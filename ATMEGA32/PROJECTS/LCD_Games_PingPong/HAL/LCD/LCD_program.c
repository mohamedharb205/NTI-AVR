/*****************************************************************************************/
/*****************************************************************************************/
/***********************		AUTHOR	:	MOHAMED HARB		**************************/
/***********************		LAYER	:	HAL					**************************/
/***********************		SWC		:	LCD					**************************/
/***********************		DATE	:	OCT 20, 2023		**************************/
/***********************		VERSION	:	V01					**************************/
/*****************************************************************************************/
/*****************************************************************************************/



#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "LCD_private.h"
#include "LCD_config.h"
#include "LCD_interface.h"

#include "../../MCAL/DIO/DIO_interface.h"
#include "avr/delay.h"



// Global variables
static u8 Is_Init_Finished = 0;



/* Functions Initialization */
void LCD_voidInit()
{
	/* PINS Directions Configuration */
	SET_voidLCDPinsDirection();

	#if		CONNECTION_MODE == LCD_FOUR_BIT_MODE	// 4 Bits Mode
			// Wait for more than 30 ms
			_delay_ms(100);

			// Function Set
			Send_voidCommand(FUNCTION_SET1);	// Data length = 4 , N = 2 lines , F = 5*7
			Send_voidCommand(FUNCTION_SET2);
			Send_voidCommand(FUNCTION_SET3);
			_delay_ms(1);	// delay > 39 micro sec

			// Display ON/OFF Control
			Send_voidCommand(DISPLAY_ON_OFF_CONTROL1);	// Display = ON , Cursor = OFF , Blink = OFF
			Send_voidCommand(DISPLAY_ON_OFF_CONTROL2);
			_delay_ms(1);	// delay > 39 micro sec

			// Display Clear
			Send_voidCommand(DISPLAY_CLEAR1);
			Send_voidCommand(DISPLAY_CLEAR2);
			_delay_ms(2);	// delay > 1.53 ms

			// Entry Mode Set
			Send_voidCommand(ENTRY_MODE_SET1); // I/D: increase (write from left to right) = 1 , SH: No Shift = 0
			Send_voidCommand(ENTRY_MODE_SET2);

	#elif	CONNECTION_MODE == LCD_EIGHT_BIT_MODE	// 8 Bits Mode
			// Wait for more than 30 ms
			_delay_ms(35);

			// Function Set
			Send_voidCommand(0b00111000);	// Data length = 8 , N = 2 lines , F = 5*7
			_delay_ms(1);	// delay > 39 micro sec

			// Display ON/OFF Control
			Send_voidCommand(0b00001100);	// Display = ON , Cursor = OFF , Blink = OFF
			_delay_ms(1);	// delay > 39 micro sec

			// Display Clear
			Send_voidCommand(0b00000001);
			_delay_ms(2);	// delay > 1.53 ms

			// Entry Mode Set
			Send_voidCommand(0b00000110); // I/D: increase (write from left to right) = 1 , SH: No Shift = 0
	#else
		#error	"INVALID MODE !!!"
	#endif

	Is_Init_Finished = 1;
	_delay_ms(2);	// delay > 1.53 ms
}



void SET_voidLCDPinsDirection()
{
	// Set Ditrections of 4 bits mode
	DIO_voidSetPinDirection(LCD_DATA_PORT, LCD_D4_PIN, DIO_u8PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_DATA_PORT, LCD_D5_PIN, DIO_u8PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_DATA_PORT, LCD_D6_PIN, DIO_u8PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_DATA_PORT, LCD_D7_PIN, DIO_u8PIN_OUTPUT);
	// set direction of Control Pins
	DIO_voidSetPinDirection(LCD_CTRL_PORT, LCD_EN_PIN, DIO_u8PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_CTRL_PORT, LCD_RS_PIN, DIO_u8PIN_OUTPUT);

	// Set LCD PORT direction for simulation
	//DIO_voidSetPortDirection(LCD_PORT, DIO_PORT_OUTPUT);
}

void Send_voidEnablePulse()
{
	DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, DIO_u8PIN_HIGH);	// Set Enable
	_delay_ms(2);	// delay more than 50 mico seconds
	DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, DIO_u8PIN_LOW);
	//_delay_ms(2);
}

