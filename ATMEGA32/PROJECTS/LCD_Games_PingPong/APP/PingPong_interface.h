/*****************************************************************************************/
/*****************************************************************************************/
/***********************		AUTHOR	:	MOHAMED HARB		**************************/
/***********************		LAYER	:	APP					**************************/
/***********************		DES.	:	PING PONG PROJECT	**************************/
/***********************		DATE	:	2-11-2023			**************************/
/***********************		VERSION	:	V01					**************************/
/*****************************************************************************************/
/*****************************************************************************************/

#include "../LIB/STD_TYPES.h"


#ifndef APP_PINGPONG_INTERFACE_H_
#define APP_PINGPONG_INTERFACE_H_


	void WelcomeMessage();
	void PindPong_voidInit();

	void DrawBallAtXY(u8 copy_u8YPos , u8 copy_u8XPos);
	void ClearXY(u8 copy_u8YPos , u8 copy_u8XPos);

	void DrawLeftPaddleAtXY(u8 copy_u8YPos , u8 copy_u8XPos);
	void DrawRightPaddleAtXY(u8 copy_u8YPos , u8 copy_u8XPos);

	void Update_Score();
	void UpdatePaddles();

	void PindPong_voidForward_Move();
	void PindPong_voidBackward_Move();

	void Harb_Celebrate();
	void Khaled_Celebrate();

#endif /* APP_PINGPONG_INTERFACE_H_ */
