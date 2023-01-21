/*
 * TIMER0_Private.h
 *
 *  Created on: Nov 12, 2022
 *      Author: osama yassin
 */

#ifndef TMR0_PRIVATE_H_
#define TMR0_PRIVATE_H_

/*** Timer/Counter Control Register ***/
#define TCCR0_REG *((volatile u8*)(0x53))
#define TCCR0_CS00  (0x00)
#define TCCR0_CS01  (0x01)
#define TCCR0_CS02  (0x02)
#define TCCR0_WGM01 (0x03)
#define TCCR0_COM00 (0x04)
#define TCCR0_COM01 (0x05)
#define TCCR0_WGM00 (0x06)
#define TCCR0_FOC0  (0x07)

/*** Timer/Counter Interrupt Mask Register ***/
#define TIMSK_REG *((volatile u8*)(0x59))
#define TIMSK_TOIE0 (0x00)
#define TIMSK_OCIE0 (0x01)

/**** Timer/Counter Interrupt Flag Register ****/
#define TIFR_REG *((volatile u8*)(0x58))
#define TIFR_TOV0 (0x00)
#define TIFR_OCF0 (0x01)

/**** Special Function IO Register ****/
#define SFIOR_REG *((volatile u8*)(0x50))
#define SFIOR_PSR10 (0x00) //(Prescaler Reset Timer/Counter1 and Timer/Counter0)

/**** Timer/Counter Register ****/
#define TCNT0_REG *((volatile u8*)(0x52))

/****Output Compare Register****/
#define OCR0_REG *((volatile u8*)(0x5C))


/**** (OC0 --> PB3) ****/
#define OC0_PORT PORTB_ID
#define OC0_PIN  PIN3

/***** Mode Options *****/
#define NORMAL_MODE (0x00)
#define PWM_MODE    (0x01)
#define CTC_MODE    (0x02)
#define FPWM_MODE   (0x03)

/**** Normal Mode OverFlow Ticks ****/
#define NORMAL_OVERFLOW_TICKS (256UL)

/**** PRESCALER Options ****/
#define PRESCALER_1    (1)
#define PRESCALER_8    (8)
#define PRESCALER_64   (64)
#define PRESCALER_256  (256)
#define PRESCALER_1024 (1024)
#define EXT_CLK_FE     (1)
#define EXT_CLK_RE     (1)

/**** Compare match Modes ****/
#define COM_OC0_DISCONNECTED (0x00)
#define COM_TOGGLE           (0x01)
#define COM_CLEAR            (0x02)
#define COM_SET              (0x03)

#endif /* TMR0_PRIVATE_H_ */
