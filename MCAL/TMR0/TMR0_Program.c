/*
 * TIMER0_Program.c
 *
 *  Created on: Nov 12, 2022
 *      Author: osama yassin
 */

/***LIB***/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
/***MCAL***/
#include "../../MCAL/DIO/DIO_Interface.h"
/***TMR0***/
#include "TMR0_Interface.h"
#include "TMR0_Private.h"
#include "TMR0_Config.h"

/**** Static Variables ****/
static void (*TMR0_CallBack)(void) = NULL_PTR;
static u16 global_u16OverFlowTicks;
static u32 global_u32OverFlows;
static u16 global_u16Preload;

/**** Static Functions ****/
static void TMR0_voidCalculateNumberOfOverFlows(u16 copy_u16DesiredTime){
#if MODE == NORMAL_MODE
	f64 local_f64TickTime = (1.0*PRESCALER)/F_SYS;
	f64 local_f64OverFlows = (copy_u16DesiredTime/(global_u16OverFlowTicks*local_f64TickTime));
	global_u32OverFlows  = (u16) local_f64OverFlows;
	f32 local_f32Fraction = local_f64OverFlows - global_u32OverFlows;
	global_u32OverFlows++;
	global_u16Preload = (1-local_f32Fraction)*global_u32OverFlows;

#elif MODE == CTC_MODE
	f64 local_f64TickTime = (1.0*PRESCALER)/F_SYS;
	global_u32OverFlows = CTC_OVERFLOWS;
	global_u16OverFlowTicks = (copy_u16DesiredTime/(local_f64TickTime*global_u32OverFlows));

#endif
}

/****** Functions *****/
void TMR0_voidInit(){
#if MODE == NORMAL_MODE
	CLR_BIT(TCCR0_REG,TCCR0_WGM01);
	CLR_BIT(TCCR0_REG,TCCR0_WGM00);
	SET_BIT(TIMSK_REG,TIMSK_TOIE0);
	global_u16OverFlowTicks = NORMAL_OVERFLOW_TICKS;

#elif MODE == CTC_MODE
	SET_BIT(TCCR0_REG,TCCR0_WGM01);
	CLR_BIT(TCCR0_REG,TCCR0_WGM00);
	SET_BIT(TIMSK_REG,TIMSK_OCIE0);

#elif MODE == FPWM_MODE
	SET_BIT(TCCR0_REG,TCCR0_WGM01);
	SET_BIT(TCCR0_REG,TCCR0_WGM00);
	global_u16OverFlowTicks = NORMAL_OVERFLOW_TICKS;

#elif MODE == PWM_MODE
	CLR_BIT(TCCR0_REG,TCCR0_WGM01);
	SET_BIT(TCCR0_REG,TCCR0_WGM00);

#endif

}

void TMR0_voidStart(){

#if PRESCALER == PRESCALER_1
	CLR_BIT(TCCR0_REG,TCCR0_CS02);
	CLR_BIT(TCCR0_REG,TCCR0_CS01);
	SET_BIT(TCCR0_REG,TCCR0_CS00);

#elif PRESCALER == PRESCALER_8
	CLR_BIT(TCCR0_REG,TCCR0_CS02);
	SET_BIT(TCCR0_REG,TCCR0_CS01);
	CLR_BIT(TCCR0_REG,TCCR0_CS00);

#elif PRESCALER == PRESCALER_64
	CLR_BIT(TCCR0_REG,TCCR0_CS02);
	SET_BIT(TCCR0_REG,TCCR0_CS01);
	SET_BIT(TCCR0_REG,TCCR0_CS00);

#elif PRESCALER == PRESCALER_256
	SET_BIT(TCCR0_REG,TCCR0_CS02);
	CLR_BIT(TCCR0_REG,TCCR0_CS01);
	CLR_BIT(TCCR0_REG,TCCR0_CS00);

#elif PRESCALER == PRESCALER_1024
	SET_BIT(TCCR0_REG,TCCR0_CS02);
	CLR_BIT(TCCR0_REG,TCCR0_CS01);
	SET_BIT(TCCR0_REG,TCCR0_CS00);

#elif PRESCALER == EXT_CLK_FE
	SET_BIT(TCCR0_REG,TCCR0_CS02);
	SET_BIT(TCCR0_REG,TCCR0_CS01);
	CLR_BIT(TCCR0_REG,TCCR0_CS00);

#elif PRESCALER == EXT_CLK_RE
	SET_BIT(TCCR0_REG,TCCR0_CS02);
	SET_BIT(TCCR0_REG,TCCR0_CS01);
	SET_BIT(TCCR0_REG,TCCR0_CS00);

#endif

}

