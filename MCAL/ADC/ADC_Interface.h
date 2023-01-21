/*
 * ADC_Interface.h
 *
 *  Created on: Nov 8, 2022
 *      Author: osama yassin
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

/***Channel selection***/
#define ADC_CHANNEL_TYPE u8
#define CHANNEL_0 (0x00)
#define CHANNEL_1 (0x01)
#define CHANNEL_2 (0x02)
#define CHANNEL_3 (0x03)
#define CHANNEL_4 (0x04)
#define CHANNEL_5 (0x05)
#define CHANNEL_6 (0x06)
#define CHANNEL_7 (0x07)

/*** Functions ProtoTypes ***/
void ADC_voidInit();
void ADC_voidChannelSelect(ADC_CHANNEL_TYPE copy_u8ChannelSelect);
void ADC_voidStartConversion_Polling(u16 *copy_u16Data);
void ADC_voidStartConversion_Interrupt();
void ADC_voidReadData(u16 *copy_u16Data);
void ADC_voidSetCallBack(void(*copy_ptf)(void));

#endif /* ADC_INTERFACE_H_ */
