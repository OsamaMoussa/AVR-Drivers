/*
 * main.c


 *
 *  Created on: Nov 5, 2022
 *      Author: osama yassin
 */

/****LIB****/
//#include "avr/delay.h"
#include "stdio.h"
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "LIB/STRNG/STRNG.h"
/****MCAL****/
#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/GINT/GINT_Interface.h"
#include "MCAL/ADC/ADC_Interface.h"
#include "MCAL/EXT/EXT_Interface.h"
#include "MCAL/TMR0/TMR0_Interface.h"
#include "MCAL/TMR1/TMR1_Interface.h"
#include "MCAL/I2C/I2C_Interface.h"
#include "MCAL/USART/USART_Interface.h"
#include "MCAL/SPI/SPI_Interface.h"
/****HAL****/
#include "HAL/BTN/BTN_Interface.h"
#include "HAL/LED/LED_Interface.h"
#include "HAL/LCD/LCD_Interface.h"
#include "HAL/SEVSEG/SEVSEG_Interface.h"
#include "HAL/SSD/SSD_Interface.h"
#include "HAL/KPD/KPD_Interface.h"
/****FREE_RTOS****/
#include "Free_RTOS/FreeRTOS.h"
#include "Free_RTOS/task.h"
#include "Free_RTOS/semphr.h"
/***System Frequency***/
#define F_CPU (16000000ULL)




int main(){
	/**** MCAL Initializations ****/

	/**** HAL Initializations ****/
	LCD_voidInit();

	/*** APP ***/


	while(1){

	}
}

