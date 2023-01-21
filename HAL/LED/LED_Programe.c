/*
 * LED.c


 *
 *  Created on: Nov 5, 2022
 *      Author: osama yassin
 */

/***LIB***/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
/***MCAL***/
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/EXT/EXT_Interface.h"
/***LED***/
#include "LED_Interface.h"
#include "LED_Config.h"

void LED_voidInit(){
	DIO_voidSetPinDirection(LED_BLU_PORT, LED_BLU_PIN, PIN_OUTPUT);
	DIO_voidSetPinDirection(LED_GRN_PORT, LED_GRN_PIN, PIN_OUTPUT);
	DIO_voidSetPinDirection(LED_RED_PORT, LED_RED_PIN, PIN_OUTPUT);
	DIO_voidSetPinDirection(LED_YEL_PORT, LED_YEL_PIN, PIN_OUTPUT);
	LED_voidTurnOffLed(LED_BLU_ID);
	LED_voidTurnOffLed(LED_GRN_ID);
	LED_voidTurnOffLed(LED_RED_ID);
	LED_voidTurnOffLed(LED_YEL_ID);
}

void LED_voidTurnOnLed(u8 Copy_u8LedID){

	switch(Copy_u8LedID){
	case LED_BLU_ID: DIO_voidSetPinValue(LED_BLU_PORT,LED_BLU_PIN,PIN_HIGH);break;
	case LED_GRN_ID: DIO_voidSetPinValue(LED_GRN_PORT,LED_GRN_PIN,PIN_HIGH);break;
	case LED_RED_ID: DIO_voidSetPinValue(LED_RED_PORT,LED_RED_PIN,PIN_HIGH);break;
	case LED_YEL_ID: DIO_voidSetPinValue(LED_YEL_PORT,LED_YEL_PIN,PIN_HIGH);break;
	default:break;
	}
}

void LED_voidTurnOffLed(u8 Copy_u8LedID){

	switch(Copy_u8LedID){
	case LED_BLU_ID: DIO_voidSetPinValue(LED_BLU_PORT,LED_BLU_PIN,PIN_LOW);break;
	case LED_GRN_ID: DIO_voidSetPinValue(LED_GRN_PORT,LED_GRN_PIN,PIN_LOW);break;
	case LED_RED_ID: DIO_voidSetPinValue(LED_RED_PORT,LED_RED_PIN,PIN_LOW);break;
	case LED_YEL_ID: DIO_voidSetPinValue(LED_YEL_PORT,LED_YEL_PIN,PIN_LOW);break;
	default:break;
	}
}

void LED_voidToggleLed(u8 Copy_u8LedID){

	switch(Copy_u8LedID){
	case LED_BLU_ID: DIO_voidToggelPin(LED_BLU_PORT,LED_BLU_PIN);break;
	case LED_GRN_ID: DIO_voidToggelPin(LED_GRN_PORT,LED_GRN_PIN);break;
	case LED_RED_ID: DIO_voidToggelPin(LED_RED_PORT,LED_RED_PIN);break;
	case LED_YEL_ID: DIO_voidToggelPin(LED_YEL_PORT,LED_YEL_PIN);break;
	default:break;
	}
}
