//Librería para controlar la matriz de leds
 #include <delay.h>
 #define DIN_1  PORTC.0 
 #define DIN_2  PORTC.1
 #define DIN_3  PORTC.2
 #define DIN_4  PORTC.3
 #define LOAD PORTC.4
 #define CLK  PORTC.5
      
 
void MandaMax7219_1(unsigned int dato){
    unsigned char i;
    CLK=0;    
    LOAD=0;
    //ciclo para mandar bit por bit (serial)
    for(i=0;i<16;i++)
    {
        if((dato&0x8000)==0)
            DIN_1=0;
        else
            DIN_1=1;
        CLK=1;
        CLK=0;
        dato=dato<<1; //esto es lo mismo a dividirlo entre 2, para recorrer datos    
    }
    LOAD=1;
    LOAD=0;
}
void MandaMax7219_2(unsigned int dato){
    unsigned char i;
    CLK=0;    
    LOAD=0;
    //ciclo para mandar bit por bit (serial)
    for(i=0;i<16;i++)
    {
        if((dato&0x8000)==0)
            DIN_2=0;
        else
            DIN_2=1;
        CLK=1;
        CLK=0;
        dato=dato<<1; //esto es lo mismo a dividirlo entre 2, para recorrer datos    
    }
    LOAD=1;
    LOAD=0;
}
void MandaMax7219_3(unsigned int dato){
    unsigned char i;
    CLK=0;    
    LOAD=0;
    //ciclo para mandar bit por bit (serial)
    for(i=0;i<16;i++)
    {
        if((dato&0x8000)==0)
            DIN_3=0;
        else
            DIN_3=1;
        CLK=1;
        CLK=0;
        dato=dato<<1; //esto es lo mismo a dividirlo entre 2, para recorrer datos    
    }
    LOAD=1;
    LOAD=0;
}
void MandaMax7219_4(unsigned int dato){
    unsigned char i;
    CLK=0;    
    LOAD=0;
    //ciclo para mandar bit por bit (serial)
    for(i=0;i<16;i++)
    {
        if((dato&0x8000)==0)
            DIN_4=0;
        else
            DIN_4=1;
        CLK=1;
        CLK=0;
        dato=dato<<1; //esto es lo mismo a dividirlo entre 2, para recorrer datos    
    }
    LOAD=1;
    LOAD=0;
}
//Procedimeinto que se tiene que llamar de inicio para poder controlar la matriz de leds
void ConfiguraMax_1(void){
    DDRC|=0x31;
    MandaMax7219_1(0x0900);
    MandaMax7219_1(0x0A0B);
    MandaMax7219_1(0x0B07);
    MandaMax7219_1(0x0C01);
    MandaMax7219_1(0x0F00);
}
//Procedimeinto que se tiene que llamar de inicio para poder controlar la matriz de leds
void ConfiguraMax_2(void){
    DDRC|=0x32;
    MandaMax7219_2(0x0900);
    MandaMax7219_2(0x0A0B);
    MandaMax7219_2(0x0B07);
    MandaMax7219_2(0x0C01);
    MandaMax7219_2(0x0F00);
}
//Procedimeinto que se tiene que llamar de inicio para poder controlar la matriz de leds
void ConfiguraMax_3(void){
    DDRC|=0x34;
    MandaMax7219_3(0x0900);
    MandaMax7219_3(0x0A0B);
    MandaMax7219_3(0x0B07);
    MandaMax7219_3(0x0C01);
    MandaMax7219_3(0x0F00);
}
//Procedimeinto que se tiene que llamar de inicio para poder controlar la matriz de leds
void ConfiguraMax_4(void){
    DDRC|=0x38;
    MandaMax7219_4(0x0900);
    MandaMax7219_4(0x0A0B);
    MandaMax7219_4(0x0B07);
    MandaMax7219_4(0x0C01);
    MandaMax7219_4(0x0F00);
}
//Numeros para las unidades de minuto
void MinUCrea_0(){
    MandaMax7219_1(0x0100); 
    MandaMax7219_1(0x0200);
    MandaMax7219_1(0x033C); 
    MandaMax7219_1(0x0442);
    MandaMax7219_1(0x0542);
    MandaMax7219_1(0x063C);
    MandaMax7219_1(0x0700); 
    MandaMax7219_1(0x0800);
}
void MinUCrea_1(){
    MandaMax7219_1(0x0100); 
    MandaMax7219_1(0x0200);
    MandaMax7219_1(0x0302); 
    MandaMax7219_1(0x047E);
    MandaMax7219_1(0x0522);
    MandaMax7219_1(0x0600);
    MandaMax7219_1(0x0700); 
    MandaMax7219_1(0x0800);
}
void MinUCrea_2(){
    MandaMax7219_1(0x0100); 
    MandaMax7219_1(0x0200);
    MandaMax7219_1(0x0332); 
    MandaMax7219_1(0x044A);
    MandaMax7219_1(0x0546);
    MandaMax7219_1(0x0622);
    MandaMax7219_1(0x0700); 
    MandaMax7219_1(0x0800);
   }
