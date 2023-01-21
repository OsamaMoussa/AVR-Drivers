/*
 * SPI_Private.h
 *
 *  Created on: Nov 15, 2022
 *      Author: osama yassin
 */

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

/*** SPI Control Register ***/
#define SPCR_REG *((volatile u8*)(0x2D))
#define SPCR_SPR0 0
#define SPCR_SPR1 1
#define SPCR_CPHA 2
#define SPCR_CPOL 3
#define SPCR_MSTR 4
#define SPCR_DORD 5
#define SPCR_SPE  6
#define SPCR_SPIE 7

/*** SPI Status Register ***/
#define SPSR_REG *((volatile u8*)(0x2E))
#define SPSR_SPI2X 0
#define SPSR_WCOL  6
#define SPSR_SPIF  7

/*** SPI Data Register ***/
#define SPDR_REG *((volatile u8*)(0x2F))

/*** SPI Modes ***/
#define MASTER (0x00)
#define SLAVE  (0x01)

#endif /* SPI_PRIVATE_H_ */
