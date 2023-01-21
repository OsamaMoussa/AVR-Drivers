#ifndef _STD_TYPES_H_
#define _STD_TYPES_H_

/*
 * unSigned Data Types
 */
typedef unsigned char           u8;
typedef unsigned short int      u16;
typedef unsigned long int       u32;
typedef unsigned long long int  u64;

/*
 * signed Data Types
 */
typedef signed char             s8;
typedef signed short int        s16;
typedef signed long int         s32;
typedef signed long long int    s64;

/*
 * Floating point Types
 */
typedef float                   f32;
typedef double                  f64;

/*
 * NULL Pointer
 */
#define NULL_PTR ((void *) 0x00)

/*
 * Standard LOW, HIGH
 */
#define STD_LOW  ((u8)(0x00))
#define STD_HIGH ((u8)(0x01))

/*
 * Standard FALSE, TRUE
 */
#define STD_FALSE  ((u8)(0x00))
#define STD_TRUE   ((u8)(0x01))

#endif /* _STD_TYPES_H */
