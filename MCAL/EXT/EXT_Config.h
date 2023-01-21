/*
 * EXT_Config.h
 *
 *  Created on: Nov 7, 2022
 *      Author: osama yassin
 */

#ifndef EXT_CONFIG_H_
#define EXT_CONFIG_H_

/*** Define Button Denounce Delay ***/
#define DEBOUNCE_DELAY 40

/*** PD2-->INT0 ***/
#define EXT_INT0_REG (PORTD_ID)
#define EXT_INT0_PIN (0x02)

/*** PD3-->INT1 ***/
#define EXT_INT1_REG (PORTD_ID)
#define EXT_INT1_PIN (0x03)

/*** PB2-->INT2 ***/
#define EXT_INT2_REG (PORTB_ID)
#define EXT_INT2_PIN (0x02)

#endif /* EXT_CONFIG_H_ */
