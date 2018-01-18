
#ifndef LCD_H
#define	LCD_H

#include <xc.h>
#include<stdlib.h>
#include <stdio.h>
#include <string.h>
#define _XTAL_FREQ 4000000
//=============================управляющие регистры(данные) выход МК======================
#define DDDR TRISB
#define DPORT PORTB

//=======================================================================================

//цифрами указываем номера выводов мк подключенные к дисплею.
//	  Пин  МК  LCD
#define DB0 0  //DD0
#define DB1 1  //DD1
#define DB2 2  //DD2
#define DB3 3  //DD3
#define DB4 4  //DD4
#define DB5 5  //DD5
#define DB6 6  //DD6
#define DB7 7  //DD7
//===========================================


//Указываем порт к которому подключены выводы дисплея E, RS, R/W.

#define CDDR TRISA
#define CPORT PORTA

//--------------------------------------------------------------

//--------------Указываем порт к которому подключены выводы управления E,RS,R/W-----------------
#define E 2			// E	 СТРОБ.
#define RS 0		// R/W   R/W=1 читаем из LCD, R/W=0 записываем в LCD.
#define RW 1		// RS	 RS=0 посылаем команду в LCD, RS=1 посылаем данные в LCD.
//----------------------------------------------------------------------------------------------
//Двухстрочный дисплей.
#define LINE0 0x00
#define LINE1 0x40
// 4 строчный дисплей
#define LINE2 0x14
#define LINE3 0x54
//------------------------------------------------------------------------------

#define PIND7   RB7
#define PIND6   RB6
#define PIND5   RB5
#define PIND4   RB4
#define PIND3   RB3
#define PIND2   RB2
#define PIND1   RB1
#define PIND0   RB0



        


static void Send_byte(char i);
void LCDGotoXY(char x,char y)	;
void LCDputsIntGotoXY(int val,char x,char y);
void LCDsendString(char *s);
void LCDstringXY(char *i,char x,char y);
void LCDGotoXY(char x,char y);
void LCDdataXY (char a, char b,char c);
void LCDdata(char i);
void LCDinit(void);
void LCDclear(void);



#endif	/* LCD_H */