void Send_voidCommand(u8 Copy_u8Command)
{
	// 1-Set RS pin low for command
	DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, DIO_u8PIN_LOW);
	// 2- Set RW pin to low for write
	#if 	READ_OPERATION_STATUS == LCD_ENABLED
			DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RW_PIN, DIO_u8PIN_LOW);	// connected to ground to be set write all the time
	#endif

	#if 	CONNECTION_MODE == LCD_FOUR_BIT_MODE
			DIO_voidSetPinValue(LCD_DATA_PORT, LCD_D4_PIN, GET_BIT(Copy_u8Command,DIO_u8PIN4));		// error .... Remember that GET_BIT not DIO_GetPinValue
			DIO_voidSetPinValue(LCD_DATA_PORT, LCD_D5_PIN, GET_BIT(Copy_u8Command,DIO_u8PIN5));
			DIO_voidSetPinValue(LCD_DATA_PORT, LCD_D6_PIN, GET_BIT(Copy_u8Command,DIO_u8PIN6));
			DIO_voidSetPinValue(LCD_DATA_PORT, LCD_D7_PIN, GET_BIT(Copy_u8Command,DIO_u8PIN7));
			Send_voidEnablePulse();

			if(Is_Init_Finished)
			{
				DIO_voidSetPinValue(LCD_DATA_PORT, LCD_D4_PIN, GET_BIT(Copy_u8Command,DIO_u8PIN0));
				DIO_voidSetPinValue(LCD_DATA_PORT, LCD_D5_PIN, GET_BIT(Copy_u8Command,DIO_u8PIN1));
				DIO_voidSetPinValue(LCD_DATA_PORT, LCD_D6_PIN, GET_BIT(Copy_u8Command,DIO_u8PIN2));
				DIO_voidSetPinValue(LCD_DATA_PORT, LCD_D7_PIN, GET_BIT(Copy_u8Command,DIO_u8PIN3));
				Send_voidEnablePulse();
			}

	#elif	CONNECTION_MODE == LCD_EIGHT_BIT_MODE
			DIO_voidSetPortValue(LCD_PORT , Copy_u8Command);
			Send_voidEnablePulse();
	#else
		#error	"Invalid MODE to Send Command !!!"
	#endif

	//_delay_ms(2);
}

void Send_voidData(u8 copy_u8Data)
{
	// 1-Set RS pin HIGH for data
	DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, DIO_u8PIN_HIGH);
	// 2- Set RW pin to low for write
	#if 	READ_OPERATION_STATUS == LCD_ENABLED
			DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RW_PIN, DIO_PIN_LOW);	// connected to ground to be set write all the time
	#endif

	#if		CONNECTION_MODE == LCD_FOUR_BIT_MODE
			DIO_voidSetPinValue(LCD_DATA_PORT, LCD_D4_PIN, GET_BIT(copy_u8Data,DIO_u8PIN4));
			DIO_voidSetPinValue(LCD_DATA_PORT, LCD_D5_PIN, GET_BIT(copy_u8Data,DIO_u8PIN5));
			DIO_voidSetPinValue(LCD_DATA_PORT, LCD_D6_PIN, GET_BIT(copy_u8Data,DIO_u8PIN6));
			DIO_voidSetPinValue(LCD_DATA_PORT, LCD_D7_PIN, GET_BIT(copy_u8Data,DIO_u8PIN7));
			Send_voidEnablePulse();

			DIO_voidSetPinValue(LCD_DATA_PORT, LCD_D4_PIN, GET_BIT(copy_u8Data,DIO_u8PIN0));
			DIO_voidSetPinValue(LCD_DATA_PORT, LCD_D5_PIN, GET_BIT(copy_u8Data,DIO_u8PIN1));
			DIO_voidSetPinValue(LCD_DATA_PORT, LCD_D6_PIN, GET_BIT(copy_u8Data,DIO_u8PIN2));
			DIO_voidSetPinValue(LCD_DATA_PORT, LCD_D7_PIN, GET_BIT(copy_u8Data,DIO_u8PIN3));
			Send_voidEnablePulse();

	#elif	CONNECTION_MODE == LCD_EIGHT_BIT_MODE
			DIO_voidSetPortValue(LCD_PORT , copy_u8Data);
			Send_voidEnablePulse();
	#else
		#error	"Invalid MODE to Write Data !!!"
	#endif

	//_delay_ms(2);
}




void LCD_voidClear()
{
	Send_voidCommand(DISPLAY_CLEAR);
}

void LCD_voidClearLine(u8 copy_u8Ypos , u8 copy_u8Xpos)
{
	for(u8 Local_u8Counter = copy_u8Xpos; Local_u8Counter < 20; Local_u8Counter++)
	{
		LCD_voidWriteCharacterAtXY('\0' , copy_u8Ypos , Local_u8Counter);
	}
}




void LCD_voidWriteCharacter(u8 copy_u8Character)
{
	Send_voidData(copy_u8Character);
}

