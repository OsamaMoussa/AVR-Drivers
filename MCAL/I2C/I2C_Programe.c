/*
 * I2C_Programe.c
 *
 *  Created on: Nov 19, 2022
 *      Author: osama yassin
 */

/****LIB****/
#include "avr/delay.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
/****I2C****/
#include "I2C_Interface.h"
#include "I2C_Private.h"
#include "I2C_Config.h"

void I2C_voidMastrInit(void){

	/*		Set the Bit Rate = 100KHz			*/
	TWBR_REG = 72;
	/*		Enable I2C							*/
	SET_BIT(TWCR_REG, TWCR_TWEN);
	/*		Enable ACK							*/
	SET_BIT(TWCR_REG, TWCR_TWEA);
	/*		Assign the master Address			*/
	TWAR_REG = (MASTER_ADD<<1);

}

void I2C_voidSlaveInit(u8 Copy_u8SlaveAdd){

	/*		Enable I2C							*/
	SET_BIT(TWCR_REG, TWCR_TWEN);
	/*		Enable ACK							*/
	SET_BIT(TWCR_REG, TWCR_TWEA);
	/*		Assign the Slave Address			*/
	TWAR_REG = (Copy_u8SlaveAdd<<1);

}


I2C_Error I2C_enuSendStrCond(void){

	I2C_Error local_enuErr = I2C_NOK;
	/*         Clear Interrupt Flag            */
	SET_BIT(TWCR_REG, TWCR_TWINT);
	/*         Send Start Condition                 */
	SET_BIT(TWCR_REG, TWCR_TWSTA);
	/*         Wait for Flag                   */
	while(!GET_BIT(TWCR_REG, TWCR_TWINT));
	/*         Check for error                 */
	if((TWSR_REG & 0xF8) == START_COD_OK){
		local_enuErr = I2C_OK;
	}
	else{
		local_enuErr = START_COD_ERR;
	}
	return local_enuErr;

}

I2C_Error I2C_enuSendStopCond(void){

	u32 local_u32timeOut = 0;
	I2C_Error local_enuErr = I2C_NOK;
	/*         Clear Interrupt Flag            */
	SET_BIT(TWCR_REG, TWCR_TWINT);
	/*         Send Stop Condition             */
	SET_BIT(TWCR_REG, TWCR_TWSTO);
	/*         Wait for Flag                   */
	while(!GET_BIT(TWCR_REG, TWCR_TWINT) && local_u32timeOut<=1000000UL){
		 local_u32timeOut++;
	}
	/*         Check for error                 */
	if(local_u32timeOut>=1000000UL){
		local_enuErr = TIMEOUT_ERR;
	}
	else if((TWSR_REG & 0xF8) == STOP_COD_OK){
		local_enuErr = I2C_OK;
	}
	else{
		local_enuErr = STOP_COD_ERR;
	}
	return local_enuErr;
}

I2C_Error I2C_enuSendSlAWrite(u8 Copy_u8SlaveAdd){

	I2C_Error local_enuErr = I2C_NOK;
	/*         Put Address on Data Register    */
	TWDR_REG = (Copy_u8SlaveAdd<<1);

	/*         Clear Start Condition           */
	CLR_BIT(TWCR_REG, TWCR_TWSTA);

	/*         Clear Interrupt Flag            */
	SET_BIT(TWCR_REG, TWCR_TWINT);

	/*         Wait for Flag                   */
	while(!GET_BIT(TWCR_REG, TWCR_TWINT));

	/*         Check for error                 */
	if((TWSR_REG & 0xF8) == SLA_W_OK){
		local_enuErr = I2C_OK;
	}
	else{
		local_enuErr = SLA_W_ERR;
	}
	return local_enuErr;
}

I2C_Error I2C_enuSendSlARead(u8 Copy_u8SlaveAdd){

	I2C_Error local_enuErr = I2C_NOK;
	/*         Put Address on Data Register    */
	TWDR_REG = ((Copy_u8SlaveAdd<<1) | 0x01) ; //ORed with one for read

	/*         Clear Start Condition           */
	CLR_BIT(TWCR_REG, TWCR_TWSTA);

	/*         Clear Interrupt Flag            */
	SET_BIT(TWCR_REG, TWCR_TWINT);

	/*         Wait for Flag                   */
	while(!GET_BIT(TWCR_REG, TWCR_TWINT));

	/*         Check for error                 */
	if((TWSR_REG & 0xF8) == SLA_R_OK){
		local_enuErr = I2C_OK;
	}
	else{
		local_enuErr = SLA_R_ERR;
	}
	return local_enuErr;

}

I2C_Error I2C_enuSendDataMstr(u8 Copy_u8Data){

	I2C_Error local_enuErr = I2C_NOK;
	/*         Put Data on Data Register    */
	TWDR_REG = Copy_u8Data;

	/*         Clear Interrupt Flag         */
	SET_BIT(TWCR_REG, TWCR_TWINT);

	/*         Wait for Flag                */
	while(!GET_BIT(TWCR_REG, TWCR_TWINT));

	/*         Check for error              */
	if((TWSR_REG & 0xF8) == DATA_MSTR_S_OK){
		local_enuErr = I2C_OK;
	}
	else{
		local_enuErr = DATA_MSTR_S_ERR;
	}
	return local_enuErr;

}

I2C_Error I2C_enuReceiveDataMstr(u8 * Copy_u8Data){

	I2C_Error local_enuErr = I2C_NOK;
	/*         Clear Interrupt Flag            */
	SET_BIT(TWCR_REG, TWCR_TWINT);
	/*         Wait for Flag                   */
	while(!GET_BIT(TWCR_REG, TWCR_TWINT));
	/*         Check for error                 */
	if((TWSR_REG & 0xF8) == DATA_MSTR_R_OK){
		local_enuErr = I2C_OK;
		/*         Get Data from data Register     */
		*Copy_u8Data = TWDR_REG;
	}
	else{
		local_enuErr = DATA_MSTR_R_ERR;
	}
	return local_enuErr;
}

I2C_Error I2C_enuSendDataSl(u8 Copy_u8Data){

	I2C_Error local_enuErr = I2C_NOK;
	/*         Put Data on Data Register       */
	TWDR_REG = Copy_u8Data;
	/*         Clear Interrupt Flag            */
	SET_BIT(TWCR_REG, TWCR_TWINT);
	/*         Wait for Flag                   */
	while(!GET_BIT(TWCR_REG, TWCR_TWINT));
	/*         Check for error                 */
	if((TWSR_REG & 0xF8) == DATA_SL_S_OK){
		local_enuErr = I2C_OK;
	}
	else{
		local_enuErr = DATA_SL_S_ERR;
	}
	return local_enuErr;
}

I2C_Error I2C_enuReceiveDataSl(u8 * Copy_u8Data){

	I2C_Error local_enuErr = I2C_NOK;
	/*         Clear Interrupt Flag            */
	SET_BIT(TWCR_REG, TWCR_TWINT);
	/*         Wait for Flag                   */
	while(!GET_BIT(TWCR_REG, TWCR_TWINT));
	/*         Check for error                 */
	if((TWSR_REG & 0xF8) == DATA_SL_R_OK){
		local_enuErr = I2C_OK;
		/*         Get Data from data Register     */
		*Copy_u8Data = TWDR_REG;
	}
	else{
		local_enuErr = DATA_SL_R_ERR;
	}
	return local_enuErr;
}

