/*
 * UART_Private.h
 *
 *  Created on: Nov 15, 2022
 *      Author: osama yassin
 */

#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_

/******* Data Register ********/
#define UDR_REG *((volatile u8*)0x2C)

/**** Control and Status Register A ****/
#define UCSRA_REG  *((volatile u8 *)0x2B)
#define UCSRA_MPCM (0)
#define UCSRA_U2X  (1)
#define UCSRA_PE   (2)
#define UCSRA_DOR  (3)
#define UCSRA_FE   (4)
#define UCSRA_UDRE (5)
#define UCSRA_TXC  (6)
#define UCSRA_RXC  (7)

/**** Control and Status Register B ****/
#define UCSRB_REG  *((volatile u8 *)0x2A)
#define UCSRB_TXB8  (0)
#define UCSRB_RXB8  (1)
#define UCSRB_UCSZ2 (2)
#define UCSRB_TXEN  (3)
#define UCSRB_RXEN  (4)
#define UCSRB_UDRIE (5)
#define UCSRB_TXCIE (6)
#define UCSRB_RXCIE (7)

/**** Control and Status Register C ****/
#define UCSRC_REG  *((volatile u8 *)0x40)
#define UCSRC_UCPOL  (0)
#define UCSRC_UCSZ0  (1)
#define UCSRC_UCSZ1  (2)
#define UCSRC_USBS   (3)
#define UCSRC_UPM0   (4)
#define UCSRC_UPM1   (5)
#define UCSRC_UMSEL  (6)
#define UCSRC_URSEL  (7)

/**** Baud Rate Register ****/
#define UBRRH_REG *((volatile u8 *)0x40)
#define UBRRL_REG *((volatile u8 *)0x29)

/**** Speed Configuration ****/
#define NORMAL_SPEED ((0x00))
#define DOUBLE_SPEED ((0x01))

/**** Multi-Proccessor Configuration ****/
#define MP_DISABLED ((0x00))
#define MP_ENABLED  ((0x01))

/**** TX RX Configuration ****/
#define TX_DISABLED ((0x00))
#define TX_ENABLED  ((0x01))

#define RX_DISABLED ((0x00))
#define RX_ENABLED  ((0x01))

/**** MODE Configuration ****/
#define ASYNC_MODE ((0x00))
#define SYNC_MODE  ((0x01))

/**** PARITY MODE Configuration ****/
#define PARITY_DISABLED ((0x00))
#define PARITY_EVEN     ((0x01))
#define PARITY_ODD      ((0x02))

/**** Stop BIT Configuration ****/
#define STOP_1_BIT ((0x00))
#define STOP_2_BIT ((0x01))

/**** Character size Configuration ****/
#define DATA_SIZE_8_BIT ((0x00))
#define DATA_SIZE_9_BIT ((0x01))

#endif /* USART_PRIVATE_H_ */
