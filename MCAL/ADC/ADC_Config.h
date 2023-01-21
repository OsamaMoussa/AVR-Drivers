/*
 * ADC_Config.h
 *
 *  Created on: Nov 8, 2022
 *      Author: osama yassin
 */

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

/*** Reference Voltage ***/
/*AREF_InternalVrefturnedOff
* AVCC
* INTERNAL_2_5V*/
#define REF_VOLT (AVCC)

/*** Data Adjustment ***/
/*RIGHT_ADJUSTED
* LEFT_ADJUSTED*/
#define TYPE_DATA (RIGHT_ADJUSTED)

/*PRESCALER_2
* PRESCALER_4
* PRESCALER_8
* PRESCALER_16
* PRESCALER_32
* PRESCALER_64
* PRESCALER_128 */
#define PRESCALER (PRESCALER_4)

/*** Enable/Disable Interrupt ***/
#define ADC_ENABLE_INTERRUPT (0)

#endif /* ADC_CONFIG_H_ */
