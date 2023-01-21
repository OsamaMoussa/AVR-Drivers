/*
 * STRNG.c
 *
 *  Created on: Jan 16, 2023
 *      Author: osama yassin
 */


/****LIB****/
#include "../STD_TYPES.h"
#include "../BIT_MATH.h"

/***STRNG***/
#include "STRNG.h"


void STRNG_voidReverseString(u8* copy_Au8Str, u32 copy_u32StrLen){
	u32 i = 0;
	u32 j = copy_u32StrLen - 1;
	u8 temp;

	 while (i < j){
	        temp = copy_Au8Str[i];
	        copy_Au8Str[i] = copy_Au8Str[j];
	        copy_Au8Str[j] = temp;
	        i++;
	        j--;
	    }
}

u32 STRNG_u32IntToString(u32 copy_u8IntNumber, u8* copy_Au8Str){
	u32 i = 0;
	while(copy_u8IntNumber){
		copy_Au8Str[i++] = copy_u8IntNumber%10 + '0';
		copy_u8IntNumber/=10;
	}

	STRNG_voidReverseString(copy_Au8Str, i);
	copy_Au8Str[i] = '\0';
	return i;
}

void STRNG_voidFloatToString(f32 copy_f32floatNumber, u8* copy_Au8Str){
	/*Extract Integer Part*/
	u32 local_u32IntPart = (u32)copy_f32floatNumber;
	/*Extract float Part*/
	f32 local_f32FloatPart = 100*(copy_f32floatNumber - (f32)local_u32IntPart);
	/*Convert integer part to string*/
	u32 i = STRNG_u32IntToString(local_u32IntPart, copy_Au8Str);
	/* Add a Dot */
	copy_Au8Str[i]='.';
	/*Convert float Part*/
	STRNG_u32IntToString((u32)local_f32FloatPart, copy_Au8Str+i+1);
}
