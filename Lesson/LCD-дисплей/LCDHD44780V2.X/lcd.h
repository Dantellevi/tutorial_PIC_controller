/* 
 * File:   lcd.h
 * Author: Dante_L_Levi
 *
 * Created on 16 января 2018 г., 20:39
 */

#ifndef LCD_H
#define	LCD_H


#include "Main.h"
#include <xc.h>
#include <stdlib.h>
#include <stdio.h>

#define _XTAL_FREQ 8000000

#define DDR_RS	TRISA	// Порт на котором будет RS
#define DDR_E	TRISA	// Порт на котором будет Е
#define DDR_RW  TRISA
#define DDR_D4	TRISB	// Порт на котором будет D4
#define DDR_D5	TRISB	// Порт на котором будет D5
#define DDR_D6	TRISB	// Порт на котором будет D6
#define DDR_D7	TRISB	// Порт на котором будет D7

#define PORT_RS	PORTA	// Порт на котором будет RS
#define PORT_E	PORTA	// Порт на котором будет Е
#define PORT_D4	PORTA	// Порт на котором будет D4
#define PORT_D5	PORTA	// Порт на котором будет D5
#define PORT_D6	PORTB	// Порт на котором будет D6
#define PORT_D7	PORTB	// Порт на котором будет D7

#define RS		0		// Номер пина RS
#define RW		1		// Номер пина RS
#define E		2		// Номер пина Е
#define D4		4		// Номер пина D4
#define D5		5		// Номер пина D5
#define D6		6		// Номер пина D6
#define D7		7		// Номер пина D7



#define E_SET()		(PORT_E|=(1 << E))		// Е в единицу
#define E_RESET()	(PORT_E&=~(1 << E))		// Е в ноль
#define RS_COM()	(PORT_RS&=~(1 << RS))		// Запись команды
#define RS_DATA()	(PORT_RS|=(1 << RS))		// Запись данных


void lcd_out(char data);
void lcd_com(char com);
void LCD_init(void);
void lcd_print_char(char data);
void lcd_print_string(char *str);
void lcd_gotoxy(char x, char y);
void lcd_printStringXY(char *str,char x,char y);
void lcd_clear(void);


#endif	/* LCD_H */

