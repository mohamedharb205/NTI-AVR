/*****************************************************************************************/
/*****************************************************************************************/
/***********************		AUTHOR	:	MOHAMED HARB		**************************/
/***********************		LAYER	:	HAL					**************************/
/***********************		SWC		:	KEYPAD				**************************/
/***********************		DATE	:	OCT 21, 2023		**************************/
/***********************		VERSION	:	V01					**************************/
/*****************************************************************************************/
/*****************************************************************************************/



#ifndef HAL_KEYPAD_KEYPAD_CONFIG_H_
#define HAL_KEYPAD_KEYPAD_CONFIG_H_



/* KEYPAD PORTS */
#define 	KEYPAD_ROWS_PORT		DIO_u8PORTC
#define 	KEYPAD_COLS_PORT		DIO_u8PORTD

/* KEYPAD PINS */
#define 	KEYPAD_ROW1_PIN			DIO_u8PIN5
#define 	KEYPAD_ROW2_PIN			DIO_u8PIN4
#define 	KEYPAD_ROW3_PIN			DIO_u8PIN3
#define 	KEYPAD_ROW4_PIN			DIO_u8PIN2

#define 	KEYPAD_COL1_PIN			DIO_u8PIN7
#define 	KEYPAD_COL2_PIN			DIO_u8PIN6
#define 	KEYPAD_COL3_PIN			DIO_u8PIN5
#define 	KEYPAD_COL4_PIN			DIO_u8PIN3



#endif /* HAL_KEYPAD_KEYPAD_CONFIG_H_ */
