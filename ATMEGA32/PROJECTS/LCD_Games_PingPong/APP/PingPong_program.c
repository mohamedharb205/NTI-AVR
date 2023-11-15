/*****************************************************************************************/
/*****************************************************************************************/
/***********************		AUTHOR	:	MOHAMED HARB		**************************/
/***********************		LAYER	:	APP					**************************/
/***********************		DES.	:	PING PONG PROJECT	**************************/
/***********************		DATE	:	2-11-2023			**************************/
/***********************		VERSION	:	V01					**************************/
/*****************************************************************************************/
/*****************************************************************************************/


#ifndef F_CPU
#define F_CPU	8000000
#endif


#include "../LIB/STD_TYPES.h"

#include "../HAL/LCD/LCD_config.h"
#include "../HAL/LCD/LCD_interface.h"
#include "../HAL/LCD/LCD_private.h"

#include "../MCAL/DIO/DIO_interface.h"

#include "PingPong_interface.h"

#include <util/delay.h>




// Define the Port for the push buttons
#define 	PING_PONG_PORT		DIO_u8PORTC

// Define the pin numbers for the push buttons
#define 	PADDLE_1_UP 		DIO_u8PIN0
#define 	PADDLE_1_DOWN	 	DIO_u8PIN1
#define 	PADDLE_2_UP 		DIO_u8PIN2
#define 	PADDLE_2_DOWN	 	DIO_u8PIN3

// Define the player names
#define 	PLAYER1				"HARB"
#define 	PLAYER2				"KHALED"

// Define the game parameters
#define 	SCREEN_WIDTH 		20 		// The width of the LCD screen
#define 	SCREEN_HEIGHT 		4 		// The height of the LCD screen

#define 	PADDLE1_X 			0
#define 	PADDLE2_X 			19


// Global variables
volatile u8 PLAYER1_Score = 0;	 	// The score of player 1
volatile u8 PLAYER2_Score = 0; 		// The score of player 2

volatile u8 Paddle1_y = 2; 			// The y-coordinate of paddle 1 old
volatile u8 Paddle2_y = 2; 			// The y-coordinate of paddle 2 old


/*Custom Character of Ball*/
u8 Ball[] = { 0x00, 0x0E, 0x1F, 0x1F, 0x1F, 0x0E, 0x00, 0x00 };

/*Custom Character of Paddles*/
u8 Left_Paddle[] = { 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x00 };
u8 Right_Paddle[] = { 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x00 };

u8 Harb[] = { 0x04, 0x0A, 0x04, 0x0E, 0x15, 0x04, 0x0A, 0x00 };
u8 Harb1[] = { 0x04, 0x0A, 0x15, 0x0E, 0x04, 0x04, 0x0A, 0x00 };
u8 Harb2[] = { 0x04, 0x0A, 0x05, 0x0E, 0x14, 0x04, 0x0A, 0x00 };
u8 Harb3[] = { 0x04, 0x0A, 0x14, 0x0E, 0x05, 0x04, 0x0A, 0x00 };

u8 Khaled[] = { 0x0E, 0x0E, 0x04, 0x0E, 0x15, 0x04, 0x0E, 0x00 };
u8 Khaled1[] = { 0x0E, 0x0E, 0x15, 0x0E, 0x04, 0x04, 0x0E, 0x00 };
u8 Khaled2[] = { 0x0E, 0x0E, 0x05, 0x0E, 0x14, 0x04, 0x0E, 0x00 };
u8 Khaled3[] = { 0x0E, 0x0E, 0x14, 0x0E, 0x05, 0x04, 0x0E, 0x00 };


u8 Ball_Direction_Flag = 0;		// By default from right to left



