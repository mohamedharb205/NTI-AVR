/*****************************************************************************************/
/*****************************************************************************************/
/***********************		AUTHOR	:	MOHAMED HARB		**************************/
/***********************		LAYER	:	HAL					**************************/
/***********************		SWC		:	KEYPAD				**************************/
/***********************		DATE	:	OCT 21, 2023		**************************/
/***********************		VERSION	:	V01					**************************/
/*****************************************************************************************/
/*****************************************************************************************/


#include "STD_TYPES.h"


#ifndef HAL_KEYPAD_KEYPAD_INTERFACE_H_
#define HAL_KEYPAD_KEYPAD_INTERFACE_H_



#define 	KEYPAD_NOT_PRESSED		255		//0xFF	// '\0' - 255	- 	255; don't put ; because it cause an error that can not be defined


/* Function PROTOTYPES */
void KeyPad_voidInit(void);
u8 	 KeyPad_u8GetPress(void);


#endif /* HAL_KEYPAD_KEYPAD_INTERFACE_H_ */