void MinUCrea_3(){
    MandaMax7219_1(0x0100); 
    MandaMax7219_1(0x0200);
    MandaMax7219_1(0x036C); 
    MandaMax7219_1(0x0452);
    MandaMax7219_1(0x0542);
    MandaMax7219_1(0x0644);
    MandaMax7219_1(0x0700); 
    MandaMax7219_1(0x0800);
    }
void MinUCrea_4(){
    MandaMax7219_1(0x0100); 
    MandaMax7219_1(0x0200);
    MandaMax7219_1(0x037E); 
    MandaMax7219_1(0x0410);
    MandaMax7219_1(0x0510);
    MandaMax7219_1(0x0670);
    MandaMax7219_1(0x0700); 
    MandaMax7219_1(0x0800);
}
void MinUCrea_5(){
    MandaMax7219_1(0x0100); 
    MandaMax7219_1(0x0200);
    MandaMax7219_1(0x034C); 
    MandaMax7219_1(0x0452);
    MandaMax7219_1(0x0552);
    MandaMax7219_1(0x0672);
    MandaMax7219_1(0x0700); 
    MandaMax7219_1(0x0800);
}
void MinUCrea_6(){
    MandaMax7219_1(0x0100); 
    MandaMax7219_1(0x0200);
    MandaMax7219_1(0x034C); 
    MandaMax7219_1(0x0452);
    MandaMax7219_1(0x0552);
    MandaMax7219_1(0x063C);
    MandaMax7219_1(0x0700); 
    MandaMax7219_1(0x0800);
}
void MinUCrea_7(){
    MandaMax7219_1(0x0100); 
    MandaMax7219_1(0x0200);
    MandaMax7219_1(0x0370); 
    MandaMax7219_1(0x044E);
    MandaMax7219_1(0x0540);
    MandaMax7219_1(0x0640);
    MandaMax7219_1(0x0700); 
    MandaMax7219_1(0x0800);
}
void MinUCrea_8(){
    MandaMax7219_1(0x0100); 
    MandaMax7219_1(0x0200);
    MandaMax7219_1(0x032C); 
    MandaMax7219_1(0x0452);
    MandaMax7219_1(0x0552);
    MandaMax7219_1(0x062C);
    MandaMax7219_1(0x0700); 
    MandaMax7219_1(0x0800);
}
void MinUCrea_9(){
    MandaMax7219_1(0x0100); 
    MandaMax7219_1(0x0200);
    MandaMax7219_1(0x033C); 
    MandaMax7219_1(0x044A);
    MandaMax7219_1(0x054A);
    MandaMax7219_1(0x0632);
    MandaMax7219_1(0x0700); 
    MandaMax7219_1(0x0800);
}
//Numeros para las decenas de minuto
void MinDCrea_0(){
    MandaMax7219_2(0x0100); 
    MandaMax7219_2(0x0200);
    MandaMax7219_2(0x033C); 
    MandaMax7219_2(0x0442);
    MandaMax7219_2(0x0542);
    MandaMax7219_2(0x063C);
    MandaMax7219_2(0x0700); 
    MandaMax7219_2(0x0800);
}
void MinDCrea_1(){
    MandaMax7219_2(0x0100); 
    MandaMax7219_2(0x0200);
    MandaMax7219_2(0x0302); 
    MandaMax7219_2(0x047E);
    MandaMax7219_2(0x0522);
    MandaMax7219_2(0x0600);
    MandaMax7219_2(0x0700); 
    MandaMax7219_2(0x0800);
}
void MinDCrea_2(){
    MandaMax7219_2(0x0100); 
    MandaMax7219_2(0x0200);
    MandaMax7219_2(0x0332); 
    MandaMax7219_2(0x044A);
    MandaMax7219_2(0x0546);
    MandaMax7219_2(0x0622);
    MandaMax7219_2(0x0700); 
    MandaMax7219_2(0x0800);
   }
void MinDCrea_3(){
    MandaMax7219_2(0x0100); 
    MandaMax7219_2(0x0200);
    MandaMax7219_2(0x036C); 
    MandaMax7219_2(0x0452);
    MandaMax7219_2(0x0542);
    MandaMax7219_2(0x0644);
    MandaMax7219_2(0x0700); 
    MandaMax7219_2(0x0800);
    }
void MinDCrea_4(){
    MandaMax7219_2(0x0100); 
    MandaMax7219_2(0x0200);
    MandaMax7219_2(0x037E); 
    MandaMax7219_2(0x0410);
    MandaMax7219_2(0x0510);
    MandaMax7219_2(0x0670);
    MandaMax7219_2(0x0700); 
    MandaMax7219_2(0x0800);
}
void MinDCrea_5(){
    MandaMax7219_2(0x0100); 
    MandaMax7219_2(0x0200);
    MandaMax7219_2(0x034C); 
    MandaMax7219_2(0x0452);
    MandaMax7219_2(0x0552);
    MandaMax7219_2(0x0672);
    MandaMax7219_2(0x0700); 
    MandaMax7219_2(0x0800);
}

