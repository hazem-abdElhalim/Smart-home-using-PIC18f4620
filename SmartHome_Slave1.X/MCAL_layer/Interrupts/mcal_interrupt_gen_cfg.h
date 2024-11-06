/* 
 * File:   mcal_interrupt_gen_cfg.h
 * Author: Hazem Abd El-Halim
 * Link: https://www.linkedin.com/in/hazem-abd-el-halim-335a40220/
 * Created on 11 September 2024, 20:55
 */

#ifndef MCAL_INTERRUPT_GEN_CFG_H
#define	MCAL_INTERRUPT_GEN_CFG_H


/* ----------------- Includes -----------------*/


/* ----------------- Macro Declarations -----------------*/
#define INTERRUPT_FEATURE_ENABLE 1U

//#define INTERRUPT_PRIORITY_LEVELS_ENABLE           INTERRUPT_FEATURE_ENABLE

#define EXTERNAL_INTERRUPT_INTX_FEATURE_ENABLE     INTERRUPT_FEATURE_ENABLE
#define EXTERNAL_INTERRUPT_OnChange_FEATURE_ENABLE INTERRUPT_FEATURE_ENABLE

#define INTERRUPT_ADC_FEATURE_ENABLE               INTERRUPT_FEATURE_ENABLE

#define INTERRUPT_TIMER0_FEATURE_ENABLE            INTERRUPT_FEATURE_ENABLE
#define INTERRUPT_TIMER1_FEATURE_ENABLE            INTERRUPT_FEATURE_ENABLE
#define INTERRUPT_TIMER2_FEATURE_ENABLE            INTERRUPT_FEATURE_ENABLE
#define INTERRUPT_TIMER3_FEATURE_ENABLE            INTERRUPT_FEATURE_ENABLE

#define INTERRUPT_USART_TX_FEATURE_ENABLE          INTERRUPT_FEATURE_ENABLE
#define INTERRUPT_USART_RX_FEATURE_ENABLE          INTERRUPT_FEATURE_ENABLE

#define INTERRUPT_MCCP_I2C_FEATURE_ENABLE          INTERRUPT_FEATURE_ENABLE
#define INTERRUPT_MCCP_SPI_FEATURE_ENABLE          INTERRUPT_FEATURE_ENABLE

#define INTERRUPT_CCP1_FEATURE_ENABLE              INTERRUPT_FEATURE_ENABLE
#define INTERRUPT_CCP2_FEATURE_ENABLE              INTERRUPT_FEATURE_ENABLE

/* ----------------- Macro Functions Declarations -----------------*/

/* ----------------- Data Type Declarations -----------------*/

/* ----------------- Software Interfaces Declarations -----------------*/

#endif	/* MCAL_INTERRUPT_GEN_CFG_H */

