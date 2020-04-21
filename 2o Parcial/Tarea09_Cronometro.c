#include <io.h>
#include <stdio.h>
#include <delay.h>
#include "display.h"

unsigned char min=0, seg=0, decimas=0;
char Cadena[9];
char Animacion2[8]={0x1B, 0x1B, 0x1B, 0x00, 0x11, 0x1F, 0x0E, 0x00};
char Animacion1[8]={0x00, 0x0E, 0x1F, 0x11, 0x00, 0x1B, 0x1B, 0x1B};

void main(){
    PORTD.0=1; //Pull-up en PD0             Se podria poner tambien:
    PORTD.1=1; //Pull-up en PD1                                     PORTD=0x03
    ConfiguraLCD();
    CreaCaracter(0,Animacion1);  
    CreaCaracter(1,Animacion2);  
    while(1){
        sprintf(Cadena, "%02i:%02i.%i", min, seg, decimas); //%lu por long unsigned   
        MoverCursor(5, 0);
        StringLCDVar(Cadena);
        delay_ms(54);
        if(PIND.0==1){
            decimas++;
        }
        if(decimas<=4){
            MoverCursor(8, 1);
            LetraLCD(1);
        }            
        if(decimas>=5){
            MoverCursor(8, 1);
            LetraLCD(0);
        }
        if(decimas==10){
            decimas=0;
            seg++;
            if(seg==60){
                seg=0;
                min++;
                if(min==60){
                    min=0;
                }
            }
        }  
        if(PIND.1==0){
            decimas = 0;
            seg = 0;
            min = 0;
        }
    }
}