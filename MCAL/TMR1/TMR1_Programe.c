/*
 * TMR1_Programe.c
 *
 *  Created on: Nov 14, 2022
 *      Author: osama yassin
 */

/***LIB****/
#include "util/delay.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
/***MCAL***/
#include "../../MCAL/DIO/DIO_Interface.h"
/***TMR1***/
#include "TMR1_Interface.h"
#include "TMR1_Private.h"
#include "TMR1_Config.h"

void TMR1_voidInit(){
	/*** OC1A --> OUTPUT ***/
	DIO_voidSetPinDirection(OC1A_PORT,OC1A_PIN,PIN_OUTPUT);

	/*** Compare match = clear on compare ***/
	SET_BIT(TCCR1A_REG,TCCR1A_COM1A1);
	CLR_BIT(TCCR1A_REG,TCCR1A_COM1A0);

	/*** MODE = FAST_PWM, TOP=ICR1 ***/
	SET_BIT(TCCR1B_REG,TCCR1B_WGM13);
	SET_BIT(TCCR1B_REG,TCCR1B_WGM12);
	SET_BIT(TCCR1A_REG,TCCR1A_WGM11);
	CLR_BIT(TCCR1A_REG,TCCR1A_WGM10);

	/*** Top Value ***/
	ICR1_REG = (u16)(40000UL);  //for Period_Time = 20 mSec

	/*** Compare match from 2000 to 4000 ***/
	OCR1A_REG = (u16)(2000UL); //for On_Time = 1mSec

	/*** Prescaler = 8 ***/
	CLR_BIT(TCCR1B_REG,TCCR1B_CS12);
	SET_BIT(TCCR1B_REG,TCCR1B_CS11);
	CLR_BIT(TCCR1A_REG,TCCR1B_CS10);
}


void TMR1_voidGeneratePWMtoRotateServo(){
	u16 i=2000UL;

	for( ; i<=4000UL ;i++){
		OCR1A_REG = (u16)i;
		_delay_ms(5);
	}
}
