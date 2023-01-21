/*
 * SSD_Programe.c
 *
 *  Created on: Dec 17, 2022
 *      Author: osama yassin
 */

/***HAL***/
//#include "avr/delay.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
/***MCAL***/
#include "../../MCAL/DIO/DIO_Interface.h"
/***SSD***/
#include "SSD_Interface.h"
#include "SSD_Private.h"
#include "SSD_Config.h"


static void voidPrintNumOnSSD(u8 copy_u8Num){
	switch(copy_u8Num){
	case 0:
		DIO_voidSetPinValue(SSD_NUM_PORT, SSD_BIT3, PIN_LOW);
		DIO_voidSetPinValue(SSD_NUM_PORT, SSD_BIT2, PIN_LOW);
		DIO_voidSetPinValue(SSD_NUM_PORT, SSD_BIT1, PIN_LOW);
		DIO_voidSetPinValue(SSD_NUM_PORT, SSD_BIT0, PIN_LOW);
		break;
	case 1:
		DIO_voidSetPinValue(SSD_NUM_PORT, SSD_BIT3, PIN_LOW);
		DIO_voidSetPinValue(SSD_NUM_PORT, SSD_BIT2, PIN_LOW);
		DIO_voidSetPinValue(SSD_NUM_PORT, SSD_BIT1, PIN_LOW);
		DIO_voidSetPinValue(SSD_NUM_PORT, SSD_BIT0, PIN_HIGH);
		break;
	case 2:
		DIO_voidSetPinValue(SSD_NUM_PORT, SSD_BIT3, PIN_LOW);
		DIO_voidSetPinValue(SSD_NUM_PORT, SSD_BIT2, PIN_LOW);
		DIO_voidSetPinValue(SSD_NUM_PORT, SSD_BIT1, PIN_HIGH);
		DIO_voidSetPinValue(SSD_NUM_PORT, SSD_BIT0, PIN_LOW);
		break;
	case 3:
		DIO_voidSetPinValue(SSD_NUM_PORT, SSD_BIT3, PIN_LOW);
		DIO_voidSetPinValue(SSD_NUM_PORT, SSD_BIT2, PIN_LOW);
		DIO_voidSetPinValue(SSD_NUM_PORT, SSD_BIT1, PIN_HIGH);
		DIO_voidSetPinValue(SSD_NUM_PORT, SSD_BIT0, PIN_HIGH);
		break;
	case 4:
		DIO_voidSetPinValue(SSD_NUM_PORT, SSD_BIT3, PIN_LOW);
		DIO_voidSetPinValue(SSD_NUM_PORT, SSD_BIT2, PIN_HIGH);
		DIO_voidSetPinValue(SSD_NUM_PORT, SSD_BIT1, PIN_LOW);
		DIO_voidSetPinValue(SSD_NUM_PORT, SSD_BIT0, PIN_LOW);
		break;
	case 5:
		DIO_voidSetPinValue(SSD_NUM_PORT, SSD_BIT3, PIN_LOW);
		DIO_voidSetPinValue(SSD_NUM_PORT, SSD_BIT2, PIN_HIGH);
		DIO_voidSetPinValue(SSD_NUM_PORT, SSD_BIT1, PIN_LOW);
		DIO_voidSetPinValue(SSD_NUM_PORT, SSD_BIT0, PIN_HIGH);
		break;
	case 6:
		DIO_voidSetPinValue(SSD_NUM_PORT, SSD_BIT3, PIN_LOW);
		DIO_voidSetPinValue(SSD_NUM_PORT, SSD_BIT2, PIN_HIGH);
		DIO_voidSetPinValue(SSD_NUM_PORT, SSD_BIT1, PIN_HIGH);
		DIO_voidSetPinValue(SSD_NUM_PORT, SSD_BIT0, PIN_LOW);
		break;
	case 7:
		DIO_voidSetPinValue(SSD_NUM_PORT, SSD_BIT3, PIN_LOW);
		DIO_voidSetPinValue(SSD_NUM_PORT, SSD_BIT2, PIN_HIGH);
		DIO_voidSetPinValue(SSD_NUM_PORT, SSD_BIT1, PIN_HIGH);
		DIO_voidSetPinValue(SSD_NUM_PORT, SSD_BIT0, PIN_HIGH);
		break;
	case 8:
		DIO_voidSetPinValue(SSD_NUM_PORT, SSD_BIT3, PIN_HIGH);
		DIO_voidSetPinValue(SSD_NUM_PORT, SSD_BIT2, PIN_LOW);
		DIO_voidSetPinValue(SSD_NUM_PORT, SSD_BIT1, PIN_LOW);
		DIO_voidSetPinValue(SSD_NUM_PORT, SSD_BIT0, PIN_LOW);
		break;
	case 9:
		DIO_voidSetPinValue(SSD_NUM_PORT, SSD_BIT3, PIN_HIGH);
		DIO_voidSetPinValue(SSD_NUM_PORT, SSD_BIT2, PIN_LOW);
		DIO_voidSetPinValue(SSD_NUM_PORT, SSD_BIT1, PIN_LOW);
		DIO_voidSetPinValue(SSD_NUM_PORT, SSD_BIT0, PIN_HIGH);
		break;
	default:
		break;
	}

}

