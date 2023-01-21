/*
 * UART_Programe.c
 *
 *  Created on: Nov 15, 2022
 *      Author: osama yassin
 */

/****LIB****/
#include "avr/delay.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/****USART****/
#include "USART_Interface.h"
#include "USART_Private.h"
#include "USART_Config.h"

#define BAUD_NS_PRESCALE   (((F_SYS / (BAUD_RATE * 16UL))) - 1)
#define BAUD_DS_PRESCALE   (((F_SYS / (BAUD_RATE * 8UL))) - 1)
#define BAUD_SYNC_PRESCALE (((F_SYS / (BAUD_RATE * 2UL))) - 1)

void USART_voidInit(void){
	u8 local_UCSRC_REG;
	/* Turn on/off transmission and reception */
#if TX_STATE == TX_ENABLED
	SET_BIT(UCSRB_REG, UCSRB_TXEN);
#elif TX_STATE == TX_DISABLED
	CLR_BIT(UCSRB_REG, UCSRB_TXEN);
#endif
#if RX_STATE == RX_ENABLED
	SET_BIT(UCSRB_REG, UCSRB_RXEN);
#elif RX_STATE == RX_DISABLED
	CLR_BIT(UCSRB_REG, UCSRB_RXEN);
#endif

	/*Enable write on UCSR-C*/
	SET_BIT(local_UCSRC_REG,UCSRC_URSEL);
	/* Data Size*/
#if DATA_SIZE == DATA_SIZE_8_BIT
	CLR_BIT(local_UCSRC_REG, UCSRB_UCSZ2);
	SET_BIT(local_UCSRC_REG, UCSRC_UCSZ1);
	SET_BIT(local_UCSRC_REG, UCSRC_UCSZ0);
	UCSRC_REG = local_UCSRC_REG;
#elif DATA_SIZE DATA_SIZE_9_BIT
	SET_BIT(local_UCSRC_REG, UCSRB_UCSZ2);
	SET_BIT(local_UCSRC_REG, UCSRC_UCSZ1);
	SET_BIT(local_UCSRC_REG, UCSRC_UCSZ0);
	UCSRC_REG = local_UCSRC_REG;
#endif

	/*Communication Mode ASync/Sync */
#if MODE == ASYNC_MODE
	CLR_BIT(local_UCSRC_REG, UCSRC_UMSEL);
	UCSRC_REG = local_UCSRC_REG;
#elif MODE == SYNC_MODE
	SET_BIT(local_UCSRC_REG, UCSRC_UMSEL);
	UCSRC_REG = local_UCSRC_REG;
#endif

	/* PARITY Selection */
#if PARITY==PARITY_DISABLED
	CLR_BIT(local_UCSRC_REG, UCSRC_UPM1);
	CLR_BIT(local_UCSRC_REG, UCSRC_UPM0);
	UCSRC_REG = local_UCSRC_REG;
#elif PARITY==PARITY_EVEN
	SET_BIT(local_UCSRC_REG, UCSRC_UPM1);
	CLR_BIT(local_UCSRC_REG, UCSRC_UPM0);
	UCSRC_REG = local_UCSRC_REG;
#elif PARITY==PARITY_ODD
	SET_BIT(local_UCSRC_REG, UCSRC_UPM1);
	SET_BIT(local_UCSRC_REG, UCSRC_UPM0);
	UCSRC_REG = local_UCSRC_REG;
#endif

	/* Stop Bits*/
#if STOP_BIT==STOP_1_BIT
	CLR_BIT(local_UCSRC_REG, UCSRC_USBS);
	UCSRC_REG = local_UCSRC_REG;
#elif STOP_BIT==STOP_2_BIT
	SET_BIT(local_UCSRC_REG, UCSRC_USBS);
	UCSRC_REG = local_UCSRC_REG;
#endif

	/*Enable write on UBRR*/
	CLR_BIT(local_UCSRC_REG, UCSRC_URSEL);
	UCSRC_REG = local_UCSRC_REG;
	/* Speed Mode + Baud Rate */
#if SPEED_MODE == NORMAL_SPEED
	CLR_BIT(UCSRA_REG,UCSRA_U2X);
	UBRRL_REG = BAUD_NS_PRESCALE;
	UBRRH_REG = (BAUD_NS_PRESCALE >> 8);
#elif SPEED_MODE == DOUBLE_SPEED_SPEED
	SET_BIT(UCSRA_REG,UCSRA_U2X);
	UBRRL_REG = BAUD_DS_PRESCALE;
	UBRRH_REG = (BAUD_DS_PRESCALE >> 8);
#elif MODE == SYNC_MODE
	UBRRL_REG = BAUD_SYNC_PRESCALE;
	UBRRH_REG = (BAUD_SYNC_PRESCALE >> 8);
#endif
}

void USART_voidTransmitData(u16 copy_u16Data){
	/* Wait for empty transmit buffer */
	while (!GET_BIT(UCSRA_REG,UCSRA_UDRE));

	/* Put data into buffer, sends the data */
#if DATA_SIZE == DATA_SIZE_9_BIT
	UDR_REG = (u8)(copy_u16Data | (GET_BIT(UCSRB_REG, UCSRB_TXB8)<<8));
#else
	UDR_REG = (u8)copy_u16Data;
#endif
}

void USART_voidTransmitString(u8* copy_string){
	u32 i=0;
	for(;copy_string[i]!='\0';i++){
		USART_voidTransmitData((u16)copy_string[i]);
	}
}

u16 USART_u16ReceiveData(void){
	/* Wait for data to be received */
	while (!GET_BIT(UCSRA_REG, UCSRA_RXC));

	/* Get and return received data from buffer */

#if DATA_SIZE == DATA_SIZE_9_BIT
	return UDR_REG | GET_BIT(UCSRB_REG, UCSRB_RXB8)<<8 ;

#else
	return UDR_REG;
#endif
}

