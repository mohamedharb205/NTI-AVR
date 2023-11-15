/*****************************************************************************************/
/*****************************************************************************************/
/***********************		AUTHOR	:	MOHAMED HARB		**************************/
/***********************		LAYER	:	APP					**************************/
/***********************		DES.	:	Calculator PROJECT	**************************/
/***********************		DATE	:	2-11-2023			**************************/
/***********************		VERSION	:	V01					**************************/
/*****************************************************************************************/
/*****************************************************************************************/

#ifndef F_CPU
#define F_CPU	8000000
#endif

#include "../MCAL/DIO/DIO_interface.h"
#include "../HAL/LCD/LCD_interface.h"
#include "../HAL/LCD/LCD_private.h"

#include "../HAL/KEYPAD/KEYPAD_interface.h"
#include "../HAL/KEYPAD/KEYPAD_config.h"

#include "avr/delay.h"




#define MAX_PASSWORD_NUM	20
#define MAX_INPUTS_NUM		20


/* GLOBAL VARIABLES */
volatile u8 KeyPadValue = KEYPAD_NOT_PRESSED;                       //variable to store the pressed button for Keypad
volatile u8 DigitsNumber = 0;                   //variable to calculate the number of digit of password
volatile u8 Counter = 0;
volatile u8 Index = 0;

volatile u8 Pasword[MAX_PASSWORD_NUM];						 //array to store the password when set
volatile u8 CheckPasword[MAX_PASSWORD_NUM];					//array to store the password when check
static s16 Inputs[MAX_INPUTS_NUM];


/* FUNCTIONS PROTOTYPES */
void Get_Password();
void Get_Check_Password();
void Check_Password();
u8 Check_Password_Result(u8 Copy_u8Password[], u8 Copy_u8CheckPasword[], u8 Copy_u8DigitsNumber, u8 Copy_u8Counter);

void Get_From_User();
u16 Calculate_Result();
void Show_Result();
void Another_Process();

s16 SUM		(s16 Operand1 , s16 Operand2);
s16 SUB		(s16 Operand1 , s16 Operand2);
s16 MULTI	(s16 Operand1 , s16 Operand2);
s16 DIV		(s16 Operand1 , s16 Operand2);

void Swap(s16* Operand1 , s16* Operand2);



int main()
{
	KeyPad_voidInit();						//Initialize KEYPAD
	LCD_voidInit();							//Initialize LCD

//	sei();
//	EXIT_Interrupts_Init(EXIT_INT0,EXIT_EDGE_RAISING);
//	EXIT_Set_CallBack(EXIT_INT0,INT0_Interrupt);


	/* Set Password for First time */
	LCD_voidWriteStringAtXY("Welecome", 0,1);
	_delay_ms(500);
	LCD_voidClear();

	LCD_voidWriteStringAtXY("Set New Password", 0, 1);
	Get_Password();
	LCD_voidClear();

	/* Get Password To Check It */
	LCD_voidWriteStringAtXY("Check password", 0, 1);
	Check_Password();

	while(1)
	{
		/* Get Numbers and Operators from the user */
		Get_From_User();

		if(KeyPadValue == '=')
		{
			/* Calculate the result and return it */
			Calculate_Result();
			Show_Result();
		}

		/* Perform another Calculation process */
		Another_Process();
	}

	return 0;
}//main






void Get_Password()
{
	while(DigitsNumber < MAX_PASSWORD_NUM)
	{
		/* Get New Password */
		do
		{
			KeyPadValue = KeyPad_u8GetPress();
		}while(KeyPadValue == '\0');	//


		if(KeyPadValue == 'C')
		{
			_delay_ms(100);
			break;
		}
		else
		{
			LCD_voidGoToXY(3 , DigitsNumber);
			LCD_voidWriteCharacter(KeyPadValue);
			_delay_ms(100);
			LCD_voidGoToXY(3 , DigitsNumber);
			LCD_voidWriteCharacter('*');
			/* Put the number in the password array */
			Pasword[DigitsNumber] = KeyPadValue;
		}

		DigitsNumber++;	// To calculate the number of digits of the password array
	}
}

