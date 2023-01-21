/*
 * BTN_Config.h
 *
 *  Created on: Nov 8, 2022
 *      Author: osama yassin
 */

#ifndef BTN_CONFIG_H_
#define BTN_CONFIG_H_

/*** Define Button Denounce Delay ***/
#define DEBOUNCE_DELAY 40

/*** PD2-->INT0 ***/
#define BTN_INT0_REG PORTD_ID
#define BTN_INT0_PIN PIN2

/*** PD3-->INT1 ***/
#define BTN_INT1_REG PORTD_ID
#define BTN_INT1_PIN PIN3

/*** PB2-->INT2 ***/
#define BTN_INT2_REG PORTB_ID
#define BTN_INT2_PIN PIN2

#endif /* BTN_CONFIG_H_ */
