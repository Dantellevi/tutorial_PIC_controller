/* 
 * File:   ds1307.h
 * Author: Dante_L_Levi
 *
 * Created on 14 февраля 2018 г., 20:49
 */

#ifndef DS1307_H
#define	DS1307_H

#include "Main.h"


/***************************************************************************************************
                                 Struct/Enums used
***************************************************************************************************/
typedef struct
{
  char sec;
  char min;
  char hour;
  char weekDay;
  char date;
  char month;
  char year;  
}rtc_t;
/**************************************************************************************************/


/***************************************************************************************************
                             Commonly used Ds1307 macros/Constants
***************************************************************************************************
  Below values are fixed and should not be changed. Refer Ds1307 DataSheet for more info*/

#define C_Ds1307ReadMode_U8   0xD1u  // DS1307 ID
#define C_Ds1307WriteMode_U8  0xD0u  // DS1307 ID

#define C_Ds1307SecondRegAddress_U8   0x00u   // Address to access Ds1307 SEC register
#define C_Ds1307DateRegAddress_U8     0x04u   // Address to access Ds1307 DATE register
#define C_Ds1307ControlRegAddress_U8  0x07u   // Address to access Ds1307 CONTROL register
/**************************************************************************************************/




void RTC_GetDateTime(rtc_t *rtc);
void RTC_SetDateTime(rtc_t *rtc);
void RTC_Init(void);







#endif	/* DS1307_H */

