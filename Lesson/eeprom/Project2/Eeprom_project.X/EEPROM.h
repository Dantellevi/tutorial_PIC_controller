#ifndef EEPROM_H
#define	EEPROM_H

#include "Main.h"



/*
 =====================Функция чтения байтаа из определенного адреса========
 */
uint8_t EEPROM_ReadByte(uint8_t addr);
/*
 ===============Функция записи байта по определенному адресу=======
 */
void EEPROM_WriteByte(uint8_t addr,uint8_t dt);

/*
 =========Функция записи целочисленного двух байтовой величины============
 */
void EEPROM_WriteWord(uint8_t addr, uint16_t ucData);
/*
 ==============================Функция чтения двух байт из адресов===============
 */
uint16_t EEPROM_ReadWord(uint8_t addr);


/*
 ===========================Функция записи 4 байта===========================
 */
void EEPROM_WriteDWord(uint16_t addr,unsigned long ucData);
/*
 ==================Функция чтения 4 байтной величины==================
 */
uint32_t EEPROM_ReadDWord(uint8_t addr);

/*
 ===========Записываем строку в EEPROM===========================
 */
void EEPROM_WriteString(uint8_t addr,char *str1);
/*
 ===========================Читаем строку из адреса===================
 */
void EEPROM_ReadString(uint8_t addr,char *str1,uint8_t sz);


#endif	/* EEPROM_H */

