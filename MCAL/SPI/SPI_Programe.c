/*
 * SPI_Programe.c
 *
 *  Created on: Nov 15, 2022
 *      Author: osama yassin
 */

/****LIB****/
#include "avr/delay.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
/****MCAL****/
#include "../../MCAL/DIO/DIO_Interface.h"
/****SPI****/
#include "SPI_Private.h"
#include "SPI_Config.h"
#include "SPI_Interface.h"

#include "../../HAL/LED/LED_Interface.h"

void SPI_voidInit(void){
#if SPI_MODE == MASTER
	SET_BIT(SPCR_REG, SPCR_MSTR); //Master mode
	CLR_BIT(SPCR_REG, SPCR_DORD); //MSB
	/*** Prescaler=16 ***/
	SET_BIT(SPCR_REG,SPCR_SPR0);
	/***Pin Configuration***/
	DIO_voidSetPinDirection(SPI_PORT,SS,  PIN_OUTPUT);
	DIO_voidSetPinDirection(SPI_PORT,MOSI,PIN_OUTPUT);
	DIO_voidSetPinDirection(SPI_PORT,MISO,PIN_INPUT);
	DIO_voidSetPinDirection(SPI_PORT,SCK, PIN_OUTPUT);
	DIO_voidSetPinValue(SPI_PORT,SS, PIN_LOW);
	/***SPI Enable ***/
	SET_BIT(SPCR_REG, SPCR_SPE);

#elif SPI_MODE == SLAVE
	CLR_BIT(SPCR_REG, SPCR_MSTR); //Slave mode
	CLR_BIT(SPCR_REG, SPCR_DORD); //MSB
	/***Pin Configuration***/
	DIO_voidSetPinDirection(SPI_PORT,SS,PIN_INPUT);
	DIO_voidSetPinValue(SPI_PORT,SS,PIN_HIGH);
	DIO_voidSetPinDirection(SPI_PORT,MOSI,PIN_INPUT);
	DIO_voidSetPinDirection(SPI_PORT,MISO,PIN_OUTPUT);
	DIO_voidSetPinDirection(SPI_PORT,SCK, PIN_INPUT);
	/***SPI Enable ***/
	SET_BIT(SPCR_REG, SPCR_SPE);
#endif
}

u8 SPI_voidTransmitAndReceive(u8 copy_u8Data){
	SPDR_REG = copy_u8Data;
	while(!GET_BIT(SPSR_REG,SPSR_SPIF));
	return SPDR_REG;
}
