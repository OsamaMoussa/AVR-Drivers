/*************************************************************************************
 *                                  Files Inclusion                                  *
 *************************************************************************************/

/* User Defined Library Files */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "util/delay.h"
#include "../../MCAL/DIO/DIO_Interface.h"

/* Module Header Files */
#include "KPD_Interface.h"
#include "KPD_Private.h"
#include "KPD_Config.h"

/*************************************************************************************
 *                             Static Objects Definition                             *
 *************************************************************************************/
static const u8 global_Au8ColsPins[] = {COL_1, COL_2, COL_3, COL_4};
static const u8 global_Au8RowsPins[] = {ROW_1, ROW_2, ROW_3, ROW_4};
static const u8 global_Au8SwitchVal[ROW_SIZE][COL_SIZE] =
{
		{1,  2,  3,  4  },
		{5,  6,  7,  8  },
		{9,  10, 11, 12 },
		{13, 14, 15, 16 }
};

/*************************************************************************************
 *                               Public Function Definition                          *
 *************************************************************************************/

void KPD_voidInit(void) {
	/* Set Rows as  Output */
	for (u8 local_u8PinID = 0; local_u8PinID < 4; local_u8PinID++){
		DIO_voidSetPinDirection(KPD_ROW_PORT, global_Au8RowsPins[local_u8PinID], PIN_OUTPUT);
	}

	/* Set Columns as Inputs & Pulled up */
	for (u8 local_u8PinID = 0; local_u8PinID < 4; local_u8PinID++){
		DIO_voidSetPinDirection(KPD_COL_PORT, global_Au8ColsPins[local_u8PinID], PIN_INPUT);
		DIO_voidSetPinValue(KPD_COL_PORT, global_Au8ColsPins[local_u8PinID], PIN_HIGH);
	}
}

u8 KPD_voidGetPressedKey(void)
{
	u8 local_u8ColID, local_u8RowID, local_u8PinVal;
	/* Initialize the switch status to NOT Pressed as a default value */
	u8 local_u8_PressedKey = KPD_NOT_PRESSED;

	/* Loop on the rows of the Key Pad */
	for (local_u8RowID = 0; local_u8RowID < 4; local_u8RowID++){
		/* Activate the All Columns in Current Row */
		DIO_voidSetPinValue(KPD_ROW_PORT, global_Au8RowsPins[local_u8RowID], PIN_LOW);

		/* Looping on columns of the Key Pad */
		for (local_u8ColID = 0; local_u8ColID < 4; local_u8ColID++){
			/* Check the status of the switch */
			local_u8PinVal = DIO_voidGetPinValue(KPD_COL_PORT, global_Au8ColsPins[local_u8ColID]);
			if (local_u8PinVal == 0){
				/* Get the value of the currently pressed switch */
				local_u8_PressedKey = global_Au8SwitchVal[local_u8RowID][local_u8ColID];

				/* Wait until the switch is released (Single Press) */
				while (local_u8PinVal == 0){
					local_u8PinVal = DIO_voidGetPinValue(KPD_COL_PORT, global_Au8ColsPins[local_u8ColID]);
				}
				_delay_ms(20); /* Delay to avoid bouncing */
				return local_u8_PressedKey; /* Returning the value */
			}
		}
		/* Deactivate the All Columns in Current Row */
		DIO_voidSetPinValue(KPD_ROW_PORT, global_Au8RowsPins[local_u8RowID], PIN_HIGH);
	}

	return local_u8_PressedKey; /* Returning the value */
}