void TMR0_voidStop(){
	CLR_BIT(TCCR0_REG,TCCR0_CS02);
	CLR_BIT(TCCR0_REG,TCCR0_CS01);
	CLR_BIT(TCCR0_REG,TCCR0_CS00);
}

void TMR0_voidSetCallBack(void(*copy_ptf)(void), u16 copy_u16DesiredTime){

#if MODE == NORMAL_MODE
	if(copy_ptf != NULL_PTR){
		TMR0_CallBack = copy_ptf;
		TMR0_voidCalculateNumberOfOverFlows(copy_u16DesiredTime);
		TCNT0_REG = (u8)global_u16Preload;
		TMR0_voidStart();
	}

#elif MODE == CTC_MODE
	if(copy_ptf != NULL_PTR){
		TMR0_CallBack = copy_ptf;
		TMR0_voidCalculateNumberOfOverFlows(copy_u16DesiredTime);
		OCR0_REG = (u8)(global_u16OverFlowTicks-1);
		TMR0_voidStart();
	}
#endif

}

void TMR0_voidGeneratePWM(u8 copy_u8DutyCyclePercent){
	DIO_voidSetPinDirection(OC0_PORT,OC0_PIN,PIN_OUTPUT);
#if MODE == FPWM_MODE
	#if COM_MODE == COM_CLEAR
		SET_BIT(TCCR0_REG,TCCR0_COM01);
		CLR_BIT(TCCR0_REG,TCCR0_COM00);
		OCR0_REG = (u8)((copy_u8DutyCyclePercent/100.0)*global_u16OverFlowTicks);
		TMR0_voidStart();

	#elif COM_MODE == COM_SET
		SET_BIT(TCCR0_REG,TCCR0_COM01);
		SET_BIT(TCCR0_REG,TCCR0_COM00);
		//OCR0_REG = 128; //For 50% Duty Cycle
		OCR0_REG = (u8)((1.0-(copy_u8DutyCyclePercent/100.0))*global_u16OverFlowTicks);
		TMR0_voidStart();

	#endif

#elif MODE == PWM_MODE
	#if COM_MODE == COM_CLEAR
		SET_BIT(TCCR0_REG,TCCR0_COM01);
		CLR_BIT(TCCR0_REG,TCCR0_COM00);
		OCR0_REG = (u8)((copy_u8DutyCyclePercent*(NORMAL_OVERFLOW_TICKS-1))/100.0);
		TMR0_voidStart();

	#elif COM_MODE == COM_SET
		SET_BIT(TCCR0_REG,TCCR0_COM01);
		SET_BIT(TCCR0_REG,TCCR0_COM00);
		OCR0_REG = (u8)((NORMAL_OVERFLOW_TICKS-1)*(1-(copy_u8DutyCyclePercent/100.0)));
		TMR0_voidStart();
	#endif

#endif

}

/*** Timer_0 Compare Match ISR ***/
void __vector_10() __attribute__((signal));
void __vector_10(){
	static u32 static_u32OverFlowsCntr=0;
	static_u32OverFlowsCntr++;

	if(static_u32OverFlowsCntr == global_u32OverFlows){
		TMR0_CallBack();
		static_u32OverFlowsCntr=0;
	}
}

/**** Timer_0 ISR ****/
void __vector_11() __attribute__((signal));
void __vector_11(){
	static u32 static_u32OverFlowsCntr=0;
	static_u32OverFlowsCntr++;

	if(static_u32OverFlowsCntr==global_u32OverFlows){
		TMR0_CallBack();
		static_u32OverFlowsCntr=0;
		TCNT0_REG = global_u16Preload;
	}
}





