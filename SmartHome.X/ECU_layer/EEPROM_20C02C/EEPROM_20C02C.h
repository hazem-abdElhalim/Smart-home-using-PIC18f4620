/* 
 * File:   EEPROM_20C02C.h
 * Author: Hazem Abd El-Halim
 * Link: https://www.linkedin.com/in/hazemabdelhalim
 * Created on October 26, 2024, 1:03 AM
 */

#ifndef EEPROM_20C02C_H
#define	EEPROM_20C02C_H

#include "./../../mcc_generated_files/mcc.h"
#include "./../../mcc_generated_files/examples/i2c_master_example.h"


void EEPROM_20C02C_Write_Byte   (i2c_address_t EEPROM_Adress, i2c_address_t Byte_Adress, uint8_t _Byte);
uint8_t EEPROM_20C02C_Read_Byte (i2c_address_t EEPROM_Adress, i2c_address_t Byte_Adress);


#endif	/* EEPROM_20C02C_H */

