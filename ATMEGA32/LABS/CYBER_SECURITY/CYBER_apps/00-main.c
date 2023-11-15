/*****************************************************************************************/
/*****************************************************************************************/
/***********************		AUTHOR	:	MOHAMED HARB		**************************/
/***********************		LAYER	:	APP					**************************/
/***********************		SWC		:	MAIN				**************************/
/***********************		DATE	:	NOV 10, 2023		**************************/
/***********************		VERSION	:	V01					**************************/
/*****************************************************************************************/
/*****************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "../CYBER_driver/STD_TYPES.h"
#include "../CYBER_driver/DIO_interface.h"
#include "../CYBER_driver/TIMER0_interface.h"
#include "../CYBER_driver/LCD_interface.h"
#include "../CYBER_driver/USART_interface.h"


#define 	LED_ON_ORDER					"3101AA00"
#define 	LED_ON_VERIFIED					"7101AA00"

#define 	ACCESS_DENIED					"7F3135"

#define 	RANDOM_KEY_ORDER				"2701"
#define 	RANDOM_KEY_RESPOND				"6701"

#define 	CHECK_DECRYPTED_KEY				"2702"
#define 	ACCESS_VERIFIED					"6702"


#define 	WRONG_ORDER						0
#define 	RIGHT_ORDER						1


static u8 User_Input[20];
static u8 Input_Counter = 0;

static u8 Order_Flag = WRONG_ORDER;
static u8 Random_Array[9] = {'\0'};;
static u8 Encrypted_Array[9] = {'\0'};

static u8 Conc_Key[13] =  RANDOM_KEY_RESPOND;
//static u8 Conc_Encrypted_Key_Respond[13] =  DECRIPT_RAND_KEY;




/* Function Prototypes */
void Cyber_voidInit();
void Get_From_User();

void Check_User_Input();
void First_Time_Access();
void Opearations_After_Access();
u8 	 Check_Two_Arrays(u8* arr1 , u8* arr2);

void Get_Random_Array();
void Encrytp_Numbers(u8* arr);

void Led_ON();
void Led_OFF();



int main()
{
	Cyber_voidInit();

	while(1)
	{
		Get_From_User();
		Check_User_Input();
	}


	return 0;
}



void Cyber_voidInit()
{
	DIO_voidSetPinDirection(DIO_u8PORTD, DIO_u8PIN0, DIO_u8PIN_INPUT);		// RX
	DIO_voidSetPinDirection(DIO_u8PORTD, DIO_u8PIN1, DIO_u8PIN_OUTPUT);		// TX
	DIO_voidSetPinDirection(DIO_u8PORTC, DIO_u8PIN0, DIO_u8PIN_OUTPUT);		// Red led

	LCD_voidInit();
	USART_Init();
}



void Get_From_User()
{
	u8 Local_u8UserData;
	u8 Local_u8Counter = 0;

	for(Local_u8Counter = 0; Local_u8Counter < 20; Local_u8Counter++)
	{
		User_Input[Local_u8Counter] = '\0';
	}

	Local_u8Counter = 0;
	while(1)
	{
		Local_u8UserData = USART_Receive();

		if(Local_u8UserData == 0x8)		// Back space
		{
			Local_u8Counter --;
			User_Input[Local_u8Counter] = '\0';
		}
		else if(Local_u8UserData == 0x0D)		// Enter
		{
			User_Input[Local_u8Counter] =  '\0';	// fill with null to know the end of the array
		//	USART_Transmit(0x0D);		// To go to another line
			break;
		}
		else //if(Local_u8UserData != 0x0D)	// Enter
		{
			User_Input[Local_u8Counter] =  Local_u8UserData;
			Local_u8Counter++;
			Input_Counter++;
		}
	}
}



void Check_User_Input()
{
	if (Order_Flag == RIGHT_ORDER)
	{
		Opearations_After_Access();
	}
	else if (Order_Flag == WRONG_ORDER)
	{
		First_Time_Access();
	}
}



