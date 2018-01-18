#include "LCD.h"
#include <xc.h>

#define LCDLine1()          LCDPutCmd(LCD_HOME)          // legacy support
#define LCDLine2()          LCDPutCmd(LCD_CURSOR_LINE2)  // legacy support
#define shift_cursor()      LCDPutCmd(LCD_CURSOR_FWD)    // legacy support
#define cursor_on()         LCDPutCmd(LCD_CURSOR_ON)     // legacy support
#define DisplayClr()        LCDPutCmd(LCD_CLEAR)         // Legacy support



void LCDWriteNibble(uint8_t ch,uint8_t rs)
{
    // always send the upper nibble
    ch = (ch >> 4);

    // mask off the nibble to be transmitted
    ch = (ch & 0x0F);

    // clear the lower half of LCD_PORT
    LCD_PORT = (LCD_PORT & 0xF);

    // move the nibble onto LCD_PORT
    LCD_PORT = (LCD_PORT | ch);

    // set data/instr bit to 0 = insructions; 1 = data
    LCD_RS = rs;

    // RW - set write mode
    LCD_RW = 0;

    // set up enable before writing nibble
    LCD_EN = 1;

    // turn off enable after write of nibble
    LCD_EN = 0;
}


void LCDPutCmd(uint8_t ch)
{
    __delay_ms(LCD_delay);

    //Send the higher nibble
    LCDWriteNibble(ch,instr);

    //get the lower nibble
    ch = (ch << 4);

    __delay_ms(1);

    //Now send the lower nibble
    LCDWriteNibble(ch,instr);
}

void LCD_Init(void)
{
    DDR_COM_LCD=0x00;
    DDR_DATA_LCD=0x00;
    LCD_PORT=0x00;
    LCD_COMAND_PORT=0x00;
    // required by display controller to allow power to stabilize
    __delay_ms(LCD_Startup);
    
    // required by display initialization
    LCDPutCmd(0x32);

    // set interface size, # of lines and font
    LCDPutCmd(FUNCTION_SET);

    // turn on display and sets up cursor
    LCDPutCmd(DISPLAY_SETUP);
    
    //DisplayClr();
    LCDPutCmd(LCD_CLEAR);
    // set cursor movement direction
    LCDPutCmd(ENTRY_MODE);
    
}


void LCDPutChar(uint8_t ch)
{
    __delay_ms(LCD_delay);

    //Send higher nibble first
    LCDWriteNibble(ch,data);

    //get the lower nibble
    ch = (ch << 4);

    // Now send the low nibble
    LCDWriteNibble(ch,data);
}











