/*****************************************************************************************/
/*****************************************************************************************/
/***********************		AUTHOR	:	MOHAMED HARB		**************************/
/***********************		LAYER	:	APP					**************************/
/***********************		DES.	:	PING PONG PROJECT	**************************/
/***********************		DATE	:	2-11-2023			**************************/
/***********************		VERSION	:	V01					**************************/
/*****************************************************************************************/
/*****************************************************************************************/


#include "PingPong_interface.h"


// Main function
int main()
{
	WelcomeMessage();

	PindPong_voidInit();


	while(1)	// can add time out
	{
		PindPong_voidForward_Move();
		PindPong_voidBackward_Move();
	}

   // Quit the game
   return 0;
}

