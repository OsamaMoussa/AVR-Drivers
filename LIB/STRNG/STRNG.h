/*
 * STRNG.h
 *
 *  Created on: Jan 16, 2023
 *      Author: osama yassin
 */

#ifndef LIB_STRNG_STRNG_H_
#define LIB_STRNG_STRNG_H_

void STRNG_voidReverseString(u8* copy_Au8Str, u32 copy_u32StrLen);
u32 STRNG_u32IntToString(u32 copy_u8IntNumber, u8* copy_Au8Str);
void STRNG_voidFloatToString(f32 copy_f32floatNumber, u8* copy_Au8Str);

#endif /* LIB_STRNG_STRNG_H_ */