void SSD_voidInit(){

	/* Output Number Ports  */
	DIO_voidSetPortDirection(SSD_NUM_PORT, PORT_OUTPUT);

	/* Output COM  */
	DIO_voidSetPinDirection(SSD_COM1_PORT, SSD_COM1_PIN, PIN_OUTPUT);
	DIO_voidSetPinDirection(SSD_COM2_PORT, SSD_COM2_PIN, PIN_OUTPUT);
	DIO_voidSetPinDirection(SSD_COM3_PORT, SSD_COM3_PIN, PIN_OUTPUT);
	DIO_voidSetPinDirection(SSD_COM4_PORT, SSD_COM4_PIN, PIN_OUTPUT);

	/* Disable All SSDs */
	DIO_voidSetPinValue(SSD_COM1_PORT,  SSD_COM1_PIN, PIN_HIGH);
	DIO_voidSetPinValue(SSD_COM2_PORT,  SSD_COM2_PIN, PIN_HIGH);
	DIO_voidSetPinValue(SSD_COM3_PORT,  SSD_COM3_PIN, PIN_HIGH);
	DIO_voidSetPinValue(SSD_COM4_PORT,  SSD_COM4_PIN, PIN_HIGH);
}


void SSD_voidPrintNumOnSSD_1(u8 copy_u8Num){
	/* Enable SSD1 only */
	DIO_voidSetPinValue(SSD_COM1_PORT,  SSD_COM1_PIN, PIN_LOW);
	DIO_voidSetPinValue(SSD_COM2_PORT,  SSD_COM2_PIN, PIN_HIGH);
	DIO_voidSetPinValue(SSD_COM3_PORT,  SSD_COM3_PIN, PIN_HIGH);
	DIO_voidSetPinValue(SSD_COM4_PORT,  SSD_COM4_PIN, PIN_HIGH);
	/* Print Number on SSD1 */
	voidPrintNumOnSSD(copy_u8Num);

}

void SSD_voidPrintNumOnSSD_2(u8 copy_u8Num){
	/* Enable SSD2 only */
	DIO_voidSetPinValue(SSD_COM1_PORT,  SSD_COM1_PIN, PIN_HIGH);
	DIO_voidSetPinValue(SSD_COM2_PORT,  SSD_COM2_PIN, PIN_LOW);
	DIO_voidSetPinValue(SSD_COM3_PORT,  SSD_COM3_PIN, PIN_HIGH);
	DIO_voidSetPinValue(SSD_COM4_PORT,  SSD_COM4_PIN, PIN_HIGH);
	/* Print Number on SSD2 */
	voidPrintNumOnSSD(copy_u8Num);
}

void SSD_voidPrintNumOnSSD_3(u8 copy_u8Num){
	/* Enable SSD3 only */
	DIO_voidSetPinValue(SSD_COM1_PORT,  SSD_COM1_PIN, PIN_HIGH);
	DIO_voidSetPinValue(SSD_COM2_PORT,  SSD_COM2_PIN, PIN_HIGH);
	DIO_voidSetPinValue(SSD_COM3_PORT,  SSD_COM3_PIN, PIN_LOW);
	DIO_voidSetPinValue(SSD_COM4_PORT,  SSD_COM4_PIN, PIN_HIGH);
	/* Print Number on SSD3 */
	voidPrintNumOnSSD(copy_u8Num);
}

void SSD_voidPrintNumOnSSD_4(u8 copy_u8Num){
	/* Enable SSD4 only */
	DIO_voidSetPinValue(SSD_COM1_PORT,  SSD_COM1_PIN, PIN_HIGH);
	DIO_voidSetPinValue(SSD_COM2_PORT,  SSD_COM2_PIN, PIN_HIGH);
	DIO_voidSetPinValue(SSD_COM3_PORT,  SSD_COM3_PIN, PIN_HIGH);
	DIO_voidSetPinValue(SSD_COM4_PORT,  SSD_COM4_PIN, PIN_LOW);
	/* Print Number on SSD4 */
	voidPrintNumOnSSD(copy_u8Num);
}


