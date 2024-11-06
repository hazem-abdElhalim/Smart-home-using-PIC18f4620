/* 
 * File:   RealTimeClock_DS1307.c
 * Author: Hazem Abd El-Halim
 * Link: https://www.linkedin.com/in/hazemabdelhalim
 * Created on 23 October 2024, 19:15
 */


#include "RealTimeClock_DS1307.h"

static REALTIMECLOCK_DS1307_t  REALTIMECLOCK_DS1307;
static uint8 REALTIMECLOCK_DS1307_Data[18];

static EUSART_Config_t UART_obj = {
    .BAUDRAT_CONFIG = EUSART_BAUDRAT_ASYN_8BIT_LOW_SPEED,
    .Baud_rate = 9600,
    .EUSART_TX_InterruptHandler = NULL,
    .TX_Config.Transmit_Enable = EUSART_ASYNCHRONOUS_TX_ENABLE_SELECTED,
    .TX_Config.Transmit_Interrupt_Enable = EUSART_ASYNCHRONOUS_INTERRUPT_TX_DISABLE_SELECTED,
    .TX_Config.Transmit_TX9_Enable = EUSART_ASYNCHRONOUS_TX9_DISABLE_SELECTED     
};



REALTIMECLOCK_DS1307_t  REALTIMECLOCK_DS1307_Get_Data(void){
    REALTIMECLOCK_DS1307.seconds = I2C_Read1ByteRegister(0xD0, 0x00);
    REALTIMECLOCK_DS1307.minutes = I2C_Read1ByteRegister(0xD0, 0x01);
    REALTIMECLOCK_DS1307.hours   = I2C_Read1ByteRegister(0xD0, 0x02);
    REALTIMECLOCK_DS1307.days    = I2C_Read1ByteRegister(0xD0, 0x04);
    REALTIMECLOCK_DS1307.months  = I2C_Read1ByteRegister(0xD0, 0x05);
    REALTIMECLOCK_DS1307.years   = I2C_Read1ByteRegister(0xD0, 0x06);
    
    return REALTIMECLOCK_DS1307;
}


uint8   *REALTIMECLOCK_DS1307_print_Data(void){
    STD_ReturnType ret;
    REALTIMECLOCK_DS1307_Data[0] = ((REALTIMECLOCK_DS1307.days >> 4) + 0x30);
    REALTIMECLOCK_DS1307_Data[1] = ((REALTIMECLOCK_DS1307.days & 0x0F) + 0x30);
    REALTIMECLOCK_DS1307_Data[2] = '/';
    REALTIMECLOCK_DS1307_Data[3] = ((REALTIMECLOCK_DS1307.months >> 4) + 0x30);
    REALTIMECLOCK_DS1307_Data[4] = ((REALTIMECLOCK_DS1307.months & 0x0F) + 0x30);
    REALTIMECLOCK_DS1307_Data[5] = '/';
    REALTIMECLOCK_DS1307_Data[6] = ((REALTIMECLOCK_DS1307.years >> 4) + 0x30);
    REALTIMECLOCK_DS1307_Data[7] = ((REALTIMECLOCK_DS1307.years & 0x0F) + 0x30);
    REALTIMECLOCK_DS1307_Data[8] = '-';
    REALTIMECLOCK_DS1307_Data[9] = ((REALTIMECLOCK_DS1307.hours >> 4) + 0x30);
    REALTIMECLOCK_DS1307_Data[10] = ((REALTIMECLOCK_DS1307.hours & 0x0F) + 0x30);
    REALTIMECLOCK_DS1307_Data[11] = ':';
    REALTIMECLOCK_DS1307_Data[12] = ((REALTIMECLOCK_DS1307.minutes >> 4) + 0x30);
    REALTIMECLOCK_DS1307_Data[13] = ((REALTIMECLOCK_DS1307.minutes & 0x0F) + 0x30);
    REALTIMECLOCK_DS1307_Data[14] = ':';
    REALTIMECLOCK_DS1307_Data[15] = ((REALTIMECLOCK_DS1307.seconds >> 4) + 0x30);
    REALTIMECLOCK_DS1307_Data[16] = ((REALTIMECLOCK_DS1307.seconds & 0x0F) + 0x30);
    REALTIMECLOCK_DS1307_Data[17] = '\r';
    
    EUSART_ASYNC_Init(&UART_obj);
    ret = EUSART_ASYNC_WriteStringBlocking("Date: ", 6);
    ret = EUSART_ASYNC_WriteStringBlocking(REALTIMECLOCK_DS1307_Data, 18);
    
    return REALTIMECLOCK_DS1307_Data;
}