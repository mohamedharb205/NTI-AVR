/*****************************************************************************************/
/*****************************************************************************************/
/***********************		AUTHOR	:	MOHAMED HARB		**************************/
/***********************		LAYER	:	APP					**************************/
/***********************		SWC		:	MAIN				**************************/
/***********************		DATE	:	OCT 21, 2023		**************************/
/***********************		VERSION	:	V01					**************************/
/*****************************************************************************************/
/*****************************************************************************************/



#include "00-main.h"

#include "util/delay.h"



int main()
{
	#if		MAIN_APP == KPD_TEST
			KeyPad_test();

	#else
	#endif



	return 0;
}
