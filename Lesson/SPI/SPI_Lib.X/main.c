/*
 * File:   main.c
 * Author: Dante_L_Levi
 *
 * Created on 20 февраля 2018 г., 20:56
 */


#include "Main.h"


void main(void) 
{
    /*
     устанавливаем делитель частоты на 4,
     *   SPI_DATA_SAMPLE_MIDDLE-входные данные отбираются в середине времени вывода данных
     * SPI_CLOCK_IDLE_LOW-тактирование по низкому фронту
     * SPI_IDLE_2_ACTIVE-Передача происходит во время перехода от активного состояния в состояние ожидания
     * 
     */
    spiInit(SPI_MASTER_OSC_DEL4, SPI_DATA_SAMPLE_MIDDLE, SPI_CLOCK_IDLE_LOW, SPI_IDLE_2_ACTIVE);
    TRISC7 = 0;
    RC7=0;
    while(1)
    {
        for(char i=0;i<254;i++)
        {
            RC7=0;  //выбор ведомого
            __delay_ms(1);
            SPI_Write_Data(i);
             __delay_ms(1);
             RC7=1;  //выбор ведомого
             
             __delay_ms(500);
        }
    }

}
