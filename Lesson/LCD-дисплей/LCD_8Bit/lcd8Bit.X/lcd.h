/* 
 * File:   lcd.h
 * Author: Dante_L_Levi
 *
 * Created on 22 марта 2018 г., 14:51
 */

#ifndef LCD_H
#define	LCD_H

#include "Main.h"
#include <xc.h>


void LCD_PORT_init(void);
void sendbyte(unsigned char c, unsigned char mode);
void LCD_Init(void);
void LCD_String(char* st);
void LCD_SetPos(unsigned char x, unsigned char y);


#endif	/* LCD_H */

