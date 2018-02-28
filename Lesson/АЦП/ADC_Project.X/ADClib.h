/* 
 * File:   ADClib.h
 * Author: Dante_L_Levi
 *
 * Created on 24 февраля 2018 г., 19:49
 */

#ifndef ADCLIB_H
#define	ADCLIB_H



#include "Main.h"

#define ADCCHannel_0 0
#define ADCCHannel_1 1
#define ADCCHannel_2 2
#define ADCCHannel_3 3
#define ADCCHannel_4 4
#define ADCCHannel_5 5
#define ADCCHannel_6 6
#define ADCCHannel_7 7

/*
 ======================Функция инициализации АЦП-----------------
 */
void ADC_Init(float Uref);






/*
    ---------------------------------Функция чтения данных из регистра АЦП---------------------
 *                      Принимаемые параметры:
 *                          channel-канал по которому будет считыватся значения
 *                      Возращаемое значение:
 *                          данные из регистра АЦП
 */
unsigned int ADC_Read(unsigned char channel);






/*
 =============================Преобразование в напряжение---------------------
 *      Принимаемые параметры:
 *              channel-канал по которому будет считыватся значения
 *      Возращаемые параметры:
 *              значение напряжения в вещественном виде
 */
float Get_Voltage(unsigned char channel);




#endif	/* ADCLIB_H */

