#include "Main.h"




void main(void) {
    
    LCD_PORT_init();
    LCD_Init();
    LCD_String((char*)"String 1");
    LCD_SetPos(2,1);
    LCD_String((char*)"String 2");
    LCD_SetPos(4,2);
    LCD_String((char*)"String 3");
    LCD_SetPos(6,3);
    LCD_String((char*)"String 4");
    
    while(1)
    {
        
    }
}
