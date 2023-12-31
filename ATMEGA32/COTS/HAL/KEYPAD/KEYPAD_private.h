/*****************************************************************************************/
/*****************************************************************************************/
/***********************		AUTHOR	:	MOHAMED HARB		**************************/
/***********************		LAYER	:	HAL					**************************/
/***********************		SWC		:	KEYPAD				**************************/
/***********************		DATE	:	OCT 21, 2023		**************************/
/***********************		VERSION	:	V01					**************************/
/*****************************************************************************************/
/*****************************************************************************************/

#ifndef HAL_KEYPAD_KEYPAD_PRIVATE_H_
#define HAL_KEYPAD_KEYPAD_PRIVATE_H_



#define 	ROWS_NUM				4
#define 	COLS_NUM				4


/* We can use a 4*4 double array */
static const u8 KeyPad_Char[16] = { '7', '8', '9', '/',
									'4', '5', '6', '*',
									'1', '2', '3', '-',
									'C', '0', '=', '+'};


u8 	 Read_u8Button(u8 Copy_u8Line);
void Select_voidLine(u8 Copy_u8Line);



#endif /* HAL_KEYPAD_KEYPAD_PRIVATE_H_ */
