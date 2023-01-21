/*
 * DIO_Interface.h
 *
 *  Created on: Nov 5, 2022
 *      Author: osama yassin
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/*** PORTS ***/
#define DIO_PORT_TYPE u8
#define PORTA_ID (u8)(0x00)
#define PORTB_ID (u8)(0x01)
#define PORTC_ID (u8)(0x02)
#define PORTD_ID (u8)(0x03)

/*** PINS ***/
#define DIO_PIN_TYPE u8
#define PIN0 (u8)(0x00)
#define PIN1 (u8)(0x01)
#define PIN2 (u8)(0x02)
#define PIN3 (u8)(0x03)
#define PIN4 (u8)(0x04)
#define PIN5 (u8)(0x05)
#define PIN6 (u8)(0x06)
#define PIN7 (u8)(0x07)

/*** PIN Direction ***/
#define DIO_PIN_DIR_TYPE u8
#define PIN_INPUT  (u8)(0x00)
#define PIN_OUTPUT (u8)(0x01)

/*** PIN level ***/
#define DIO_PIN_VAL_TYPE u8
#define PIN_LOW  (u8)(0x00)
#define PIN_HIGH (u8)(0x01)

/*** PORT Direction ***/
#define DIO_PORT_DIR_TYPE u8
#define PORT_INPUT  (u8)(0x00)
#define PORT_OUTPUT (u8)(0xFF)

/*** Functions ProtoTypes ***/
void DIO_voidSetPinDirection(DIO_PORT_TYPE Copy_u8PortID, DIO_PIN_TYPE Copy_u8PinID, DIO_PIN_DIR_TYPE Copy_u8PinDir);
void DIO_voidSetPinValue(DIO_PORT_TYPE Copy_u8PortID, DIO_PIN_TYPE Copy_u8PinID, DIO_PIN_VAL_TYPE Copy_u8PinVal);

void DIO_voidSetPortDirection(DIO_PORT_TYPE Copy_u8PortID, DIO_PORT_DIR_TYPE Copy_u8PortDir);
void DIO_voidSetPortValue(DIO_PORT_TYPE Copy_u8PortID, DIO_PIN_VAL_TYPE Copy_u8PortVal);

DIO_PIN_VAL_TYPE DIO_voidGetPinValue(DIO_PORT_TYPE Copy_u8PortID , DIO_PIN_TYPE Copy_PinID);
//void DIO_voidGetPinValue(DIO_PORT_TYPE Copy_u8PortID , DIO_PIN_TYPE Copy_PinID , DIO_PIN_VAL_TYPE *Copy_u8PinVal);

void DIO_voidToggelPin(DIO_PORT_TYPE Copy_u8PortID, DIO_PIN_TYPE Copy_u8PinID);

#endif /* DIO_INTERFACE_H_ */
