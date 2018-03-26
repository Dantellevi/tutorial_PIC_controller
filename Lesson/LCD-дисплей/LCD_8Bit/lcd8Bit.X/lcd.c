#include "lcd.h"
//--------------------------------------------------------------
#define rs RC4
#define rw RC5
#define e RC6
//--------------------------------------------------------------
void LCD_delay()
{
  int i;
  for(i=0;i<19;i++);
}
//--------------------------------------------------------------
void LCD_PORT_init()
{
  TRISC=0X00;
  TRISD=0X00;
}
//--------------------------------------------------------------
void sendbyte(unsigned char c, unsigned char mode)
{
  PORTD=c;
  if(mode==0) rs=0;
  else rs=1;
  rw=0;
  e=0;
  LCD_delay();
  e=1;
}
//--------------------------------------------------------------
void LCD_Init()
{
  sendbyte(0X01,0);//Clear Display
  sendbyte(0X38,0);//Function set: 8-bit bus mode,
  //2-line display mode is set (2004 - 4-line), 5x8 dots format
  sendbyte(0X0c,0);//Display ON, Cursor OFF, blink OFF
  sendbyte(0X06,0);//direction left to right
  sendbyte(0X80,0);//SET POS LINE 0
}
//--------------------------------------------------------------
void LCD_SetPos(unsigned char x, unsigned char y)
{
  switch(y)
  {
    case 0:
      sendbyte((unsigned char)(x|0x80),0);
      break;
    case 1:
      sendbyte((unsigned char)((0x40+x)|0x80),0);
      break;
    case 2:
      sendbyte((unsigned char)((0x14+x)|0x80),0);
      break;
    case 3:
      sendbyte((unsigned char)((0x54+x)|0x80),0);
      break;
  }
}
//--------------------------------------------------------------
void LCD_String(char* st)
{
  unsigned char i=0;
  while(st[i]!=0)
  {
    sendbyte(st[i],1);
    i++;
  }
}
//--------------------------------------------------------------
