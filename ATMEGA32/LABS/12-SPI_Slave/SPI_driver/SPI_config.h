/*****************************************************************************************/
/*****************************************************************************************/
/***********************		AUTHOR	:	MOHAMED HARB		**************************/
/***********************		LAYER	:	MCAL				**************************/
/***********************		SWC		:	SPI					**************************/
/***********************		DATE	:	OCT 30, 2023		**************************/
/***********************		VERSION	:	V01					**************************/
/*****************************************************************************************/
/*****************************************************************************************/


#ifndef SPI_DRIVER_SPI_CONFIG_H_
#define SPI_DRIVER_SPI_CONFIG_H_


/***************************************************************************/
/********		CONFIGURATION OF SPI NODE TYPE:						********/
/********										1- MASTER			********/
/********										2- SLAVE			********/
/***************************************************************************/
#define SPI_NODE_TYPE		SLAVE


/***************************************************************************/
/********		CONFIGURATION OF SPI DATA ORDER:					********/
/********										1- LSB				********/
/********										2- MSB				********/
/***************************************************************************/
#define SPI_DATA_ORDER		LSB


/***************************************************************************/
/********		CONFIGURATION OF SPI CLOCK POLARITY:				********/
/********										1- IDLE_LOW			********/
/********										2- IDEL_HIGH		********/
/***************************************************************************/
#define SPI_CLOCK_POLARITY		IDLE_LOW


/***************************************************************************/
/********		CONFIGURATION OF SPI CLOCK PHASE:					********/
/********										1- SAMPLE			********/
/********										2- SETUP			********/
/***************************************************************************/
#define SPI_CLOCK_PHASE		SAMPLE


/***************************************************************************/
/********		CONFIGURATION OF SPI PRESCALER:						********/
/********										1- DIVIDED_BY_2		********/
/********										2- DIVIDED_BY_4		********/
/********										2- DIVIDED_BY_8		********/
/********										2- DIVIDED_BY_16	********/
/********										2- DIVIDED_BY_32	********/
/********										2- DIVIDED_BY_64	********/
/********										2- DIVIDED_BY_128	********/
/***************************************************************************/
#define SPI_PRESCALER		DIVIDED_BY_2


/***************************************************************************/
/********		CONFIGURATION OF SPI INTERRUPT:						********/
/********										1- ENABLED			********/
/********										2- DISABLED			********/
/***************************************************************************/
#define SPI_INTERRUPT_STATUS		DISABLED




#endif /* SPI_DRIVER_SPI_CONFIG_H_ */