/*
 * I2C_Private.h
 *
 *  Created on: Nov 19, 2022
 *      Author: osama yassin
 */

#ifndef I2C_PRIVATE_H_
#define I2C_PRIVATE_H_

/*  Bit Rate Register  */
#define TWBR_REG *((volatile u8*)(0x20))

/*  Control Register  */
#define TWCR_REG *((volatile u8*)(0x56))
#define TWCR_TWIE  (0x00)
#define TWCR_TWEN  (0x02)
#define TWCR_TWWC  (0x03)
#define TWCR_TWSTO (0x04)
#define TWCR_TWSTA (0x05)
#define TWCR_TWEA  (0x06)
#define TWCR_TWINT (0x07)

/*  Status Register  */
#define TWSR_REG *((volatile u8*)(0x21))
#define TWSR_TWPS0 (0x00)
#define TWSR_TWPS1 (0x01)

/*  Data Register  */
#define TWDR_REG *((volatile u8*)(0x23))

/*  Address Register  */
#define TWAR_REG *((volatile u8*)(0x22))
#define TWAR_TWGC (0x00)

/* Status */
#define START_COD_OK   (0x08)
#define STOP_COD_OK    (0xA0)
#define SLA_W_OK       (0x18)
#define SLA_R_OK       (0x40)
#define DATA_MSTR_S_OK (0x28)
#define DATA_MSTR_R_OK (0x50)
#define DATA_SL_S_OK   (0xB8)
#define DATA_SL_R_OK   (0x80)


#endif /* I2C_PRIVATE_H_ */
