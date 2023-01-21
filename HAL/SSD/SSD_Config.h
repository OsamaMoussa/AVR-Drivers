/*
 * SSD_Config.h
 *
 *  Created on: Dec 17, 2022
 *      Author: osama yassin
 */

#ifndef HAL_SSD_SSD_CONFIG_H_
#define HAL_SSD_SSD_CONFIG_H_

/*** Seven Segment Data Pins ***/
#define SSD_NUM_PORT  PORTB_ID
#define SSD_BIT0 PIN0
#define SSD_BIT1 PIN1
#define SSD_BIT2 PIN2
#define SSD_BIT3 PIN4

/*** Seven Segment COM1 Pin ***/
#define SSD_COM1_PORT PORTA_ID
#define SSD_COM1_PIN PIN3

/*** Seven Segment COM2 Pin ***/
#define SSD_COM2_PORT PORTA_ID
#define SSD_COM2_PIN PIN2

/*** Seven Segment COM3 Pin ***/
#define SSD_COM3_PORT PORTB_ID
#define SSD_COM3_PIN PIN5

/*** Seven Segment COM4 Pin ***/
#define SSD_COM4_PORT PORTB_ID
#define SSD_COM4_PIN PIN6

#endif /* HAL_SSD_SSD_CONFIG_H_ */
