/* 
 * File:   Main.h
 * Author: Dante_L_Levi
 *
 * Created on 20 февраля 2018 г., 20:56
 */

#ifndef MAIN_H
#define	MAIN_H

#include <xc.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#define _XTAL_FREQ 8000000

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

// CONFIG
#pragma config FOSC = XT   // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF  // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF   // Low-Voltage In-Circuit Serial Programming Enable bit
#pragma config CPD = OFF   // Data EEPROM Memory Code Protection bit 
#pragma config WRT = OFF   // Flash Program Memory Write Enable bits 
#pragma config CP = OFF    // Flash Program Memory Code Protection bit



#include "SPIlib.h"

#endif	/* MAIN_H */

