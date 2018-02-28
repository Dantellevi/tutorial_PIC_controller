#include "SPIlib.h"
#include <xc.h>



/*
 ==========================Инициализаия SPI интерфейса================
 */

void spiInit (Spi_type sType, Spi_Data_Sample sDataSample, Spi_Clock_Idle sClockIdle, Spi_Transmit_Edge sTransmitEdge)
{
    TRISC5 = 0;
  if (sType & 0b00000100) // Если ведомый режим
  {
    SSPSTAT = sTransmitEdge;    //устанавливаем регистр статуса
    TRISC3 = 1;
  }
  else // Если мастер-режим
  {
    SSPSTAT = sDataSample | sTransmitEdge;  //настраиваем выборку данных и устанавливаем режим перехода в передачу данных
    TRISC3 = 0;
  }
  SSPCON = sType | sClockIdle; //устанавливаем делитель и тактирование по низкому или высокому уровню
}

/*
 =============Ожидание до завершения приема данных===========
 */
static void spiReceiveWait(void)
{
  while (! SSPSTATbits.BF); // Дождитесь завершения приема данных
}

/*
 ==================Запись данных в шину SPI===============
 */
void SPI_Write_Data(char dat) 
{
  SSPBUF = dat;
}


/*
 ==================Проверка данных для чтения===========
 */
unsigned spiDataReady(void) // Проверьте, готовы ли данные для чтения
{
  if(SSPSTATbits.BF)
    return 1;
  else
    return 0;
}


/*
 =============Чтение данных из Шины==============
 */
char spiRead(void) // Чтение полученных данных
{
  spiReceiveWait(); // Подождите, пока все биты не получат
  return (SSPBUF); // Чтение полученных данных из буфера
}











