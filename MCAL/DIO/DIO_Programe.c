/*
 * DIO_Programe.c

 *
 *  Created on: Nov 5, 2022
 *      Author: osama yassin
 */

/***LIB***/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
/***DIO***/
#include "DIO_Interface.h"
#include "DIO_Private.h"


void DIO_voidSetPinDirection(DIO_PORT_TYPE Copy_u8PortID, DIO_PIN_TYPE Copy_u8PinID, DIO_PIN_DIR_TYPE Copy_u8PinDir){

	if(Copy_u8PinDir==PIN_INPUT){
		switch(Copy_u8PortID){
			case PORTA_ID: CLR_BIT(DDRA_REG,Copy_u8PinID);
			break;
			case PORTB_ID: CLR_BIT(DDRB_REG,Copy_u8PinID);
			break;
			case PORTC_ID: CLR_BIT(DDRC_REG,Copy_u8PinID);
			break;
			case PORTD_ID: CLR_BIT(DDRD_REG,Copy_u8PinID);
			break;
		}
	}
	else if(Copy_u8PinDir==PIN_OUTPUT){
		switch(Copy_u8PortID){
			case PORTA_ID: SET_BIT(DDRA_REG,Copy_u8PinID);
			break;
			case PORTB_ID: SET_BIT(DDRB_REG,Copy_u8PinID);
			break;
			case PORTC_ID: SET_BIT(DDRC_REG,Copy_u8PinID);
			break;
			case PORTD_ID: SET_BIT(DDRD_REG,Copy_u8PinID);
			break;
		}
	}

}

void DIO_voidSetPinValue(DIO_PORT_TYPE Copy_u8PortID, DIO_PIN_TYPE Copy_u8PinID, DIO_PIN_VAL_TYPE Copy_u8PinVal){

	if(Copy_u8PinVal==PIN_LOW){
		switch(Copy_u8PortID){
			case PORTA_ID: CLR_BIT(PORTA_REG,Copy_u8PinID);
			break;
			case PORTB_ID: CLR_BIT(PORTB_REG,Copy_u8PinID);
			break;
			case PORTC_ID: CLR_BIT(PORTC_REG,Copy_u8PinID);
			break;
			case PORTD_ID: CLR_BIT(PORTD_REG,Copy_u8PinID);
			break;
		}
	}
	else if(Copy_u8PinVal==PIN_HIGH){
		switch(Copy_u8PortID){
			case PORTA_ID: SET_BIT(PORTA_REG,Copy_u8PinID);
			break;
			case PORTB_ID: SET_BIT(PORTB_REG,Copy_u8PinID);
			break;
			case PORTC_ID: SET_BIT(PORTC_REG,Copy_u8PinID);
			break;
			case PORTD_ID: SET_BIT(PORTD_REG,Copy_u8PinID);
			break;
		}
	}
}

void DIO_voidSetPortDirection(DIO_PORT_TYPE Copy_u8PortID, DIO_PORT_DIR_TYPE Copy_u8PortDir){

	switch(Copy_u8PortID){
		case PORTA_ID: DDRA_REG = Copy_u8PortDir;
		break;
		case PORTB_ID: DDRB_REG = Copy_u8PortDir;
		break;
		case PORTC_ID: DDRC_REG = Copy_u8PortDir;
		break;
		case PORTD_ID: DDRD_REG = Copy_u8PortDir;
		break;
	}
}

void DIO_voidSetPortValue(DIO_PORT_TYPE Copy_u8PortID, DIO_PIN_VAL_TYPE Copy_u8PortVal){

	switch(Copy_u8PortID){
		case PORTA_ID: PORTA_REG = Copy_u8PortVal;
		break;
		case PORTB_ID: PORTB_REG = Copy_u8PortVal;
		break;
		case PORTC_ID: PORTC_REG = Copy_u8PortVal;
		break;
		case PORTD_ID: PORTD_REG = Copy_u8PortVal;
		break;
	}

}

DIO_PIN_VAL_TYPE DIO_voidGetPinValue(DIO_PORT_TYPE Copy_u8PortID , DIO_PIN_TYPE Copy_u8PinID){

	switch(Copy_u8PortID){
		case PORTA_ID: return GET_BIT(PINA_REG, Copy_u8PinID);
		break;
		case PORTB_ID: return GET_BIT(PINB_REG, Copy_u8PinID);
		break;
		case PORTC_ID: return GET_BIT(PINC_REG, Copy_u8PinID);
		break;
		case PORTD_ID: return GET_BIT(PIND_REG, Copy_u8PinID);
		break;
		default: return 0;
		break;
		}
}

//void DIO_voidGetPinValue(u8 Copy_u8PortID , u8 Copy_u8PinID ,u8 *Copy_u8PinVal){
//
//	switch(Copy_u8PortID){
//		case PORTA_ID: *Copy_u8PinVal = GET_BIT(PINA_REG, Copy_u8PinID);
//		break;
//		case PORTB_ID: *Copy_u8PinVal = GET_BIT(PINB_REG, Copy_u8PinID);
//		break;
//		case PORTC_ID: *Copy_u8PinVal = GET_BIT(PINC_REG, Copy_u8PinID);
//		break;
//		case PORTD_ID: *Copy_u8PinVal = GET_BIT(PIND_REG, Copy_u8PinID);
//		break;
//		}
//}

void DIO_voidToggelPin(DIO_PORT_TYPE Copy_u8PortID, DIO_PIN_TYPE Copy_u8PinID){

	switch(Copy_u8PortID){
		case PORTA_ID: TOG_BIT(PORTA_REG, Copy_u8PinID);
		break;
		case PORTB_ID: TOG_BIT(PORTB_REG, Copy_u8PinID);
		break;
		case PORTC_ID: TOG_BIT(PORTC_REG, Copy_u8PinID);
		break;
		case PORTD_ID: TOG_BIT(PORTD_REG, Copy_u8PinID);
		break;
		}

}