void First_Time_Access()
{
	u8 Local_u8CheckResult = 0;
	Local_u8CheckResult = Check_Two_Arrays(User_Input , RANDOM_KEY_ORDER);		// 2701
	if(Local_u8CheckResult == 1)	// the two arrays are equal
	{
		u8 Local_u8Counter = 0;
		Get_Random_Array();		// Random_Array

		strcat(Conc_Key , Random_Array);  		// Conc_Key = 6701
		Conc_Key[12] = '\0';
		LCD_voidClear();
		while(Conc_Key[Local_u8Counter] != '\0')
		{
			USART_Transmit(Conc_Key[Local_u8Counter]);
			LCD_voidGoToXY(0,Local_u8Counter);
			LCD_voidWriteCharacter(Conc_Key[Local_u8Counter]);
			Local_u8Counter++;
		}

		//USART_Transmit(0x0D);	// new line
//		LCD_voidGoToXY(1,0);
//		LCD_voidWriteString("Random Array");
		Encrytp_Numbers(Random_Array);		// Encrypt the key
		/*show the encrypted key on the screen */
		Local_u8Counter = 0;
		LCD_voidGoToXY(2,0);
		LCD_voidWriteString("Encrypted Array");
		while(Encrypted_Array[Local_u8Counter] != '\0')
		{
			LCD_voidGoToXY(3, Local_u8Counter);	// show at the last line
			LCD_voidWriteCharacter(Encrypted_Array[Local_u8Counter]);
			Local_u8Counter++;
		}

		Order_Flag = RIGHT_ORDER;
	}
	/* if the user enter anything else .... deny the access */
	else if(Local_u8CheckResult == 0)
	{
		u8 Local_u8Counter = 0;
		LCD_voidClear();
		while(ACCESS_DENIED[Local_u8Counter] != '\0')
		{
			USART_Transmit(ACCESS_DENIED[Local_u8Counter]);
			LCD_voidGoToXY(0,Local_u8Counter);
			LCD_voidWriteCharacter(ACCESS_DENIED[Local_u8Counter]);
			Local_u8Counter++;
		}
		LCD_voidGoToXY(2,0);
		LCD_voidWriteString("Wrong Order !!!");

	}

	USART_Transmit(0x0D);		// new line
}


void Opearations_After_Access()
{
	/* check if it transmit access update the flag .... else show error and do not update the flag */

	u8 Local_u8CheckResult = 0;
	strcpy(Conc_Key , CHECK_DECRYPTED_KEY);		// Conc_Key = 2702
	strcat(Conc_Key , Encrypted_Array);
	Conc_Key[12] = '\0';
//	/* Display on LCD */
//	u8 Local_u8Couneter = 0;
//	while(Conc_Encrypted_Key_Respond[Local_u8Couneter] != '\0')
//	{
//		LCD_voidGoToXY(3, Local_u8Couneter);
//		LCD_voidWriteCharacter(Conc_Encrypted_Key_Respond[Local_u8Couneter]);
//		Local_u8Couneter++;
//	}

	Local_u8CheckResult = Check_Two_Arrays(User_Input , Conc_Key);
	if(Local_u8CheckResult == 1)
	{
		u8 Local_u8Counter = 0;
		LCD_voidClear();
		while(ACCESS_VERIFIED[Local_u8Counter] != '\0')
		{
			USART_Transmit(ACCESS_VERIFIED[Local_u8Counter]);
			LCD_voidGoToXY(0,Local_u8Counter);
			LCD_voidWriteCharacter(ACCESS_VERIFIED[Local_u8Counter]);
			Local_u8Counter++;
		}
		LCD_voidGoToXY(2,0);
		LCD_voidWriteString("Access Verified ...");
	}

	else if(Local_u8CheckResult == 0)
	{
		u8 Local_u8CheckResult = 0;
		Local_u8CheckResult = Check_Two_Arrays(User_Input , LED_ON_ORDER);

		if(Local_u8CheckResult == 1)
		{
			u8 Local_u8Counter = 0;
			LCD_voidClear();
			while(LED_ON_VERIFIED[Local_u8Counter] != '\0')
			{
				USART_Transmit(LED_ON_VERIFIED[Local_u8Counter]);
				LCD_voidGoToXY(0,Local_u8Counter);
				LCD_voidWriteCharacter(LED_ON_VERIFIED[Local_u8Counter]);
				Local_u8Counter++;
			}
			LCD_voidGoToXY(2,0);
			LCD_voidWriteString("Led is ON");
			Led_ON();
		}

		/* if the user enter anything else .... deny the access */
		else
		{
			u8 Local_u8Counter = 0;
			LCD_voidClear();
			while(ACCESS_DENIED[Local_u8Counter] != '\0')
			{
				USART_Transmit(ACCESS_DENIED[Local_u8Counter]);
				LCD_voidGoToXY(0,Local_u8Counter);
				LCD_voidWriteCharacter(ACCESS_DENIED[Local_u8Counter]);
				Local_u8Counter++;
			}
			LCD_voidGoToXY(2,0);
			LCD_voidWriteString("Wrong Order !!!");
		}
	}

	USART_Transmit(0x0D);		// new line
}




