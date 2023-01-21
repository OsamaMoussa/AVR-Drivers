/*
 * TIMER0_Interface.h
 *
 *  Created on: Nov 12, 2022
 *      Author: osama yassin
 */

#ifndef TMR0_INTERFACE_H_
#define TMR0_INTERFACE_H_

/*** Functions ProtoTypes ***/
void TMR0_voidInit(void);
void TMR0_voidStart(void);
void TMR0_voidStop(void);
void TMR0_voidSetCallBack(void(*copy_Ptf)(void), u16 copy_u16WaitTime);
void TMR0_voidGeneratePWM(u8 copy_u8DutyCycle);

#endif /* TMR0_INTERFACE_H_ */
