/* 
 * File:   LCDlib.h
 * Author: Dante_L_Levi
 *
 * Created on 18 ?????? 2018 ?., 19:41
 */

#ifndef LCDLIB_H
#define	LCDLIB_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "Main.h"
#include <xc.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>    
    
    
    
    
#define DDR_COMAND TRISB
#define DDR_DATA   TRISC

#define PORT_COMAND PORTB
#define PORT_DATA   PORTC

#define RS  PORTBbits.RB0 
#define RW  PORTBbits.RB1
#define E   PORTBbits.RB2 

    
#define D4  PORTCbits.RC4
#define D5  PORTCbits.RC5
#define D6  PORTCbits.RC6
#define D7  PORTCbits.RC7
    

#define E_SET()     (E=1)
#define E_RESET()   (E=0)
#define RS_COM()    (RS=0)
#define RS_DATA()   (RS=1)
    
 
    
    
 
void lcd_out(char data);
void lcd_com(char com);
void lcd_init(char lcd);
void lcd_char_out(char data);
void lcd_printString(char *str);
void lcd_gotoxy(char x, char y);
void lcd_printStringXY(char *str,char x,char y);
void lcd_clear(void);
void lcd_simbol(char simbol, char *str);

#ifdef	__cplusplus
}
#endif

#endif	/* LCDLIB_H */

