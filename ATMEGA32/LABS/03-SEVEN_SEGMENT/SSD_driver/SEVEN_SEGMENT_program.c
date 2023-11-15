/*****************************************************************************************/
/*****************************************************************************************/
/***********************		AUTHOR	:	MOHAMED HARB		**************************/
/***********************		LAYER	:	HAL					**************************/
/***********************		SWC		:	SEVEN SEGMENT		**************************/
/***********************		DATE	:	OCT 20, 2023		**************************/
/***********************		VERSION	:	V01					**************************/
/*****************************************************************************************/
/*****************************************************************************************/




#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SEVEN_SEGMENT_interface.h"
#include "SEVEN_SEGMENT_private.h"
#include "SEVEN_SEGMENT_config.h"

#include <avr/delay.h>



const u8 Numbers[10]={0b0000, 0b0001, 0b0010, 0b0011, 0b0100, 0b0101, 0b0110, 0b0111, 0b1000, 0b1001};


void SevenSegment_voidInit()
{
	/* Directions of BCD Pins */
	DIO_voidSetPinDirection(BCD_PORT, BCD_PIN_D0, DIO_u8PIN_OUTPUT);
	DIO_voidSetPinDirection(BCD_PORT, BCD_PIN_D1, DIO_u8PIN_OUTPUT);
	DIO_voidSetPinDirection(BCD_PORT, BCD_PIN_D2, DIO_u8PIN_OUTPUT);
	DIO_voidSetPinDirection(BCD_PORT, BCD_PIN_D3, DIO_u8PIN_OUTPUT);

	/* error >>> Don't forget the directions of Enable */
	DIO_voidSetPinDirection(ENABLE_PORT1, FIRST_SEVEN_SEGMENT_ENABLE_PIN , DIO_u8PIN_OUTPUT);
	DIO_voidSetPinDirection(ENABLE_PORT1, SECOND_SEVEN_SEGMENT_ENABLE_PIN, DIO_u8PIN_OUTPUT);
	DIO_voidSetPinDirection(ENABLE_PORT2, THIRD_SEVEN_SEGMENT_ENABLE_PIN , DIO_u8PIN_OUTPUT);
	DIO_voidSetPinDirection(ENABLE_PORT2, FOURTH_SEVEN_SEGMENT_ENABLE_PIN, DIO_u8PIN_OUTPUT);

	/* Enable all Seven Segments */
	DIO_voidSetPinValue(ENABLE_PORT1, FIRST_SEVEN_SEGMENT_ENABLE_PIN , DIO_u8PIN_LOW);
	DIO_voidSetPinValue(ENABLE_PORT1, SECOND_SEVEN_SEGMENT_ENABLE_PIN, DIO_u8PIN_LOW);
	DIO_voidSetPinValue(ENABLE_PORT2, THIRD_SEVEN_SEGMENT_ENABLE_PIN , DIO_u8PIN_LOW);
	DIO_voidSetPinValue(ENABLE_PORT2, FOURTH_SEVEN_SEGMENT_ENABLE_PIN, DIO_u8PIN_LOW);
}



void SevenSegmentBCD_voidWriteNumber(u16 copy_u16Number)
{
	if(copy_u16Number >= 0 && copy_u16Number <= 9)
	{
		BCD_To_7Segment((copy_u16Number), FIRST_SEVEN_SEGMENT);
		_delay_ms(20);
	}

	else if(copy_u16Number > 9 && copy_u16Number <= 99)
	{
		BCD_To_7Segment((copy_u16Number % 10), FIRST_SEVEN_SEGMENT);
		_delay_ms(10);
		BCD_To_7Segment((copy_u16Number / 10), SECOND_SEVEN_SEGMENT);
		_delay_ms(10);
	}

	else if(copy_u16Number > 99 && copy_u16Number <= 999)
	{
		BCD_To_7Segment((copy_u16Number % 10), FIRST_SEVEN_SEGMENT);
		copy_u16Number /= 10;
		_delay_ms(7);
		BCD_To_7Segment((copy_u16Number % 10), SECOND_SEVEN_SEGMENT);
		_delay_ms(7);
		BCD_To_7Segment((copy_u16Number / 10), THIRD_SEVEN_SEGMENT);
		_delay_ms(7);
	}

	else if(copy_u16Number > 999 && copy_u16Number <= 9999)
	{
		BCD_To_7Segment((copy_u16Number % 10), FIRST_SEVEN_SEGMENT);
		copy_u16Number /= 10;
		_delay_ms(5);
		BCD_To_7Segment((copy_u16Number % 10), SECOND_SEVEN_SEGMENT);
		copy_u16Number /= 10;
		_delay_ms(5);
		BCD_To_7Segment((copy_u16Number % 10), THIRD_SEVEN_SEGMENT);
		_delay_ms(5);
		BCD_To_7Segment((copy_u16Number / 10), FOURTH_SEVEN_SEGMENT);
		_delay_ms(5);
	}
}




