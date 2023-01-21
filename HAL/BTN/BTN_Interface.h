/*
 * BTN_Interface.h
 *
 *  Created on: Nov 8, 2022
 *      Author: osama yassin
 */

#ifndef BTN_INTERFACE_H_
#define BTN_INTERFACE_H_

/*** Define Buttons IDs ***/
#define BTN_INT0_ID (0x00)
#define BTN_INT1_ID (0x01)
#define BTN_INT2_ID (0x02)

void BTN_voidInit();
u8 BTN_u8IsBtnPressed(u8 copy_u8BtnID);

#endif /* BTN_INTERFACE_H_ */
