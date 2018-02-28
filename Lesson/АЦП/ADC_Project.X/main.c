#include "Main.h"



void main(void) {
   
    
    
    char buffer[20];
    char bufferVoltage[80];
    lcd_init(0);
    ADC_Init(5.0);
    lcd_printStringXY("Hello world",0,0);
    __delay_ms(500);
    lcd_clear();
    
    while(1)
    {
         int data=ADC_Read(ADCCHannel_0);
         float volt=Get_Voltage(ADCCHannel_0);
        sprintf(buffer,"data= %d%d%d%d",data/1000,(data/100)%10,(data/10)%10,data%10);
        sprintf(bufferVoltage,"voltage= %.2f",volt);
        
        lcd_printStringXY(buffer,0,0);
        lcd_printStringXY(bufferVoltage,0,1);
        __delay_ms(500);
        
    }
}