void WelcomeMessage()
{

	// Initialize the LCD
	LCD_voidInit();

	LCD_voidGoToXY(0,1);
	LCD_voidWriteString("Hello Everybody");
	LCD_voidGoToXY(1,0);
	LCD_voidWriteString("This is a Ping Pong");
	LCD_voidGoToXY(2,1);
	LCD_voidWriteString("Match between:");
	LCD_voidGoToXY(3,1);
	LCD_voidWriteString("------------------");
	_delay_ms(1000);
	LCD_voidClear();

	LCD_voidGoToXY(0,3);
	LCD_voidWriteString("Harb");
	LCD_voidWriteCustomCharacter(3, Harb, 0, 14);
	LCD_voidGoToXY(2,3);
	LCD_voidWriteString("Khaled");
	LCD_voidWriteCustomCharacter(4, Khaled, 2, 14);
	_delay_ms(1500);
	LCD_voidClear();


}
void PindPong_voidInit()
{
	/*Push Buttons Directions*/
	DIO_voidSetPinDirection(PING_PONG_PORT, PADDLE_1_UP 	, DIO_u8PIN_INPUT);
	DIO_voidSetPinDirection(PING_PONG_PORT, PADDLE_1_DOWN  	, DIO_u8PIN_INPUT);
	DIO_voidSetPinDirection(PING_PONG_PORT, PADDLE_2_UP 	, DIO_u8PIN_INPUT);
	DIO_voidSetPinDirection(PING_PONG_PORT, PADDLE_2_DOWN  	, DIO_u8PIN_INPUT);

	// Display the player scores
	LCD_voidGoToXY(0,0);
	LCD_voidWriteString("Harb: ");
	LCD_voidWriteDecimal(PLAYER1_Score);

	LCD_voidGoToXY(0, 11);
	LCD_voidWriteString("Khaled: ");
	LCD_voidWriteDecimal(PLAYER2_Score);


	DrawLeftPaddleAtXY(Paddle1_y,0);
	DrawRightPaddleAtXY(Paddle2_y,19);
	DrawBallAtXY(1,0);
	_delay_ms(100);
	ClearXY(1,0);
}

// Function to draw the ball on a specific position on the LCD
void DrawBallAtXY(u8 copy_u8YPos , u8 copy_u8XPos)
{
    // Draw the ball at its new position
	LCD_voidWriteCustomCharacter(0, Ball, copy_u8YPos, copy_u8XPos);
}

// Function to clear a specific position on the LCD
void ClearXY(u8 copy_u8YPos , u8 copy_u8XPos)
{
    // Clear the previous position
	LCD_voidGoToXY(copy_u8YPos, copy_u8XPos);
	LCD_voidWriteCharacter(' ');
}

void DrawLeftPaddleAtXY(u8 copy_u8YPos , u8 copy_u8XPos)
{
    // Draw the the left paddle at its new position
	LCD_voidWriteCustomCharacter(1, Left_Paddle, copy_u8YPos, copy_u8XPos);
}

void DrawRightPaddleAtXY(u8 copy_u8YPos , u8 copy_u8XPos)
{
    // Draw the right paddle at its new position
	LCD_voidWriteCustomCharacter(2, Right_Paddle, copy_u8YPos, copy_u8XPos);
}



void Update_Score()
{
	// Clear the old Scores
	LCD_voidGoToXY(0, 6);
	LCD_voidWriteCharacter(' ');

	LCD_voidGoToXY(0, 19);
	LCD_voidWriteCharacter(' ');

	/* Update the new Scores */
	LCD_voidGoToXY(0, 6);
	LCD_voidWriteDecimal(PLAYER1_Score);

	LCD_voidGoToXY(0, 19);
	LCD_voidWriteDecimal(PLAYER2_Score);
}



void UpdatePaddles()
{
	if (DIO_u8GetPinValue(PING_PONG_PORT, PADDLE_1_UP) == 0)
	{
		if(Paddle1_y > 1)
		{
			ClearXY(Paddle1_y, 0);

			Paddle1_y --;
			DrawLeftPaddleAtXY(Paddle1_y, 0);
		}
	}
	else if (DIO_u8GetPinValue(PING_PONG_PORT, PADDLE_1_DOWN) == 0)
	{
		if(Paddle1_y < 3)
		{
			ClearXY(Paddle1_y, 0);

			Paddle1_y ++;
			DrawLeftPaddleAtXY(Paddle1_y, 0);
		}
	}
	else if (DIO_u8GetPinValue(PING_PONG_PORT, PADDLE_2_UP) == 0)
	{
		if(Paddle2_y > 1)
		{
			ClearXY(Paddle2_y, 19);

			Paddle2_y --;
			DrawLeftPaddleAtXY(Paddle2_y, 19);
		}
	}
	else if (DIO_u8GetPinValue(PING_PONG_PORT, PADDLE_2_DOWN) == 0)
	{
		if(Paddle2_y < 3)
		{
			ClearXY(Paddle2_y, 19);

			Paddle2_y ++;
			DrawLeftPaddleAtXY(Paddle2_y, 19);
		}
	}
}



