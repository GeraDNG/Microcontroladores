    #include <io.h> 
    #include <delay.h> 
    #include "display.h"         
               
char Pacman1[8]={0x0E, 0x1D, 0x1F, 0x1E, 0x18, 0x1C, 0x1F, 0x0E}; //Boca abierta
char Pacman2[8]={0x0E, 0x1D, 0x1F, 0x1E, 0x1F, 0x1F, 0x1F, 0x0E}; //Boca cerrada
char Pacman3[8]={0x0E, 0x17, 0x1F, 0x0F, 0x03, 0x07, 0x1F, 0x0E}; //Boca abierta (Regreso)
char Pacman4[8]={0x0E, 0x17, 0x1F, 0x0F, 0x1F, 0x1F, 0x1F, 0x0E}; //Boca cerrada (Regreso)

void main()
{
    signed char i;
    ConfiguraLCD(); 
    CreaCaracter(0,Pacman1);  
    CreaCaracter(1,Pacman2);  
    CreaCaracter(2,Pacman3);  
    CreaCaracter(3,Pacman4);    
    while(1){
        MoverCursor(5,0);
        StringLCD("Micros");  
        MoverCursor(5,1);
        StringLCD2("Rules!",150);
        for(i=0; i<8; i++){
            MoverCursor(i*2, 0);
            LetraLCD(0);            //Pacman 1
            delay_ms(200);
            MoverCursor(i*2, 0);
            LetraLCD(' ');          //Borra Pacman1
            LetraLCD(1);            //Pacman 2
            delay_ms(200);
            MoverCursor(i*2+1, 0);
            LetraLCD(' ');          //Borra Pacman2
            
        }
        for(i=8; i>=0; i--){
            MoverCursor(i*2-1, 1);
            LetraLCD(2);            //Pacman 3
            delay_ms(200);
            MoverCursor(i*2-1, 1);
            LetraLCD(' ');          //Borra Pacman 3
            MoverCursor(i*2-2, 1);
            LetraLCD(3);            //Pacman 4
            delay_ms(200);
            MoverCursor(i*2-2, 1);
            LetraLCD(' ');          //Borra Pacman 4  
        }
    }
}
