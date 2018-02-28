/* 
 * File:   SPIlib.h
 * Author: Dante_L_Levi
 *
 * Created on 20 февраля 2018 г., 20:57
 */

#ifndef SPILIB_H
#define	SPILIB_H


#include "Main.h"
#include <stdint.h>

typedef enum
{
    SPI_MASTER_OSC_DEL4=0b00100000,//настроить модуль MSSP как SPI Master с тактовой частотой (частота генератора / 4).
    SPI_MASTER_OSC_DEL16=0b00100001,//настроить модуль MSSP как мастер SPI с тактовой частотой (частота генератора / 16).
    SPI_MASTER_OSC_DEL64 = 0b00100010,//настроить модуль MSSP как мастер SPI с тактовой частотой (частота генератора / 64).
    SPI_MASTER_TMR2 = 0b00100011,//настроить модуль MSSP как мастер SPI с тактированием, от Timer 2.
    SPI_SLAVE_SS_EN = 0b00100100,//настройка модуля MSSP в качестве ведомого устройства SPI с ведомым выбором 
    SPI_SLAVE_SS_DIS = 0b00100101//настроить модуль MSSP в качестве ведомого устройства SPI без ввода ведомого устройства.
            
}Spi_type;


typedef enum
{
  SPI_DATA_SAMPLE_MIDDLE = 0b00000000,// входные данные отбираются в середине времени вывода данных
  SPI_DATA_SAMPLE_END = 0b10000000// входные данные отбираются в конце времени вывода данных
} Spi_Data_Sample;

typedef enum
{
  SPI_CLOCK_IDLE_HIGH = 0b00001000,//тактирование по высокому уровню
  SPI_CLOCK_IDLE_LOW = 0b00000000//тактирование по низкому уровню
} Spi_Clock_Idle;

typedef enum
{
  SPI_IDLE_2_ACTIVE = 0b00000000,//передача происходит при переходе из режима ожидания в активное состояние
  SPI_ACTIVE_2_IDLE = 0b01000000//Передача происходит во время перехода от активного состояния в состояние ожидания
} Spi_Transmit_Edge;



//================================Прототипы=================

/*
 ==========================Инициализаия SPI интерфейса================
 */

void spiInit (Spi_type sType, Spi_Data_Sample sDataSample, Spi_Clock_Idle sClockIdle, Spi_Transmit_Edge sTransmitEdge);


/*
 =============Ожидание до завершения приема данных===========
 */
static void spiReceiveWait(void);


/*
 ==================Запись данных в шину SPI===============
 */
void SPI_Write_Data(char dat) ;



/*
 ==================Проверка данных для чтения===========
 */
unsigned spiDataReady(void);



/*
 =============Чтение данных из Шины==============
 */
char spiRead(void);


#endif	/* SPILIB_H */