void Get_Check_Password()
{
	Counter = 0;
	while(Counter < MAX_PASSWORD_NUM)
	{
		/* Get New Password */
		do
		{
			KeyPadValue = KeyPad_u8GetPress();
		}while(KeyPadValue == '\0');	//


		if(KeyPadValue == 'C')
		{
			break;
		}
		else
		{
			LCD_voidGoToXY(3 , Counter);
			LCD_voidWriteCharacter(KeyPadValue);
			_delay_ms(100);
			LCD_voidGoToXY(3 , Counter);
			LCD_voidWriteCharacter('*');
			/* Put the number in the password array */
			CheckPasword[Counter] = KeyPadValue;
		}

		Counter++;	// To calculate the number of digits of the check password array
	}
}

void Check_Password()
{
	while(1)
	{
		KeyPadValue = KEYPAD_NOT_PRESSED;
		Get_Check_Password();


		/* Check if Password is correct or not */
		if(Check_Password_Result(CheckPasword, Pasword, DigitsNumber, Counter) == 1) 	// Password is correct
		{
			/* Loading to Start Calculator */
			LCD_voidClear();
			LCD_voidWriteStringAtXY("Password is correct", 0,1);
			_delay_ms(500);

			/* Loading */
			LCD_voidWriteStringAtXY("Loading", 1,1);
			for(u8 Local_u8Counter = 0; Local_u8Counter < 4; Local_u8Counter++)
			{
				if(Local_u8Counter == 3)
				{
					LCD_voidGoToXY(1, Local_u8Counter+9);
					LCD_voidWriteCharacter('>');
					_delay_ms(100);
					break;
				}
				LCD_voidGoToXY(1, Local_u8Counter+9);
				LCD_voidWriteCharacter('-');
				_delay_ms(100);
			}
			_delay_ms(200);
			LCD_voidClear();

			/* Calculator is ready to use */
			LCD_voidWriteStringAtXY("Calculator is ready", 0,0);
			_delay_ms(500);
			LCD_voidClear();
			break;
		}
		/* Password is incorrect */
		else
		{
			LCD_voidClear();
			LCD_voidWriteStringAtXY("Pass is incorrect !!", 0,0);
			LCD_voidWriteStringAtXY("Try again ", 1,5);
			continue;
		}
	}
}

