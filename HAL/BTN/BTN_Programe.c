/*
 * BTN_Programe.c
 *
 *  Created on: Nov 8, 2022
 *      Author: osama yassin
 */

/****LIB****/
#include "util/delay.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
/****MCAL****/
#include "../../MCAL/DIO/DIO_Interface.h"
/****BTN****/
#include "BTN_Interface.h"
#include "BTN_Private.h"
#include "BTN_Config.h"

static u8 BTN_u8BtnDebounce(u8 copy_u8BtnID){

	switch(copy_u8BtnID){
	case BTN_INT0_ID:
		_delay_ms(DEBOUNCE_DELAY);
		return DIO_voidGetPinValue(BTN_INT0_REG, BTN_INT0_PIN);
		break;
	case BTN_INT1_ID:
		_delay_ms(DEBOUNCE_DELAY);
		return DIO_voidGetPinValue(BTN_INT1_REG, BTN_INT1_PIN);
		break;
	case BTN_INT2_ID:
		_delay_ms(DEBOUNCE_DELAY);
		return DIO_voidGetPinValue(BTN_INT2_REG, BTN_INT2_PIN);
		break;
	default:
		return PIN_HIGH;
		break;
	}
}

void BTN_voidInit(){

	/*** Pull up (Normally high) ***/
	DIO_voidSetPinDirection(BTN_INT0_REG, BTN_INT0_PIN, PIN_INPUT);
	DIO_voidSetPinDirection(BTN_INT1_REG, BTN_INT1_PIN, PIN_INPUT);
	DIO_voidSetPinDirection(BTN_INT2_REG, BTN_INT2_PIN, PIN_INPUT);

}

u8 BTN_u8IsBtnPressed(u8 copy_u8BtnID){

	switch(copy_u8BtnID){
	case BTN_INT0_ID:
		return !BTN_u8BtnDebounce(BTN_INT0_ID);
		break;
	case BTN_INT1_ID:
		return !BTN_u8BtnDebounce(BTN_INT1_ID);
		break;
	case BTN_INT2_ID:
		return !BTN_u8BtnDebounce(BTN_INT2_ID);
		break;
	default:
		return 0;
		break;
	}

}


