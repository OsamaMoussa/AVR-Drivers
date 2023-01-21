/*
 * GINT_Programe.c

 *
 *  Created on: Nov 7, 2022
 *      Author: osama yassin
 */

/**LIB***/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
/***GINT***/
#include "GINT_Interface.h"
#include "GINT_Private.h"
#include "GINT_Config.h"

void GINT_voidEnableGlobalInterupt(){
	SET_BIT(SREG_REG,SREG_I);
}

void GINT_voidDisableGlobalInterupt(){
	CLR_BIT(SREG_REG,SREG_I);
}

