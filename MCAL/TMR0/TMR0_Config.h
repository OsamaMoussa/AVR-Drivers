/*
 * TIMER0_Config.h
 *
 *  Created on: Nov 12, 2022
 *      Author: osama yassin
 */

#ifndef TMR0_CONFIG_H_
#define TMR0_CONFIG_H_

/***SYSTEM FREQUENCY in HZ***/
#define F_SYS (16000000ULL)

/***PRESCALER Options***/
/* PRESCALER_1
 * PRESCALER_8
 * PRESCALER_64
 * PRESCALER_256
 * PRESCALER_1024
 * EXT_CLK_FE
 * EXT_CLK_RE
 * */
#define PRESCALER PRESCALER_64

/***Mode Options***/
/* NORMAL_MODE
 *PWM_MODE
 *CTC_MODE
 *FPWM_MODE
 * */
#define MODE NORMAL_MODE

/***Compare Match Options***/
/*COM_OC0_DISCONNECTED
*COM_TOGGLE
*COM_CLEAR
*COM_SET
 * */
#define COM_MODE COM_CLEAR

/***OCR0 Register Value***/
#define CTC_OVERFLOWS (10000ULL)

#endif /* TMR0_CONFIG_H_ */
