/*
 * File:   main.c
 * Author: Dante_L_Levi
 *
 * Created on 18 ?????? 2018 ?., 19:38
 */


#include <xc.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "LCDlib.h"





void main(void) {
   
    
    lcd_init(0);
    lcd_gotoxy(0,0);
    lcd_printString("Hello World");
    lcd_printStringXY("LCD HD44780!!!",1,1);
    __delay_ms(1000);
    lcd_clear();
    while(1)
    {
        
    }
}
