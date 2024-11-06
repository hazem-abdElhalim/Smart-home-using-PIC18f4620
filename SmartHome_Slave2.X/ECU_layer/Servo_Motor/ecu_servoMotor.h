/* 
 * File:   ecu_servoMotor.h
 * Author: Hazem Abd El-Halim
 * Link: https://www.linkedin.com/in/hazem-abd-el-halim-335a40220/
 * Created on 04 October 2024, 16:06
 */

#ifndef ECU_SERVOMOTOR_H
#define	ECU_SERVOMOTOR_H

/* ----------------- Includes -----------------*/
#include "../../MCAL_layer/CCP/hal_ccp.h"
#include "../../MCAL_layer/Timer1/hal_timer1.h"
#include "./../../MCAL_layer/GPIO/hal_gpio.h"

/* ----------------- Macro Declarations -----------------*/

/* ----------------- Macro Functions Declarations -----------------*/

/* ----------------- Data Type Declarations -----------------*/

typedef struct {
    CCPx_Instance_T servoPin ;
}Servo_Config_t;

/* ----------------- Software Interfaces Declarations -----------------*/
#if (CCP1_CFG_MODE_SELECTED == CCP_CFG_COMPARE_MODE_SELECTED) || (CCP2_CFG_MODE_SELECTED == CCP_CFG_COMPARE_MODE_SELECTED)
STD_ReturnType Servo_Init (const Servo_Config_t *_Servo);
#endif
#if (CCP1_CFG_MODE_SELECTED == CCP_CFG_COMPARE_MODE_SELECTED) || (CCP2_CFG_MODE_SELECTED == CCP_CFG_COMPARE_MODE_SELECTED)
STD_ReturnType Servo_Set_Angle (const Servo_Config_t *_Servo, uint8 _Servo_Angle);
#endif


#endif	/* ECU_SERVOMOTOR_H */

