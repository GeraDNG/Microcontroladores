#include <mega328P.h>
    #include <delay.h>  
    #include "matriz.h"
    #include <io.h>
  
unsigned char seg=0;
unsigned int minU=0,minD=0,hrU=0,hrD=0;
unsigned int BMINU,BMIND,BHORU,BHORD;
unsigned int Ent;
unsigned int ALHD=1,ALHU=1,ALMD=1,ALMU=1,SAlar,Bsleep;
unsigned long int i=0;
// Timer1 output compare A interrupt service routine
interrupt [TIM1_COMPA] void timer1_compa_isr(void)
{
    PORTB=seg;
    seg++;
    if(seg>59){  
    seg=0;
    minU++;
        if(minU>9){
            minD++;
            minU=0;
            i=0;
            if(minD>5){
                hrU++;
                minD=0;
                if(hrU>9){
                    hrD++;
                    hrU=0;
                    
                }
            }    
        }

    }
    if(hrU==4 && hrD==2){
        minU=0;
        minD=0;
        hrU=0;
        hrD=0;    
    } 
    if(ALHD==hrD && ALHU==hrU && ALMD==minD && ALMU==minU){    
        PORTB.7=673;
               
        } 

}

void main(void){
    ConfiguraMax_1();
    ConfiguraMax_2();
    ConfiguraMax_3();
    ConfiguraMax_4();
    DDRB=0xBF;
    PORTD=0xFF; 
    DDRC.6=1; 
    PORTB.6=1;
    //    DDRD=0xFF;  //PD0 a PD7 de salida
    // Timer/Counter 1 initialization
    // Clock source: System Clock
    // Clock value: 15.625 kHz
    // Mode: CTC top=OCR1A
    // OC1A output: Discon.
    // OC1B output: Discon.
    // Noise Canceler: Off
    // Input Capture on Falling Edge
    // Timer1 Overflow Interrupt: Off
    // Input Capture Interrupt: Off
    // Compare A Match Interrupt: On
    // Compare B Match Interrupt: Off
    TCCR1A=0x00;
    TCCR1B=0x0B;
    
    OCR1AH=15624/256;
    OCR1AL=15624%256;
    
    // Timer/Counter 1 Interrupt(s) initialization
    TIMSK1=0x02; 
    
    // Global enable interrupts
    #asm("sei") 
    while(1)
    {     
        BHORD=PIND.0;
        BHORU=PIND.1;
        BMIND=PIND.2;
        BMINU=PIND.3;
        SAlar=PINB.6;
        Bsleep=PINB.7;
        Ent=PIND>>4;
        if(minU==0){        
            MinUCrea_0();
        } 
        if(minU==1){
            MinUCrea_1();
        }
        if(minU==2){
            MinUCrea_2();
        } 
        if(minU==3){
            MinUCrea_3();
        }
        if(minU==4){  
            MinUCrea_4();
        } 
        if(minU==5){ 
            MinUCrea_5();
        }
        if(minU==6){
            MinUCrea_6();
        }  
        if(minU==7){ 
            MinUCrea_7();
        } 
        if(minU==8){   
            MinUCrea_8(); 
        }   
        if(minU==9){ 
            MinUCrea_9();
        }
        if(minD==0){        
            MinDCrea_0();
        } 
        if(minD==1){
            MinDCrea_1();
        }
        if(minD==2){
            MinDCrea_2();
        } 
        if(minD==3){
            MinDCrea_3();
        }
        if(minD==4){  
            MinDCrea_4();
        } 
        if(minD==5){ 
            MinDCrea_5();
        }
        if(hrU==0){        
            HorUCrea_0();
        } 
        if(hrU==1){
            HorUCrea_1();
        }
        if(hrU==2){
            HorUCrea_2();
        } 
        if(hrU==3){
            HorUCrea_3();
        }
        if(hrU==4){  
            HorUCrea_4();
        } 
        if(hrU==5){ 
            HorUCrea_5();
        }
        if(hrU==6){
            HorUCrea_6();
        }  
        if(hrU==7){ 
            HorUCrea_7();
        } 
        if(hrU==8){   
            HorUCrea_8(); 
        }   
        if(hrU==9){ 
            HorUCrea_9();
        }
        if(hrD==0){        
            HorDCrea_0();
        } 
        if(hrD==1){
            HorDCrea_1();
        }
        if(hrD==2){
            HorDCrea_2();
        } 
        if(SAlar==1){
            if(BMINU==0){
            ALMU=Ent;
        }
        if(BMIND==0){
            ALMD=Ent;
        }
        if(BHORU==0){
            if(ALHD!=2){  
                ALHU=Ent;
            }
            else if(ALHD==2){
                if(Ent<4){
                    ALHU=Ent;
                }
            }
        }
        if(BHORD==0){
            if(ALHU>4){
            if(Ent==1 || Ent==0){
                ALHD=Ent;    
            }  
            else{
                 ALHD=ALHD;
                }
            }    
            else{
                 ALHD=Ent;
            }

        }
        
        }
        else{
        if(BMINU==0){
            minU=Ent;
        }
        if(BMIND==0){
            minD=Ent;
        }
        if(BHORU==0){
            if(hrD!=2){  
                hrU=Ent;
            }
            else if(hrD==2){
                if(Ent<4){
                    hrU=Ent;
                }
            }
        }
        if(BHORD==0){
            if(hrU>4){
            if(Ent==1 || Ent==0){
                hrD=Ent;    
            }  
            else{
                 hrD=hrD;
                }
            }    
            else{
                 hrD=Ent;
            }

        }
        }
                    
    }   
    
}