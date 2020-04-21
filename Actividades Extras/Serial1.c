#include <io.h>
#include <stdio.h>

void main(void){
    
    char dato;
    
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
        dato = getchar(); //recibe caracter
        if((dato>='0')&&(dato<='9'))
            printf(" Numero \n\r");
        else
        printf(" Otro \n\r");               
    }
}