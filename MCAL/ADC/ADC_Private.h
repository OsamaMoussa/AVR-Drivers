/*
 * ADC_Private.h
 *
 *  Created on: Nov 8, 2022
 *      Author: osama yassin
 */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

/*** ADMUX register ***/
typedef union{
	struct{
		u8 MUX:5;
		u8 ADLAR:1;
		u8 REFS:2;
	}Bits;
	u8 Byte;
}ADMUX;
#define ADMUX_REG ((volatile ADMUX*)(0x27))

/*** ADCSRA register ***/
typedef union{
	struct{
		u8 ADPS:3;
		u8 ADIE:1;
		u8 ADIF:1;
		u8 ADATE:1;
		u8 ADSC:1;
		u8 ADEN:1;
	}Bits;
	u8 Byte;
}ADCSRA;
#define ADCSRA_REG ((volatile ADCSRA*)(0x26))

/*** ADC Data Register ***/
#define ADCDATA_REG ((volatile u16*)(0x24))

/*** Reference Voltage ***/
#define AREF_InternalVrefturnedOff        ((u8)(0b00))
#define AVCC                              ((u8)(0b01))
#define INTERNAL_2_5V                     ((u8)(0b11))

/*** Data Adjustment ***/
#define RIGHT_ADJUSTED (0)
#define LEFT_ADJUSTED  (1)

/*** ADC Prescaler ***/
#define PRESCALER_2   ((u8)0X01)
#define PRESCALER_4   ((u8)0X02)
#define PRESCALER_8   ((u8)0X03)
#define PRESCALER_16  ((u8)0X04)
#define PRESCALER_32  ((u8)0X05)
#define PRESCALER_64  ((u8)0X06)
#define PRESCALER_128 ((u8)0X07)




#endif /* ADC_PRIVATE_H_ */
