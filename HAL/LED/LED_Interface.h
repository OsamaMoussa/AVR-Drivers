/*
 * LED.h
 *
 *  Created on: Nov 5, 2022
 *      Author: osama yassin
 */

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

/*** LED IDs ***/
#define LED_BLU_ID ((u8)0x00)
#define LED_GRN_ID ((u8)0x01)
#define LED_RED_ID ((u8)0x02)
#define LED_YEL_ID ((u8)0x03)

/*** Functions Prototypes ***/
void LED_voidInit();
void LED_voidTurnOnLed(u8 Copy_u8LedID);
void LED_voidTurnOffLed(u8 Copy_u8LedID);
void LED_voidToggleLed(u8 Copy_u8LedID);

#endif /* LED_INTERFACE_H_ */
