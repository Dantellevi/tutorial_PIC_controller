
#include <xc.h>
#include "Main.h"
#include "lcd.h"


void Port_Init(void)
{
    TRISA=0x00;
    TRISB=0x00;
    
    PORTB=0x00;
    PORTA=0x00;
}


void main(void) {
    
    Port_Init();
    LCD_init();
    lcd_clear();
    
    
    
    while(1)
    {
        lcd_printStringXY("ssss",0, 0);
    }
}
