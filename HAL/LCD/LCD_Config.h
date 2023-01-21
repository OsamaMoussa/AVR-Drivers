#ifndef _LCD_CONFIG_H
#define _LCD_CONFIG_H

#define LCD_MODE  FOUR_BIT

/*** LCD Control PINS ***/
#define RS_PIN   PIN3
#define RS_PORT  PORTA_ID

#define EN_PIN   PIN2
#define EN_PORT  PORTA_ID

/*** LCD Data PINS ***/
#define D4_PIN    PIN0
#define D4_PORT   PORTB_ID

#define D5_PIN    PIN1
#define D5_PORT   PORTB_ID

#define D6_PIN    PIN2
#define D6_PORT   PORTB_ID

#define D7_PIN    PIN4
#define D7_PORT   PORTB_ID

/*** Enable delays ***/
#define EN_HIGH_DELAY (2)
#define EN_LOW_DELAY  (20)

/*** INIT ***/
#define FUNCTION_SET     FUNCTION_SET_4BIT_2LINES_5X7_DOTS
#define DISPLAY_SETTINGS DISPLAY_ON_CURSOR_OFF

/*** Maximum digits To be displayed ***/
#define MAX_STRING_SIZE 20

#endif
