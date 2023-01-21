/*
 * TMR1_Private.h
 *
 *  Created on: Nov 14, 2022
 *      Author: osama yassin
 */

#ifndef TMR1_PRIVATE_H_
#define TMR1_PRIVATE_H_

/*** TCCR1A register ***/
#define TCCR1A_REG   *((volatile u8*)(0x4F))
#define TCCR1A_WGM10  (0x00)
#define TCCR1A_WGM11  (0x01)
#define TCCR1A_COM1A0 (0x06)
#define TCCR1A_COM1A1 (0x07)

/*** TCCR1B register ***/
#define TCCR1B_REG   *((volatile u8*)(0x4E))
#define TCCR1B_CS10  (0x00)
#define TCCR1B_CS11  (0x01)
#define TCCR1B_CS12  (0x02)
#define TCCR1B_WGM12 (0x03)
#define TCCR1B_WGM13 (0x04)

/*** TCNT1 register ***/
#define TCNT1_REG   *((volatile u16*)(0x4C))

/*** OCR1A register ***/
#define OCR1A_REG   *((volatile u16*)(0x4A))

/*** ICR1 register ***/
#define ICR1_REG    *((volatile u16*)(0x46))

/*** OC1A --> PD5 ***/
#define OC1A_PORT PORTD_ID
#define OC1A_PIN PIN5

#endif /* TMR1_PRIVATE_H_ */