void PindPong_voidForward_Move()
{
	UpdatePaddles();
	DrawLeftPaddleAtXY(Paddle1_y,0);
	DrawRightPaddleAtXY(Paddle2_y,19);
	DrawBallAtXY(3,4);
	_delay_ms(100);

	ClearXY(3,4);
	UpdatePaddles();
	DrawLeftPaddleAtXY(Paddle1_y,0);
	DrawRightPaddleAtXY(Paddle2_y,19);
	DrawBallAtXY(1,7);
	_delay_ms(100);

	ClearXY(1,7);
	UpdatePaddles();
	DrawLeftPaddleAtXY(Paddle1_y,0);
	DrawRightPaddleAtXY(Paddle2_y,19);
	DrawBallAtXY(3,10);
	_delay_ms(100);

	ClearXY(3,10);
	UpdatePaddles();
	DrawLeftPaddleAtXY(Paddle1_y,0);
	DrawRightPaddleAtXY(Paddle2_y,19);
	DrawBallAtXY(1,13);
	_delay_ms(100);

	ClearXY(1,13);
	UpdatePaddles();
	DrawLeftPaddleAtXY(Paddle1_y,0);
	DrawRightPaddleAtXY(Paddle2_y,19);
	DrawBallAtXY(3,16);
	_delay_ms(100);

	ClearXY(3,16);
	UpdatePaddles();
	DrawLeftPaddleAtXY(Paddle1_y,0);
	DrawRightPaddleAtXY(Paddle2_y,19);
	if(Paddle2_y != 1)
	{
		DrawBallAtXY(1,19);
		PLAYER1_Score ++;
		Update_Score();
		_delay_ms(100);

		if(PLAYER1_Score == 3)
		{
			Harb_Celebrate();
			exit(0);
		}

		ClearXY(1,19);

	}
	else
	{
		DrawBallAtXY(1,18);
		_delay_ms(100);
		ClearXY(1,18);
	}
}


void PindPong_voidBackward_Move()
{
	UpdatePaddles();
	DrawLeftPaddleAtXY(Paddle1_y,0);
	DrawRightPaddleAtXY(Paddle2_y,19);
	DrawBallAtXY(3,16);
	_delay_ms(100);

	ClearXY(3,16);
	UpdatePaddles();
	DrawLeftPaddleAtXY(Paddle1_y,0);
	DrawRightPaddleAtXY(Paddle2_y,19);
	DrawBallAtXY(1,13);
	_delay_ms(100);

	ClearXY(1,13);
	UpdatePaddles();
	DrawLeftPaddleAtXY(Paddle1_y,0);
	DrawRightPaddleAtXY(Paddle2_y,19);
	DrawBallAtXY(3,10);
	_delay_ms(100);

	ClearXY(3,10);
	UpdatePaddles();
	DrawLeftPaddleAtXY(Paddle1_y,0);
	DrawRightPaddleAtXY(Paddle2_y,19);
	DrawBallAtXY(1,7);
	_delay_ms(100);

	ClearXY(1,7);
	UpdatePaddles();
	DrawLeftPaddleAtXY(Paddle1_y,0);
	DrawRightPaddleAtXY(Paddle2_y,19);
	DrawBallAtXY(3,4);
	_delay_ms(100);

	ClearXY(3,4);
	UpdatePaddles();
	DrawLeftPaddleAtXY(Paddle1_y,0);
	DrawRightPaddleAtXY(Paddle2_y,19);
	if(Paddle1_y != 1)
	{
		DrawBallAtXY(1,0);
		PLAYER2_Score ++;
		Update_Score();
		_delay_ms(100);

		if(PLAYER2_Score == 3)
		{
			Khaled_Celebrate();
			exit(0);
		}
		ClearXY(1,0);

	}
	else
	{
		DrawBallAtXY(1,1);
		_delay_ms(100);
		ClearXY(1,1);
	}
}