void BCD_To_7Segment(u8 copy_u8Number, u8 copy_u8Display)
{
	if (copy_u8Display == FIRST_SEVEN_SEGMENT)
	{
		DIO_voidSetPinValue(ENABLE_PORT1, FIRST_SEVEN_SEGMENT_ENABLE_PIN , DIO_u8PIN_LOW);		// Enable SS1
		/* Disable the others */
		DIO_voidSetPinValue(ENABLE_PORT1, SECOND_SEVEN_SEGMENT_ENABLE_PIN, DIO_u8PIN_HIGH); 		// Disable SS2
		DIO_voidSetPinValue(ENABLE_PORT2, THIRD_SEVEN_SEGMENT_ENABLE_PIN , DIO_u8PIN_HIGH);		// Disable SS3
		DIO_voidSetPinValue(ENABLE_PORT2, FOURTH_SEVEN_SEGMENT_ENABLE_PIN, DIO_u8PIN_HIGH);		// Disable SS4

		DIO_voidSetPinValue(BCD_PORT, BCD_PIN_D0, GET_BIT(Numbers[copy_u8Number], 0));
		DIO_voidSetPinValue(BCD_PORT, BCD_PIN_D1, GET_BIT(Numbers[copy_u8Number], 1));
		DIO_voidSetPinValue(BCD_PORT, BCD_PIN_D2, GET_BIT(Numbers[copy_u8Number], 2));
		DIO_voidSetPinValue(BCD_PORT, BCD_PIN_D3, GET_BIT(Numbers[copy_u8Number], 3));
	}

	else if (copy_u8Display == SECOND_SEVEN_SEGMENT)
	{
		DIO_voidSetPinValue(ENABLE_PORT1, FIRST_SEVEN_SEGMENT_ENABLE_PIN , DIO_u8PIN_HIGH);		// Enable SS1
		DIO_voidSetPinValue(ENABLE_PORT1, SECOND_SEVEN_SEGMENT_ENABLE_PIN, DIO_u8PIN_LOW); 		// Enable SS2
		/* Disable the others */
		DIO_voidSetPinValue(ENABLE_PORT2, THIRD_SEVEN_SEGMENT_ENABLE_PIN , DIO_u8PIN_HIGH);		// Disable SS3
		DIO_voidSetPinValue(ENABLE_PORT2, FOURTH_SEVEN_SEGMENT_ENABLE_PIN, DIO_u8PIN_HIGH);		// Disable SS4

		DIO_voidSetPinValue(BCD_PORT, BCD_PIN_D0, GET_BIT(Numbers[copy_u8Number], 0));
		DIO_voidSetPinValue(BCD_PORT, BCD_PIN_D1, GET_BIT(Numbers[copy_u8Number], 1));
		DIO_voidSetPinValue(BCD_PORT, BCD_PIN_D2, GET_BIT(Numbers[copy_u8Number], 2));
		DIO_voidSetPinValue(BCD_PORT, BCD_PIN_D3, GET_BIT(Numbers[copy_u8Number], 3));
	}

	else if (copy_u8Display == THIRD_SEVEN_SEGMENT)
	{
		DIO_voidSetPinValue(ENABLE_PORT1, FIRST_SEVEN_SEGMENT_ENABLE_PIN , DIO_u8PIN_HIGH); 	// Enable SS1
		DIO_voidSetPinValue(ENABLE_PORT1, SECOND_SEVEN_SEGMENT_ENABLE_PIN, DIO_u8PIN_HIGH);		// Enable SS2
		DIO_voidSetPinValue(ENABLE_PORT2, THIRD_SEVEN_SEGMENT_ENABLE_PIN , DIO_u8PIN_LOW);		// Enable SS3
		/* Disable the others */
		DIO_voidSetPinValue(ENABLE_PORT2, FOURTH_SEVEN_SEGMENT_ENABLE_PIN, DIO_u8PIN_HIGH);		// Disable SS4

		DIO_voidSetPinValue(BCD_PORT, BCD_PIN_D0, GET_BIT(Numbers[copy_u8Number], 0));
		DIO_voidSetPinValue(BCD_PORT, BCD_PIN_D1, GET_BIT(Numbers[copy_u8Number], 1));
		DIO_voidSetPinValue(BCD_PORT, BCD_PIN_D2, GET_BIT(Numbers[copy_u8Number], 2));
		DIO_voidSetPinValue(BCD_PORT, BCD_PIN_D3, GET_BIT(Numbers[copy_u8Number], 3));
	}

	else if (copy_u8Display == FOURTH_SEVEN_SEGMENT)
	{
		DIO_voidSetPinValue(ENABLE_PORT1, FIRST_SEVEN_SEGMENT_ENABLE_PIN , DIO_u8PIN_HIGH); 	// Enable SS1
		DIO_voidSetPinValue(ENABLE_PORT1, SECOND_SEVEN_SEGMENT_ENABLE_PIN, DIO_u8PIN_HIGH);		// Enable SS2
		DIO_voidSetPinValue(ENABLE_PORT2, THIRD_SEVEN_SEGMENT_ENABLE_PIN , DIO_u8PIN_HIGH);		// Enable SS3
		DIO_voidSetPinValue(ENABLE_PORT2, FOURTH_SEVEN_SEGMENT_ENABLE_PIN, DIO_u8PIN_LOW);		// Enable SS4

		DIO_voidSetPinValue(BCD_PORT, BCD_PIN_D0, GET_BIT(Numbers[copy_u8Number], 0));
		DIO_voidSetPinValue(BCD_PORT, BCD_PIN_D1, GET_BIT(Numbers[copy_u8Number], 1));
		DIO_voidSetPinValue(BCD_PORT, BCD_PIN_D2, GET_BIT(Numbers[copy_u8Number], 2));
		DIO_voidSetPinValue(BCD_PORT, BCD_PIN_D3, GET_BIT(Numbers[copy_u8Number], 3));
	}
}

