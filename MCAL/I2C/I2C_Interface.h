/*
 * I2C_Interface.h
 *
 *  Created on: Nov 19, 2022
 *      Author: osama yassin
 */

#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

/*** I2C Errors ****/
typedef enum{
	I2C_OK,
	I2C_NOK,
	START_COD_ERR,
	STOP_COD_ERR,
	SLA_W_ERR,
	SLA_R_ERR,
	DATA_MSTR_S_ERR,
	DATA_MSTR_R_ERR,
	DATA_SL_S_ERR,
	DATA_SL_R_ERR,
	TIMEOUT_ERR
}I2C_Error;

/*** Functions ProtoTypes ***/
void I2C_voidMastrInit(void);
void I2C_voidSlaveInit(u8 Copy_u8SlaveAdd);

I2C_Error I2C_enuSendStrCond(void);
I2C_Error I2C_enuSendStopCond(void);

I2C_Error I2C_enuSendSlAWrite(u8 Copy_u8SlaveAdd);
I2C_Error I2C_enuSendSlARead(u8 Copy_u8SlaveAdd);

I2C_Error I2C_enuSendDataMstr(u8 Copy_u8Data);
I2C_Error I2C_enuReceiveDataMstr(u8 * Copy_u8Data);

I2C_Error I2C_enuSendDataSl(u8 Copy_u8Data);
I2C_Error I2C_enuReceiveDataSl(u8 * Copy_u8Data);

#endif /* I2C_INTERFACE_H_ */
