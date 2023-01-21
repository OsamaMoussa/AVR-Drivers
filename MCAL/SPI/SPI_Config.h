/*
 * SPI_Config.h
 *
 *  Created on: Nov 15, 2022
 *      Author: osama yassin
 */

#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

/*** PIN Configuration ***/
#define SPI_PORT PORTB_ID
#define MOSI     PIN5
#define MISO     PIN6
#define SS       PIN4
#define SCK      PIN7

/*** MODE Configuration ***/
/*MASTER
* SLAVE
*/
#define SPI_MODE MASTER

#endif /* SPI_CONFIG_H_ */
