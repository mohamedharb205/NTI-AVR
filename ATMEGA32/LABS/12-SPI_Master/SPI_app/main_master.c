/*****************************************************************************************/
/*****************************************************************************************/
/***********************		AUTHOR	:	MOHAMED HARB		**************************/
/***********************		LAYER	:	APP					**************************/
/***********************		SWC		:	MAIN				**************************/
/***********************		DATE	:	OCT 30, 2023		**************************/
/***********************		VERSION	:	V01					**************************/
/*****************************************************************************************/
/*****************************************************************************************/

#include "../SPI_driver/PORT_interface.h"
#include "../SPI_driver/DIO_interface.h"
#include "../SPI_driver/SPI_interface.h"
#include "avr/delay.h"


int main()
{
	PORT_voidInit();
	SPI_voidInit();

	while (1)
	{
		SPI_u8Transcieve(1);
		_delay_ms(500);
		SPI_u8Transcieve(0);
		_delay_ms(500);
	}

	return 0;
}
