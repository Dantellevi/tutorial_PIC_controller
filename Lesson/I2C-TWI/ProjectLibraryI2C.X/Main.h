#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h>

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
#include "I2C.h"
#include "USART.h"
#include "ds1307.h"




#endif	/* XC_HEADER_TEMPLATE_H */

