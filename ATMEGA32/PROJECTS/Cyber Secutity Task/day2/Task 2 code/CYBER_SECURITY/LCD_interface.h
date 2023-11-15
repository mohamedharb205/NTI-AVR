/*****************************************************************************************/
/*****************************************************************************************/
/***********************		AUTHOR	:	MOHAMED HARB		**************************/
/***********************		LAYER	:	HAL					**************************/
/***********************		SWC		:	LCD					**************************/
/***********************		DATE	:	OCT 20, 2023		**************************/
/***********************		VERSION	:	V01					**************************/
/*****************************************************************************************/
/*****************************************************************************************/


#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_


/*Function Deceleration */
void LCD_voidInit(void);

void LCD_voidWriteCharacter(u8 copy_u8Character);
void LCD_voidWriteCharacterAtXY(u8 copy_u8Character, u8 copy_u8YPos , u8 copy_u8XPos);

void LCD_voidWriteString(u8* copy_pu8String);
void LCD_voidWriteStringAtXY(u8* copy_pu8String, u8 copy_u8YPos , u8 copy_u8XPos);

void LCD_voidGoToXY(u8 copy_u8YPos , u8 copy_u8XPos);

void LCD_voidWriteDecimal(s32 copy_s32Number);
void LCD_voidWriteFloat(f32 copy_f32Number);

void LCD_voidWriteCustomCharacter(u8 copy_u8PatternNumber, u8 copy_pu8PatternArr[], u8 copy_u8YPos, u8 copy_u8XPos);

void LCD_voidClear();
void LCD_voidClearLine(u8 copy_u8Ypos , u8 copy_u8Xpos);
void LCD_voidClearXY(u8 copy_u8Ypos , u8 copy_u8Xpos);


void LCD_voidDisplayOFF();
void LCD_voidDisplayON();


#endif /* HAL_LCD_LCD_INTERFACE_H_ */
