/*
 * ADC_Programe.c
 *
 *  Created on: Nov 8, 2022
 *      Author: osama yassin
 */

/***LIB***/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "util/delay.h"
/***ADC***/
#include "ADC_Interface.h"
#include "ADC_Private.h"
#include "ADC_Config.h"

void(*ADC_CallBack)(void) = NULL_PTR;

void ADC_voidInit(){
	ADCSRA_REG->Bits.ADEN = STD_HIGH;
	ADMUX_REG->Bits.REFS  = REF_VOLT;
	ADMUX_REG->Bits.ADLAR = TYPE_DATA;
	ADCSRA_REG->Bits.ADPS = PRESCALER;
#if ADC_ENABLE_INTERRUPT == 1
	ADCSRA_REG->Bits.ADIE = STD_HIGH;
#else
	ADCSRA_REG->Bits.ADIE = STD_LOW;
#endif
}

void ADC_voidChannelSelect(ADC_CHANNEL_TYPE copy_u8ChannelSelect){
	ADMUX_REG->Bits.MUX=copy_u8ChannelSelect;
}

void ADC_voidStartConversion_Polling(u16 *copy_u16Data){
	/***Clear Flag***/
	ADCSRA_REG->Bits.ADIF = STD_LOW;
	/***Start Conversion***/
	ADCSRA_REG->Bits.ADSC = STD_HIGH;
	/***Wait For Flag***/
	while(ADCSRA_REG->Bits.ADIF == STD_LOW);
	/***Reset Flag***/
	ADCSRA_REG->Bits.ADIF = STD_HIGH;
	/***Read Data***/
	*copy_u16Data = *((u16*)(ADCDATA_REG));
}

void ADC_voidStartConversion_Interrupt(){
	/***Clear Flag***/
	ADCSRA_REG->Bits.ADIF = STD_LOW;
	/***Start Conversion***/
	ADCSRA_REG->Bits.ADSC = STD_HIGH;
}

void ADC_voidReadData(u16 *copy_u16Data){
	/***Read Data***/
	*copy_u16Data = *((u16*)(ADCDATA_REG));
}

void ADC_voidSetCallBack(void(*copy_ptf)(void)){

	if(copy_ptf != NULL_PTR){
		ADC_CallBack = copy_ptf;
	}
}


void __vector_16() __attribute__((signal));
void __vector_16(){

	ADC_CallBack();

}

