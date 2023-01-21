
/***LIB***/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "util/delay.h"
/***MCAL***/
#include "../../MCAL/DIO/DIO_Interface.h"
/***LCD***/
#include "LCD_Interface.h"
#include "LCD_private.h"
#include "LCD_Config.h"


static u8  global_string[MAX_STRING_SIZE]={0};
static u8* global_StringData=NULL_PTR;

static void LCD_voidWriteBitsToSend(u8 copy_u8Byte){

	DIO_voidSetPinValue(EN_PORT,EN_PIN, PIN_LOW);

	DIO_voidSetPinValue(D7_PORT,D7_PIN, GET_BIT(copy_u8Byte,PIN7));
	DIO_voidSetPinValue(D6_PORT,D6_PIN, GET_BIT(copy_u8Byte,PIN6));
	DIO_voidSetPinValue(D5_PORT,D5_PIN, GET_BIT(copy_u8Byte,PIN5));
	DIO_voidSetPinValue(D4_PORT,D4_PIN, GET_BIT(copy_u8Byte,PIN4));
	DIO_voidSetPinValue(EN_PORT,EN_PIN, PIN_HIGH);
	_delay_ms(EN_HIGH_DELAY);
	DIO_voidSetPinValue(EN_PORT,EN_PIN, PIN_LOW);
	_delay_ms(EN_LOW_DELAY);

	DIO_voidSetPinValue(D7_PORT,D7_PIN, GET_BIT(copy_u8Byte,PIN3));
	DIO_voidSetPinValue(D6_PORT,D6_PIN, GET_BIT(copy_u8Byte,PIN2));
	DIO_voidSetPinValue(D5_PORT,D5_PIN, GET_BIT(copy_u8Byte,PIN1));
	DIO_voidSetPinValue(D4_PORT,D4_PIN, GET_BIT(copy_u8Byte,PIN0));
	DIO_voidSetPinValue(EN_PORT,EN_PIN, PIN_HIGH);
	_delay_ms(EN_HIGH_DELAY);
	DIO_voidSetPinValue(EN_PORT,EN_PIN, PIN_LOW);
	_delay_ms(EN_LOW_DELAY);
}


void LCD_voidInit(void){
	/***I/O settings***/
	DIO_voidSetPinDirection(RS_PORT,RS_PIN,PIN_OUTPUT);
	DIO_voidSetPinDirection(EN_PORT, EN_PIN,PIN_OUTPUT);
	DIO_voidSetPinDirection(D4_PORT,D4_PIN,PIN_OUTPUT);
	DIO_voidSetPinDirection(D5_PORT,D5_PIN,PIN_OUTPUT);
	DIO_voidSetPinDirection(D6_PORT,D6_PIN,PIN_OUTPUT);
	DIO_voidSetPinDirection(D7_PORT,D7_PIN,PIN_OUTPUT);

    /***LCD Init***/
	_delay_ms(30);
	LCD_voidWriteCommand(LCD_INIT_CMD);
	_delay_ms(2);
	LCD_voidWriteCommand(FUNCTION_SET);
	_delay_ms(2);
	LCD_voidWriteCommand(DISPLAY_SETTINGS);
	_delay_ms(2);
	LCD_voidWriteCommand(DISPLAY_CLEAR);
	_delay_ms(2);
	LCD_voidWriteCommand(ENTRY_MODE_SET);
	_delay_ms(2);
	LCD_voidWriteCommand(DISPLAY_CLEAR);
	_delay_ms(2);
}

void LCD_voidWriteData(u8 copy_u8data){
	DIO_voidSetPinValue(RS_PORT, RS_PIN, RS_DATA_VAL);
	LCD_voidWriteBitsToSend(copy_u8data);
}

void LCD_voidWriteCommand(u8 copy_u8Command){
	DIO_voidSetPinValue(RS_PORT, RS_PIN, RS_CMD_VAL);
	LCD_voidWriteBitsToSend(copy_u8Command);
}

void LCD_voidWriteString(u8 * copy_str){
	u32 i= 0;
	while(copy_str[i] != '\0'){
		LCD_voidWriteData(copy_str[i]);
		i++;
	}
}

void LCD_voidWriteNum(u32 copy_u32Num){
	u32 i;
	global_string[MAX_STRING_SIZE-1]='\0';
	for(i=MAX_STRING_SIZE-1; copy_u32Num!=0 ; copy_u32Num/=10){
		global_string[--i]= (u8)((copy_u32Num%10) + 48); // '0' = 48 (Ascii Code)
	}
	global_StringData = (&global_string[i]);
	LCD_voidWriteString((u8*)global_StringData);
}

void LCD_voidGoToXY(u8 copy_u8row,u8 copy_u8col){

	u8 local_address ;
	switch(copy_u8row){
		case 0 : local_address = copy_u8col ;
		break ;

		case 1 : local_address = copy_u8col+0x40 ;
		break ;
	}
	LCD_voidWriteCommand(local_address+SET_DDRAM_ADDRESS);

}

void LCD_voidClear(void){
	LCD_voidWriteCommand(DISPLAY_CLEAR);
}



