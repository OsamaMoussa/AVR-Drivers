
/***LIB***/
#include "util/delay.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
/***MCAL***/
#include "../../MCAL/DIO/DIO_Interface.h"
/***EXT***/
#include "EXT_Interface.h"
#include "EXT_Private.h"
#include "EXT_Config.h"


static void(*EXT_CallBacks[])(void) = {NULL_PTR,NULL_PTR,NULL_PTR};

static u8 EXT_u8BtnDebounce(EXT_EI_NUM_TYPE copy_u8EiNum){

		switch(copy_u8EiNum){
			case EXT0:
				_delay_ms(DEBOUNCE_DELAY);
				return DIO_voidGetPinValue(EXT_INT0_REG, EXT_INT0_PIN);
				break;
			case EXT1:
				_delay_ms(DEBOUNCE_DELAY);
				return DIO_voidGetPinValue(EXT_INT1_REG, EXT_INT1_PIN);
				break;
			case EXT2:
				_delay_ms(DEBOUNCE_DELAY);
				return DIO_voidGetPinValue(EXT_INT2_REG, EXT_INT2_PIN);
				break;
			default:
				return PIN_HIGH;
				break;
		}
}

static u8 EXT_u8IsBtnPressed(EXT_EI_NUM_TYPE copy_u8EiNum){

	switch(copy_u8EiNum){
		case EXT0:
			return !EXT_u8BtnDebounce(EXT0);
			break;
		case EXT1:
			return !EXT_u8BtnDebounce(EXT1);
			break;
		case EXT2:
			return !EXT_u8BtnDebounce(EXT2);
			break;
		default:
			return 0;
			break;
	}

}


void EXT_voidInit(EXT_EI_NUM_TYPE copy_u8EiNum, EXT_EI_SENSE_TYPE copy_u8ControlSens){

	switch(copy_u8EiNum){

		case EXT0:
			switch(copy_u8ControlSens){
				case FALLING_EDGE:
					CLR_BIT(MCUCR_REG,MCUCR_ISC00);
					SET_BIT(MCUCR_REG,MCUCR_ISC01);
					break;
				case RISNIG_EDGE:
					SET_BIT(MCUCR_REG,MCUCR_ISC00);
					SET_BIT(MCUCR_REG,MCUCR_ISC01);
					break;
			}
			SET_BIT(GICR_REG,GICR_INT0);
			break;

		case EXT1:
			switch(copy_u8ControlSens){
				case FALLING_EDGE:
					CLR_BIT(MCUCR_REG,MCUCR_ISC10);
					SET_BIT(MCUCR_REG,MCUCR_ISC11);
					break;
				case RISNIG_EDGE:
					SET_BIT(MCUCR_REG,MCUCR_ISC10);
					SET_BIT(MCUCR_REG,MCUCR_ISC11);
					break;
			}
			SET_BIT(GICR_REG,GICR_INT1);
			break;

		case EXT2:
			switch(copy_u8ControlSens){
				case FALLING_EDGE:
					CLR_BIT(MCUCSR_REG,MCUCSR_ISC2);
					break;
				case RISNIG_EDGE:
					SET_BIT(MCUCSR_REG,MCUCSR_ISC2);
					break;
			}
			SET_BIT(GICR_REG,GICR_INT2);
			break;
	}

}

void EXT_voidSetCallBack(EXT_EI_NUM_TYPE copy_u8EiNum, void(*Copy_ptf)(void)){

	if(Copy_ptf != NULL_PTR){
		EXT_CallBacks[copy_u8EiNum] = Copy_ptf;
	}

}

/*** ISR ***/
void __vector_1() __attribute__((signal));
void __vector_1(){

	//if(EXT_u8IsBtnPressed(EXT0)){
		EXT_CallBacks[EXT0]();
	//}
}

void __vector_2() __attribute__((signal));
void __vector_2(){

	//if(EXT_u8IsBtnPressed(EXT1)){
		EXT_CallBacks[EXT1]();
	//}
}


void __vector_3() __attribute__((signal));
void __vector_3(){

	//if(EXT_u8IsBtnPressed(EXT2)){
		EXT_CallBacks[EXT2]();
	//}
}



