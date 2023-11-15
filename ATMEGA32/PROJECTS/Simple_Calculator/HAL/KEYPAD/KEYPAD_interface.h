/*****************************************************************************************/
/*****************************************************************************************/
/***********************		AUTHOR	:	MOHAMED HARB		**************************/
/***********************		LAYER	:	HAL					**************************/
/***********************		SWC		:	KEYPAD				**************************/
/***********************		DATE	:	OCT 21, 2023		**************************/
/***********************		VERSION	:	V01					**************************/
/*****************************************************************************************/
/*****************************************************************************************/


#include "../../LIB/STD_TYPES.h"


#ifndef HAL_KEYPAD_KEYPAD_INTERFACE_H_
#define HAL_KEYPAD_KEYPAD_INTERFACE_H_

	/*Function Deceleration */

	void KeyPad_voidInit(void);
	u8 	 KeyPad_u8GetPress(void);

#endif /* HAL_KEYPAD_KEYPAD_INTERFACE_H_ */
