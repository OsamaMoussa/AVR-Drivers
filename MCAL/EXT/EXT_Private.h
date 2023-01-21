/*
 * EXT_Private.h
 *
 *  Created on: Nov 7, 2022
 *      Author: osama yassin
 */

#ifndef EXT_PRIVATE_H_
#define EXT_PRIVATE_H_

/*** MCU Control Register ***/
#define MCUCR_REG  *((volatile u8*) (0x55))
#define MCUCR_ISC00 0x00
#define MCUCR_ISC01 0x01
#define MCUCR_ISC10 0x02
#define MCUCR_ISC11 0x03

/*** MCU Control and Status Register***/
#define MCUCSR_REG *((volatile u8*) (0x54))
#define MCUCSR_ISC2 0x06

/*** General Interrupt Control Register ***/
#define GICR_REG   *((volatile u8*) (0x5B))
#define GICR_INT2 0x05
#define GICR_INT0 0x06
#define GICR_INT1 0x07

/*** General Interrupt Flag Register ***/
#define GIFR_REG   *((volatile u8*) (0x5A))
#define GIFR_INT2 0x05
#define GIFR_INT0 0x06
#define GIFR_INT1 0x07

#endif /* EXT_PRIVATE_H_ */