u8 Check_Password_Result(u8 Copy_u8Password[], u8 Copy_u8CheckPasword[], u8 Copy_u8DigitsNumber, u8 Copy_u8Counter)
{
	u8 Local_u8DigitsNumber_Ok = 0;

	for(u8 Local_u8Counter = 0; Local_u8Counter < Copy_u8DigitsNumber; Local_u8Counter++)
	{
		if(Copy_u8Password[Local_u8Counter] == Copy_u8CheckPasword[Local_u8Counter])
		{
			Local_u8DigitsNumber_Ok++;
		}
	}

	if((Local_u8DigitsNumber_Ok == Copy_u8DigitsNumber) && (Copy_u8Counter == Copy_u8DigitsNumber))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


void Get_From_User()
{
	Index = 0;

	while((Index < MAX_INPUTS_NUM) && (KeyPadValue != '='))
	{
		/* Getting The Numbers */
		while(Index % 2 == 0)	// 19 to let 1 location for =  >>>> the result will be shown on the 3rd line
		{
			do
			{
				KeyPadValue = KeyPad_u8GetPress();
			}while(KeyPadValue == '\0');

			if(KeyPadValue == '0' || KeyPadValue == '1' || KeyPadValue == '2' || KeyPadValue == '3' || KeyPadValue == '4' || KeyPadValue == '5' || KeyPadValue == '6' || KeyPadValue == '7' || KeyPadValue == '8' || KeyPadValue == '9')
			{
				LCD_voidClearLine(3,0);
				Inputs[Index] = (KeyPadValue - '0');
				LCD_voidGoToXY(0, Index);
				//LCD_voidWriteCharacter(KeyPadValue);
				LCD_voidWriteDecimal(KeyPadValue -'0');
				Index++;
			}
			else if(KeyPadValue == 'C')
			{
				break;	// Get out from this operation
			}
			else
			{
				LCD_voidWriteStringAtXY("Invalid Input", 3,1);
				continue;
			}
		}

		/* Getting The Operators */
		while(Index % 2 != 0)
		{
			do
			{
				KeyPadValue = KeyPad_u8GetPress();
			}while(KeyPadValue == '\0');

			if(KeyPadValue == '+' || KeyPadValue == '-' || KeyPadValue == '/' || KeyPadValue == '*')
			{
				LCD_voidClearLine(3,0);
				Inputs[Index] = KeyPadValue;
				LCD_voidGoToXY(0, Index);
				LCD_voidWriteCharacter(KeyPadValue);
				Index++;
			}
			else if(KeyPadValue == '=')
			{
				/* break if KeyPadValue = '=' */
				LCD_voidClearLine(3,0);
				Inputs[Index] = KeyPadValue;
				LCD_voidGoToXY(0, Index);
				LCD_voidWriteCharacter(KeyPadValue);
				//Show_Result();
				DigitsNumber = Index; 	// Save the value of Index in DigitsNumber to use it in Show function to show the result at the position after =
				break;
			}
			else if(KeyPadValue == 'C')
			{
				break;
			}
			else
			{
				LCD_voidWriteStringAtXY("Invalid Input", 3,1);
				continue;
			}
		}
	}
}


u16 Calculate_Result()
{
	//u16 Local_u16Result = 0;

	/* Calculate the result */
	// 1- search for * more than 1 times
	// 2- perform its operations
	// 3- sort the array until you reach the '=' character
	// 4- repeat for all operators
	// 5- continue until the index value == 1 and for each iteration index -2

	while(Index > 1)
	{
		/* switch which operation was Selected */

		/* Finish '*' and '/' Operations */
		u8 Local_u8Index = 0;
		for (Local_u8Index = 1; Local_u8Index <= Index; Local_u8Index+=2)	// odd indices >>> Searching for operators
		{
			if((Inputs[Local_u8Index] == '*') || (Inputs[Local_u8Index] == '/'))
			{
				if(Inputs[Local_u8Index] == '*')
				{
					Inputs[Local_u8Index-1] = MULTI(Inputs[Local_u8Index-1] , Inputs[Local_u8Index+1]);
				}
				else if(Inputs[Local_u8Index] == '/')
				{
					Inputs[Local_u8Index-1] = DIV(Inputs[Local_u8Index-1] , Inputs[Local_u8Index+1]);
				}

				Inputs[Local_u8Index] 	= '\0';
				Inputs[Local_u8Index+1] = '\0';
				/* Swap the null at position of Local_u8Index to right of = */
				for(u8 i = Local_u8Index; i <= Index; i++)
				{
					if(Inputs[i+1] != '=')
					{
						Swap(&Inputs[i] , &Inputs[i+1]);
					}
					if(Inputs[i+1] == '=')
					{
						Swap(&Inputs[i] , &Inputs[i+1]);
						// i = Index+1;
						break;
					}
				}
				/* Swap the null at position of (Local_u8Index -1) to right of = */
				for(u8 i = Local_u8Index; i <= Index; i++)
				{
					if(Inputs[i+1] != '=')
					{
						Swap(&Inputs[i] , &Inputs[i+1]);
					}
					if(Inputs[i+1] == '=')
					{
						Swap(&Inputs[i] , &Inputs[i+1]);
						// i = Index+1;
						break;
					}
				}

				Local_u8Index = -1;	// go back one step to repeat the search for the same operator
				Index = Index - 2;	// Reduce Index by 2 because you get rid of 2 values as null
				continue;
			}
		}


		/* Finish '+' and '-' Operations */
		Local_u8Index = 0;
		for (Local_u8Index = 1; Local_u8Index <= Index; Local_u8Index+=2)	// odd indices >>> Searching for operators
		{
			if((Inputs[Local_u8Index] == '+') || (Inputs[Local_u8Index] == '-'))
			{
				if(Inputs[Local_u8Index] == '+')
				{
					Inputs[Local_u8Index-1] = SUM(Inputs[Local_u8Index-1] , Inputs[Local_u8Index+1]);
				}
				else if(Inputs[Local_u8Index] == '-')
				{
					Inputs[Local_u8Index-1] = SUB(Inputs[Local_u8Index-1] , Inputs[Local_u8Index+1]);
				}

				Inputs[Local_u8Index] 	= '\0';
				Inputs[Local_u8Index+1] = '\0';
				/* Swap the null at position of Local_u8Index to right of = */
				for(u8 i = Local_u8Index; i <= Index; i++)
				{
					if(Inputs[i+1] != '=')
					{
						Swap(&Inputs[i] , &Inputs[i+1]);
					}
					if(Inputs[i+1] == '=')
					{
						Swap(&Inputs[i] , &Inputs[i+1]);
						// i = Index+1;
						break;
					}
				}
				/* Swap the null at position of (Local_u8Index -1) to right of = */
				for(u8 i = Local_u8Index; i <= Index; i++)
				{
					if(Inputs[i+1] != '=')
					{
						Swap(&Inputs[i] , &Inputs[i+1]);
					}
					if(Inputs[i+1] == '=')
					{
						Swap(&Inputs[i] , &Inputs[i+1]);
						// i = Index+1;
						break;
					}
				}
				Local_u8Index = -1;	// go back one step to repeat the search for the same operator
				Index = Index - 2;	// Reduce Index by 2 because you get rid of 2 values as null
				continue;
			}
		}
	} // break while because Index = 0


	//Local_u16Result = Inputs[0];
// can be optimized by returning the value directly
	return Inputs[0];	//return Local_u16Result;
}


void Show_Result()
{
	// show the result
	LCD_voidGoToXY(0,DigitsNumber+1);
	LCD_voidWriteDecimal((s16)Calculate_Result());	// LCD_voidWriteDecimal((s16)Inputs[0]);
	_delay_ms(500);
	//LCD_voidClear();
}


void Another_Process()
{
	// tab '0' to continue and perform another operation
	// tab 'C' to break and finish the program
	//LCD_voidClear();
	LCD_voidWriteStringAtXY("Select Option:", 1, 0);
	LCD_voidWriteStringAtXY("'0' Continue ... ", 2, 0);
	LCD_voidWriteStringAtXY("'C' Close System", 3, 0);

	do
	{
		KeyPadValue = KeyPad_u8GetPress();
	}while(KeyPadValue == '\0');	//


	if(KeyPadValue == 'C')
	{
		LCD_voidClear();
		LCD_voidWriteStringAtXY("Calculator disabled", 0, 0);
		_delay_ms(500);
		LCD_voidClear();
		exit(0);
	}
	else if(KeyPadValue == '0')
	{
		LCD_voidClear();
		LCD_voidWriteStringAtXY("do another Operation", 0, 0);
		_delay_ms(500);
		LCD_voidClear();
	}
}



s16 SUM(s16 Operand1 , s16 Operand2)
{
	return (Operand1 + Operand2);
}

s16 SUB(s16 Operand1 , s16 Operand2)
{
	return (Operand1 - Operand2);
}

s16 MULTI(s16 Operand1 , s16 Operand2)
{
	return (Operand1 * Operand2);
}

s16 DIV(s16 Operand1 , s16 Operand2)
{
	//return ((Operand1-'0') / (Operand2-'0'));
	return (Operand1 / Operand2);
}




void Swap(s16* Operand1 , s16* Operand2)
{
	s16 Temp = *Operand1;
	*Operand1 = *Operand2;
	*Operand2 = Temp;
}
