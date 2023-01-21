#ifndef		LCD_INTERFACE_H
#define		LCD_INTERFACE_H

void LCD_voidInit(void);
void LCD_voidWriteData(u8 copy_u8data);
void LCD_voidWriteCommand(u8 copy_u8Command);
void LCD_voidWriteString(u8 * copy_str);
void LCD_voidWriteNum(u32 copy_u32Num);
void LCD_voidGoToXY(u8 copy_u8Row,u8 copy_u8Col);
void LCD_voidClear(void);

#endif
