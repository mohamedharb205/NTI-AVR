/*****************************************************************************************/
/*****************************************************************************************/
/***********************		AUTHOR	:	MOHAMED HARB		**************************/
/***********************		LAYER	:	APP					**************************/
/***********************		SWC		:	SSD					**************************/
/***********************		DATE	:	OCT 20, 2023		**************************/
/***********************		VERSION	:	V01					**************************/
/*****************************************************************************************/
/*****************************************************************************************/


#include "../SSD_driver/STD_TYPES.h"
#include "../SSD_driver/SEVEN_SEGMENT_interface.h"


void Display9999Number(void)
{
	SevenSegment_voidInit();

	while(1)
	{
		//SevenSegmentBCD_voidWriteNumber(1234);
		//_delay_ms(200);

		for(u16 i = 0; i < 10000; i++)
		{
			for(u8 j = 0 ; j < 5 ; j++ )	// this is a delay = 10 iterations * 20ms >>>> 200ms
			{
				SevenSegmentBCD_voidWriteNumber(i);	// don't use _delay_ms(200); it brokes down the processor
			}
		}

		for(u16 i = 10000; i >= 0; i++)
		{
			for(u8 j = 0 ; j < 5 ; j++ )	// this is a delay = 10 iterations * 20ms >>>> 200ms
			{
				SevenSegmentBCD_voidWriteNumber(i);	// don't use _delay_ms(200); it brokes down the processor
			}
		}
	}
}




