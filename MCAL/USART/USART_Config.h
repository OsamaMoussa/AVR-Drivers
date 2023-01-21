/*
 * UART_Config.h
 *
 *  Created on: Nov 15, 2022
 *      Author: osama yassin
 */

#ifndef USART_CONFIG_H_
#define USART_CONFIG_H_

/**** MODE Configuration ****/
#define MODE ASYNC_MODE

/**** Speed Configuration ****/
#define SPEED_MODE NORMAL_SPEED

/**** Multi-Proccessor Configuration ****/
#define MP MP_DISABLED

/**** TX RX Configuration ****/
#define TX_STATE TX_ENABLED
#define RX_STATE RX_ENABLED

/**** PARITY MODE Configuration ****/
#define PARITY PARITY_DISABLED

/**** Stop BIT Configuration ****/
#define STOP_BIT STOP_1_BIT

/**** Character size Configuration ****/
#define DATA_SIZE DATA_SIZE_8_BIT

/**** Baud Rate ****/
#define BAUD_RATE (9600UL)

/**** SYSTEM CLK Frequency ****/
#define F_SYS (16000000ULL)

#endif /* USART_CONFIG_H_ */