void Harb_Celebrate()
{
	LCD_voidClear();
	LCD_voidGoToXY(1,3);

	LCD_voidWriteString("Harb wins !!!");
	LCD_voidWriteCustomCharacter(3, Harb, 2, 8);
	LCD_voidWriteCustomCharacter(3, Harb, 2, 9);
	LCD_voidWriteCustomCharacter(3, Harb, 2, 10);

	LCD_voidWriteCustomCharacter(3, Harb1, 2, 8);
	LCD_voidWriteCustomCharacter(3, Harb1, 2, 9);
	LCD_voidWriteCustomCharacter(3, Harb1, 2, 10);

	LCD_voidWriteCustomCharacter(3, Harb2, 2, 8);
	LCD_voidWriteCustomCharacter(3, Harb2, 2, 9);
	LCD_voidWriteCustomCharacter(3, Harb2, 2, 10);

	LCD_voidWriteCustomCharacter(3, Harb3, 2, 8);
	LCD_voidWriteCustomCharacter(3, Harb3, 2, 9);
	LCD_voidWriteCustomCharacter(3, Harb3, 2, 10);

	/*Repeat -----------------------------------------*/
	LCD_voidWriteCustomCharacter(3, Harb, 2, 8);
	LCD_voidWriteCustomCharacter(3, Harb, 2, 9);
	LCD_voidWriteCustomCharacter(3, Harb, 2, 10);

	LCD_voidWriteCustomCharacter(3, Harb1, 2, 8);
	LCD_voidWriteCustomCharacter(3, Harb1, 2, 9);
	LCD_voidWriteCustomCharacter(3, Harb1, 2, 10);

	LCD_voidWriteCustomCharacter(3, Harb2, 2, 8);
	LCD_voidWriteCustomCharacter(3, Harb2, 2, 9);
	LCD_voidWriteCustomCharacter(3, Harb2, 2, 10);

	LCD_voidWriteCustomCharacter(3, Harb3, 2, 8);
	LCD_voidWriteCustomCharacter(3, Harb3, 2, 9);
	LCD_voidWriteCustomCharacter(3, Harb3, 2, 10);

	_delay_ms(500);
}

void Khaled_Celebrate()
{
	LCD_voidClear();
	LCD_voidGoToXY(1,3);

	LCD_voidWriteString("Khaled wins !!!");
	LCD_voidWriteCustomCharacter(4, Khaled, 2, 8);
	LCD_voidWriteCustomCharacter(4, Khaled, 2, 9);
	LCD_voidWriteCustomCharacter(4, Khaled, 2, 10);

	LCD_voidWriteCustomCharacter(4, Khaled1, 2, 8);
	LCD_voidWriteCustomCharacter(4, Khaled1, 2, 9);
	LCD_voidWriteCustomCharacter(4, Khaled1, 2, 10);

	LCD_voidWriteCustomCharacter(4, Khaled2, 2, 8);
	LCD_voidWriteCustomCharacter(4, Khaled2, 2, 9);
	LCD_voidWriteCustomCharacter(4, Khaled2, 2, 10);

	LCD_voidWriteCustomCharacter(4, Khaled3, 2, 8);
	LCD_voidWriteCustomCharacter(4, Khaled3, 2, 9);
	LCD_voidWriteCustomCharacter(4, Khaled3, 2, 10);

	/*Repeat -----------------------------------------*/
	LCD_voidWriteCustomCharacter(4, Khaled, 2, 8);
	LCD_voidWriteCustomCharacter(4, Khaled, 2, 9);
	LCD_voidWriteCustomCharacter(4, Khaled, 2, 10);

	LCD_voidWriteCustomCharacter(4, Khaled1, 2, 8);
	LCD_voidWriteCustomCharacter(4, Khaled1, 2, 9);
	LCD_voidWriteCustomCharacter(4, Khaled1, 2, 10);

	LCD_voidWriteCustomCharacter(4, Khaled2, 2, 8);
	LCD_voidWriteCustomCharacter(4, Khaled2, 2, 9);
	LCD_voidWriteCustomCharacter(4, Khaled2, 2, 10);

	LCD_voidWriteCustomCharacter(4, Khaled3, 2, 8);
	LCD_voidWriteCustomCharacter(4, Khaled3, 2, 9);
	LCD_voidWriteCustomCharacter(4, Khaled3, 2, 10);

	_delay_ms(500);
}