u8 Check_Two_Arrays(u8* arr1 , u8* arr2)
{
	u8 Local_u8Count = 0;
	u8 Counter = 0;


	for ( ; Local_u8Count <= Input_Counter; )
//	while(arr1[Local_u8Count] != '\0')
	{
		if(arr1[Local_u8Count] == arr2[Local_u8Count])
		{
			Counter++;
			Local_u8Count++;
			continue;
		}
		else
		{
			Local_u8Count ++;
		}
	}
	if(Counter == Local_u8Count)
	{
		Input_Counter = 0;		// to count another input from the user
		return 1;
	}
	else
	{
		Input_Counter = 0;		// to count another input from the user
		return 0;
	}
}


void Get_Random_Array()
{
	Timer0_voidInit();

    // Generate 8 random numbers
    for (u8 i = 0; i < 8; i++)
    {
        Random_Array[i] = (Timer0_u8GetTCNT() % 10) + '0';		//(rand() %10) + '0';
    }
    Random_Array[8] = '\0';
}



void Encrytp_Numbers(u8* arr)
{
	/* Assume Key = 3 */
	u8 Local_u8Couneter = 0;
	while(arr[Local_u8Couneter] != '\0')
	{
		if(((arr[Local_u8Couneter] -'0') ^ 3) <= 9)
		{
		Encrypted_Array[Local_u8Couneter] = ((arr[Local_u8Couneter] -'0') ^ 3) + ('0');
		Local_u8Couneter++;
		}

		else if(((arr[Local_u8Couneter] -'0') ^ 3) > 9)
		{
			Encrypted_Array[Local_u8Couneter] = ((arr[Local_u8Couneter] -'0') ^ 3) -10 + ('A');
			Local_u8Couneter++;
		}
	}

	Encrypted_Array[Local_u8Couneter] = '\0';

	Local_u8Couneter = 0;
	while(Encrypted_Array[Local_u8Couneter] != '\0')
	{
		LCD_voidGoToXY(2, Local_u8Couneter);
		LCD_voidWriteCharacter(Encrypted_Array[Local_u8Couneter]);
		Local_u8Couneter++;
	}
}





void Led_ON()
{
	DIO_voidSetPinValue(DIO_u8PORTC, DIO_u8PIN0, DIO_u8PIN_HIGH);
}

void Led_OFF()
{
	DIO_voidSetPinValue(DIO_u8PORTC, DIO_u8PIN0, DIO_u8PIN_LOW);
}