void LCD_voidWriteCharacterAtXY(u8 copy_u8Character, u8 copy_u8YPos , u8 copy_u8XPos)
{
	LCD_voidGoToXY(copy_u8YPos, copy_u8XPos);
	LCD_voidWriteCharacter(copy_u8Character);
}



void LCD_voidWriteString(u8* copy_pu8String)
{
	u8 Local_u8Counter = 0;
	while(copy_pu8String[Local_u8Counter] != '\0')
	{
		Send_voidData(copy_pu8String[Local_u8Counter]);
		Local_u8Counter++;
	}
}

void LCD_voidWriteStringAtXY(u8* copy_pu8String, u8 copy_u8YPos , u8 copy_u8XPos)
{
	LCD_voidGoToXY(copy_u8YPos, copy_u8XPos);
	LCD_voidWriteString(copy_pu8String);
}



void LCD_voidGoToXY(u8 copy_u8YPos , u8 copy_u8XPos)
{
	u8 Local_u8DDRAM_Address = 0;
	//0x80, 0xC0, 0x94, 0xD4

	if(copy_u8YPos == LCD_LINE_ONE)
	{
		Local_u8DDRAM_Address = copy_u8XPos + 0x80;
	}
	else if(copy_u8YPos == LCD_LINE_TWO)
	{
		Local_u8DDRAM_Address = copy_u8XPos + 0xC0;
	}
	else if(copy_u8YPos == LCD_LINE_THREE)
	{
		Local_u8DDRAM_Address = copy_u8XPos + 0x94;
	}
	else if(copy_u8YPos == LCD_LINE_FOUR)
	{
		Local_u8DDRAM_Address = copy_u8XPos + 0xD4;
	}

	SET_BIT(Local_u8DDRAM_Address , 7);				// Set bit 7 to 1
	Send_voidCommand(Local_u8DDRAM_Address);			// Go to this Address
	_delay_us(40);
}



void LCD_voidWriteDecimal(s32 copy_s32Number) {

	if (copy_s32Number < 0)
	{
		Send_voidData('-'); // Display negative sign
		copy_s32Number = -copy_s32Number; // Convert to positive number
	}
//    else if (copy_s32Number == 0 )
//    {
//    	LCD_voidSendData('0');
//    	return ;
//    }

    u8 digits[10] = {0}; // Array to store up to 10 digits (maximum for s32)
    u8 digits_No = 0;

    while (copy_s32Number > 0)
    {
        digits[digits_No] = copy_s32Number % 10; // Extract the least significant digit
        copy_s32Number /= 10; // Move to the next digit
        digits_No++;
    }

    if (digits_No == 0) {
        digits_No = 1; // At least one digit (zero) should be displayed
    }

    for (u8 i = digits_No; i > 0; i--) {
    	Send_voidData(digits[i - 1] + '0'); // Display the digit on LCD
    }
}

void LCD_voidWriteFloat(f32 copy_f32Number)
{
    // Split the float number into its integer and fractional parts
    s32 Local_s32IntegerPart = (s32)copy_f32Number;
    f32 Local_f32FractionalPart = copy_f32Number - Local_s32IntegerPart;

    // Write the integer part to the LCD
    LCD_voidWriteDecimal(Local_s32IntegerPart);

    // Write the decimal point to the LCD
    LCD_voidWriteCharacter('.');

    // Write the fractional part to the LCD, multiplied by 100 to get two decimal places
    u8 Local_u8FractionalPartAsInteger = (u8)(Local_f32FractionalPart * 100);
    LCD_voidWriteDecimal(Local_u8FractionalPartAsInteger);
}


void LCD_voidWriteCustomCharacter(u8 copy_u8PatternNumber, u8 copy_pu8PatternArr[], u8 copy_u8YPos, u8 copy_u8XPos)
{
	if ( copy_pu8PatternArr != NULL )
	{
		u8 Local_u8CGRAM_Address = copy_u8PatternNumber * 8;
		u8 Local_u8Counter = 0;

		/* Set Bit 6 & Clear Bit 7 for Setting CGRAM Address Command */
		SET_BIT(Local_u8CGRAM_Address , 6) ;

		/* Set CGRAM Address */
		Send_voidCommand(Local_u8CGRAM_Address);

		/* Write the pattern inside CGRAM */
		for (Local_u8Counter = 0; Local_u8Counter < 8; Local_u8Counter ++)
		{
			Send_voidData(copy_pu8PatternArr[Local_u8Counter]);
		}

		/* Set DDRAM Address */
		LCD_voidGoToXY(copy_u8YPos , copy_u8XPos);

		/* Write the corresponding pattern number to display from CGRAM */
		Send_voidData(copy_u8PatternNumber);
	}
}




