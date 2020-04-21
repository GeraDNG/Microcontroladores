#include <io.h>

unsigned char X, Y;
unsigned int i=0, Cont1=0, Cont2=0;

void main(){
    DDRD = 0xFF;
    while(1){ 
        X = PINB;
        Y = PINC;
        for(i=0;i<8;i++)
        {   
            if((X&0x80)!=0){
                Cont1++;
            }
            X = X<<1;
        }
        for(i=0;i<8;i++)
        {
            if((Y&0x80)!=0){
                Cont2++;
            }
            Y = Y<<1;       
        }
        PORTD = (Cont2<<4)|Cont1;
        X=0;
        Y=0;
        Cont1=0;
        Cont2=0;
    }       
}