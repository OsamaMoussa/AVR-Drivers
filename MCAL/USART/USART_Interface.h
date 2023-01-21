/*
 * UART_Interface.h
 *
 *  Created on: Nov 15, 2022
 *      Author: osama yassin
 */

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

/*** Functions ProtoTypes ***/
void USART_voidInit();
void USART_voidTransmitData(u16 copy_u16Data);
void USART_voidTransmitString(u8* copy_string);
u16 USART_u16ReceiveData(void);

#endif /* USART_INTERFACE_H_ */