//Numeros para las unidades de hora
void HorUCrea_0(){
    MandaMax7219_3(0x0100); 
    MandaMax7219_3(0x0200);
    MandaMax7219_3(0x033C); 
    MandaMax7219_3(0x0442);
    MandaMax7219_3(0x0542);
    MandaMax7219_3(0x063C);
    MandaMax7219_3(0x0700); 
    MandaMax7219_3(0x0800);
}                
void HorUCrea_1(){
    MandaMax7219_3(0x0100); 
    MandaMax7219_3(0x0200);
    MandaMax7219_3(0x0302); 
    MandaMax7219_3(0x047E);
    MandaMax7219_3(0x0522);
    MandaMax7219_3(0x0600);
    MandaMax7219_3(0x0700); 
    MandaMax7219_3(0x0800);
}
void HorUCrea_2(){
    MandaMax7219_3(0x0100); 
    MandaMax7219_3(0x0200);
    MandaMax7219_3(0x0332); 
    MandaMax7219_3(0x044A);
    MandaMax7219_3(0x0546);
    MandaMax7219_3(0x0622);
    MandaMax7219_3(0x0700); 
    MandaMax7219_3(0x0800);
   }
void HorUCrea_3(){
    MandaMax7219_3(0x0100); 
    MandaMax7219_3(0x0200);
    MandaMax7219_3(0x036C); 
    MandaMax7219_3(0x0452);
    MandaMax7219_3(0x0542);
    MandaMax7219_3(0x0644);
    MandaMax7219_3(0x0700); 
    MandaMax7219_3(0x0800);
    }
void HorUCrea_4(){
    MandaMax7219_3(0x0100); 
    MandaMax7219_3(0x0200);
    MandaMax7219_3(0x037E); 
    MandaMax7219_3(0x0410);
    MandaMax7219_3(0x0510);
    MandaMax7219_3(0x0670);
    MandaMax7219_3(0x0700); 
    MandaMax7219_3(0x0800);
}
void HorUCrea_5(){
    MandaMax7219_3(0x0100); 
    MandaMax7219_3(0x0200);
    MandaMax7219_3(0x034C); 
    MandaMax7219_3(0x0452);
    MandaMax7219_3(0x0552);
    MandaMax7219_3(0x0672);
    MandaMax7219_3(0x0700); 
    MandaMax7219_3(0x0800);
}
void HorUCrea_6(){
    MandaMax7219_3(0x0100); 
    MandaMax7219_3(0x0200);
    MandaMax7219_3(0x034C); 
    MandaMax7219_3(0x0452);
    MandaMax7219_3(0x0552);
    MandaMax7219_3(0x063C); 
    MandaMax7219_3(0x0700); 
    MandaMax7219_3(0x0800);
}
void HorUCrea_7(){
    MandaMax7219_3(0x0100); 
    MandaMax7219_3(0x0200);
    MandaMax7219_3(0x0370); 
    MandaMax7219_3(0x044E);
    MandaMax7219_3(0x0540);
    MandaMax7219_3(0x0640);
    MandaMax7219_3(0x0700); 
    MandaMax7219_3(0x0800);
}
void HorUCrea_8(){
    MandaMax7219_3(0x0100); 
    MandaMax7219_3(0x0200);
    MandaMax7219_3(0x032C); 
    MandaMax7219_3(0x0452);
    MandaMax7219_3(0x0552);
    MandaMax7219_3(0x062C);
    MandaMax7219_3(0x0700); 
    MandaMax7219_3(0x0800);
}
void HorUCrea_9(){
    MandaMax7219_3(0x0100); 
    MandaMax7219_3(0x0200);
    MandaMax7219_3(0x033C); 
    MandaMax7219_3(0x044A);
    MandaMax7219_3(0x054A);
    MandaMax7219_3(0x0632);
    MandaMax7219_3(0x0700); 
    MandaMax7219_3(0x0800);
}
//Numeros para las decenas de hora
void HorDCrea_0(){
    MandaMax7219_4(0x0100); 
    MandaMax7219_4(0x0200);
    MandaMax7219_4(0x033C); 
    MandaMax7219_4(0x0442);
    MandaMax7219_4(0x0542);
    MandaMax7219_4(0x063C); 
    MandaMax7219_4(0x0700); 
    MandaMax7219_4(0x0800);
}
void HorDCrea_1(){
    MandaMax7219_4(0x0100); 
    MandaMax7219_4(0x0200);
    MandaMax7219_4(0x0302); 
    MandaMax7219_4(0x047E);
    MandaMax7219_4(0x0522);
    MandaMax7219_4(0x0600);
    MandaMax7219_4(0x0700); 
    MandaMax7219_4(0x0800);
}
void HorDCrea_2(){
    MandaMax7219_4(0x0100); 
    MandaMax7219_4(0x0200);
    MandaMax7219_4(0x0332); 
    MandaMax7219_4(0x044A);
    MandaMax7219_4(0x0546);
    MandaMax7219_4(0x0622);
    MandaMax7219_4(0x0700); 
    MandaMax7219_4(0x0800);
   }
