/*
 * EXT_Interface.h
 *
 *  Created on: Nov 7, 2022
 *      Author: osama yassin
 */

#ifndef EXT_INTERFACE_H_
#define EXT_INTERFACE_H_

/*** Define External Interrupt Selection ***/
#define EXT_EI_NUM_TYPE u8
#define EXT0 ((u8)(0x00))
#define EXT1 ((u8)(0x01))
#define EXT2 ((u8)(0x02))

/*** Define External Interrupt Senses ***/
#define EXT_EI_SENSE_TYPE u8
#define FALLING_EDGE ((u8)(0x00))
#define RISNIG_EDGE  ((u8)(0x01))

/*** Functions ProtoTypes ***/
void EXT_voidInit(EXT_EI_NUM_TYPE copy_u8EiNum, EXT_EI_SENSE_TYPE copy_u8ControlSens);
void EXT_voidSetCallBack(EXT_EI_NUM_TYPE copy_u8EiNum, void(*Copy_ptf)(void));

#endif /* EXT_INTERFACE_H_ */
