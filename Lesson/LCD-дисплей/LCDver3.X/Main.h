/* 
 * File:   Main.h
 * Author: Dante_L_Levi
 *
 * Created on 17 января 2018 г., 19:59
 */

#ifndef MAIN_H
#define	MAIN_H

#ifdef	__cplusplus
extern "C" {
#endif

    
    
#include "LCD.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define _XTAL_FREQ 4000000
// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer (WDT disabled)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (Power-up Timer is enabled)
#pragma config CP = OFF         // Code Protection bit (Code protection disabled)


    
    
    
#ifdef	__cplusplus
}
#endif

#endif	/* MAIN_H */

