#include <io.h>
#include <stdio.h>

    int dia, mes, ano, diaSemana;
    char sep1, sep2;

void main(void){
    
    // USART initialization
    // Communication Parameters: 8 Data, 1 Stop, No Parity
    // USART Receiver: On
    // USART Transmitter: On
    // USART0 Mode: Asynchronous
    // USART Baud Rate: 9600 (Double Speed Mode)
    UCSR0A=0x02;
    UCSR0B=0x18;
    UCSR0C=0x06;
    UBRR0H=0x00;
    UBRR0L=0x0C;
    
    while(1){   
        printf(" Dame la fecha en formato dd-mm-aaaa: ");
        scanf("%i%c%i%c%i", &dia, &sep1, &mes, &sep2, &ano);
        if((sep1=='-' || sep1=='/' || sep1==' ') && (sep2=='-' || sep2=='/' || sep2==' ')){
            if((dia>=1)&&(dia<=31)&&(mes>=1)&&(mes<=12)&&(ano>=1)){
                if(mes<=2){
                    mes=mes+12;
                    ano--;
                }         
                diaSemana=((dia)+(((mes+1)*26)/10)+(ano)+(ano/4)+(6*(ano/100))+(ano/400))%7; 
                printf(" El dia de la semana es: \n\r");
                switch(diaSemana){
                    case 0:
                        printf(" SABADO \n\r");
                        break;
                    case 1:
                        printf(" DOMINGO \n\r");
                        break;
                    case 2:
                        printf(" LUNES \n\r");
                        break;
                    case 3:
                        printf(" MARTES \n\r");
                        break;                
                    case 4:
                        printf(" MIERCOLES \n\r");
                        break;
                    case 5:
                        printf(" JUEVES \n\r");
                        break;     
                    case 6:
                        printf(" VIERNES \n\r");
                        break;
                }
            }     
            else
                printf(" Formato no valido \n\r");
        }
        else
            printf(" Formato no valido \n\r");
    }
}