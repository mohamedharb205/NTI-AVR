/*****************************************************************************************/
/*****************************************************************************************/
/***********************		AUTHOR	:	MOHAMED HARB		**************************/
/***********************		LAYER	:	HAL					**************************/
/***********************		SWC		:	LCD					**************************/
/***********************		DATE	:	OCT 20, 2023		**************************/
/***********************		VERSION	:	V01					**************************/
/*****************************************************************************************/
/*****************************************************************************************/

#ifndef HAL_LCD_LCD_PRIVATE_H_
#define HAL_LCD_LCD_PRIVATE_H_


#define 	LCD_FOUR_BIT_MODE			1
#define 	LCD_EIGHT_BIT_MODE			2

#define 	LCD_ENABLED					1
#define 	LCD_DISABLED				2


// LCD PORT for simulation in 8 bits mode
#define 	LCD_PORT					DIO_u8PORTB



/* 4-BITS MODE*/
#define 	FUNCTION_SET1				0b00100000	//0b0010XXXX
#define 	FUNCTION_SET2				0b00100000	//0b0010XXXX
#define 	FUNCTION_SET3				0b10000000	//0bNFXXXXXX

#define 	DISPLAY_ON_OFF_CONTROL1		0b00000000	//0b0000XXXX
#define 	DISPLAY_ON_OFF_CONTROL2		0b11000000	//0b1DCBXXXX

#define 	DISPLAY_CLEAR1				0b00000000	//0b0000XXXX
#define 	DISPLAY_CLEAR2				0b00010000	//0b0001XXXX

#define 	ENTRY_MODE_SET1				0b00000000	//0b0000XXXX
#define 	ENTRY_MODE_SET2				0b01100000	//0b0,1,I/D,SH,XXXX


/* 8-BITS MODE */
#define 	FUNCTION_SET				0b00111000	//0b0011NFXX

#define 	DISPLAY_ON_OFF_CONTROL		0b00001100	//0b00001DCB

#define 	DISPLAY_ON					0b00001100	//0b00001DCB
#define 	DISPLAY_OFF					0b00001000	//0b00001DCB
#define 	DISPLAY_CLEAR				0b00000001	//0b00000001

#define 	ENTRY_MODE_SET				0b00000110	//0b000001,I/D,SH


#define 	LCD_LINE_ONE				0
#define 	LCD_LINE_TWO				1
#define 	LCD_LINE_THREE				2
#define 	LCD_LINE_FOUR				3



void SET_voidLCDPinsDirection();
void Send_voidEnablePulse();
void Send_voidCommand(u8 Copy_u8Command);
void Send_voidData(u8 copy_u8Data);

////0x80, 0x0C, 0x94, 0xD4


#endif /* HAL_LCD_LCD_PRIVATE_H_ */
