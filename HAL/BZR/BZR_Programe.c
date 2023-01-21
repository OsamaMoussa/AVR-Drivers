/*
 * BZR_Programe.c
 *
 *  Created on: Jan 11, 2023
 *      Author: osama yassin
 */

/****LIB****/
#include "util/delay.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
/****MCAL****/
#include "../../MCAL/DIO/DIO_Interface.h"
/****BTN****/
#include "BZR_Interface.h"
#include "BZR_Private.h"
#include "BZR_Config.h"

void BZR_voidInit(void){
	DIO_voidSetPinDirection(BZR_PORT, BZR_PIN, PIN_OUTPUT);
}


void BZR_voidActivate(void){
	DIO_voidSetPinValue(BZR_PORT, BZR_PIN, STD_HIGH);
}

void BZR_voidDeactivate(void){
	DIO_voidSetPinValue(BZR_PORT, BZR_PIN, STD_LOW);
}

