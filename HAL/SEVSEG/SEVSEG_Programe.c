/*
 * SEVSEG_Programe.c
 *
 *  Created on: Nov 13, 2022
 *      Author: osama yassin
 */

/***HAL***/
#include "avr/delay.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
/***MCAL***/
#include "../../MCAL/DIO/DIO_Interface.h"
/***SEVSEG***/
#include "SEVSEG_Interface.h"
#include "SEVSEG_Private.h"
#include "SEVSEG_Config.h"


static u8 SEVSEG_u8FromU8toSevSeg(u8 copy_u8Num){
	switch(copy_u8Num){
	case 0:return SEVSEG_NUM_0; break;
	case 1:return SEVSEG_NUM_1; break;
	case 2:return SEVSEG_NUM_2; break;
	case 3:return SEVSEG_NUM_3; break;
	case 4:return SEVSEG_NUM_4; break;
	case 5:return SEVSEG_NUM_5; break;
	case 6:return SEVSEG_NUM_6; break;
	case 7:return SEVSEG_NUM_7; break;
	case 8:return SEVSEG_NUM_8; break;
	case 9:return SEVSEG_NUM_9; break;
	default:return SEVSEG_NUM_0; break;
	}

}
void SEVSEG_voidInit(){
	DIO_voidSetPortDirection(SEVSEG_NUM_PORT, PORT_OUTPUT);
	DIO_voidSetPinDirection(SEVSEG_COM_PORT, SEVSEG_COM1_PIN,PIN_OUTPUT);
	DIO_voidSetPinDirection(SEVSEG_COM_PORT, SEVSEG_COM2_PIN,PIN_OUTPUT);
}

void SEVSEG_voidPrintNum(u8 copy_u8Num){

	u8 num1 = copy_u8Num%10;
	u8 num2 = copy_u8Num/10;


	DIO_voidSetPortValue(SEVSEG_NUM_PORT, SEVSEG_u8FromU8toSevSeg(num1));
	DIO_voidSetPinValue(SEVSEG_COM_PORT,  SEVSEG_COM1_PIN,PIN_HIGH);
	DIO_voidSetPinValue(SEVSEG_COM_PORT,  SEVSEG_COM2_PIN,PIN_LOW);
	_delay_ms(1);

	DIO_voidSetPortValue(SEVSEG_NUM_PORT, SEVSEG_u8FromU8toSevSeg(num2));
	DIO_voidSetPinValue(SEVSEG_COM_PORT, SEVSEG_COM1_PIN,PIN_LOW);
	DIO_voidSetPinValue(SEVSEG_COM_PORT, SEVSEG_COM2_PIN,PIN_HIGH);
	_delay_ms(1);

	DIO_voidSetPinValue(SEVSEG_COM_PORT, SEVSEG_COM1_PIN,PIN_LOW);
	DIO_voidSetPinValue(SEVSEG_COM_PORT, SEVSEG_COM2_PIN,PIN_LOW);

}
