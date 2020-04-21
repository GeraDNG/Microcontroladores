    #include <io.h> 
    //Gerardo Daniel Naranjo Gallegos, A01209499

    #include <delay.h>  
    #include <stdio.h>
    #include "display.h"
    #define ADC_VREF_TYPE 0x60
           
    int DC=0, POT=0;    
    float POT1, POT2;
    char cadena[16];
    char cadena1[16];
    char cadena2[16];

unsigned char read_adc(unsigned char adc_input)
{
ADMUX=adc_input | (ADC_VREF_TYPE & 0xff);
// Delay needed for the stabilization of the ADC input voltage
delay_us(10);
// Start the AD conversion
ADCSRA|=0x40;
// Wait for the AD conversion to complete
while ((ADCSRA & 0x10)==0);
ADCSRA|=0x10;
return ADCH;
}




void main()
{         
    CLKPR=0x80;
    CLKPR=0;
    ConfiguraLCD();
    while(1)
    {             
        if(PIND.1==0 && PIND.2==0){   
            //LCD:               
            MoverCursor(0,0);
            StringLCD("Gerardo Naranjo  ");  
            MoverCursor(0,1);
            StringLCD2("A01209499       ", 0);
            //Señal CTC:   
            DDRB.1=1;
            TCCR1A=0x40;
            TCCR1B=0x09;                           
            OCR1AH=1052/256; //399>>8               
            OCR1AL=1052%256; //399&0xFF
        }          
        if(PIND.1==0 && PIND.2==1){
            //Lectura POT:    
            ACSR=0x80;
            ADCSRB=0x00;
            DIDR1=0x00;
            DIDR0=0x10;
            ADMUX=ADC_VREF_TYPE & 0xff;
            ADCSRA=0x85;
            POT = read_adc(4);    
            DC = ((POT*100)/255);
            //LCD: 
            MoverCursor(0,0);
            StringLCD("PWM              ");
            sprintf(cadena, "Duty Cycle= %.i%c       ", DC, 0x25); //Convierte a texto  
            MoverCursor(0,1);
            StringLCDVar(cadena);
            //Señal PWM:     
            DDRB.3=1;  
            ASSR=0x00;
            TCCR2A=0x03;
            TCCR2B=0x00;
            TCNT2=0x00;
            OCR2A=DC/256;
            OCR2B=0x00;                                                                                                     

        } 
        if(PIND.1==1 && PIND.2==0){    
            //ADC:
            ACSR=0x80;
            ADCSRB=0x00;
            DIDR1=0x00;
            DIDR0=0x30;
            ADMUX=ADC_VREF_TYPE & 0xff;
            ADCSRA=0x85;
            POT1 = ((read_adc(4))/50.0);
            POT2 = ((read_adc(5))/50.0);
            
            //LCD:            
            sprintf(cadena1, "Voltaje 1= %.f          ", POT1); //Convierte a texto  
            MoverCursor(0,0);
            StringLCDVar(cadena1);
            sprintf(cadena2, "Voltaje 2= %.f          ", POT2); //Convierte a texto  
            MoverCursor(0,1);
            StringLCDVar(cadena2);

            
        }
        if(PIND.1==1 && PIND.2==1){
            //LCD:   
            MoverCursor(0,0);
            StringLCD("                ");  
            MoverCursor(0,1);
            StringLCD2("                ", 0);     
        }
    }    
}
