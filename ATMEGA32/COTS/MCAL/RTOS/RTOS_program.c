/*
 * RTOS_program.c
 *
 *  Created on: Nov 26, 2023
 *      Author: EngMoS
 */


#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "GIE_interface.h"
#include "TIMER0_interface.h"
#include "RTOS_interface.h"
#include "RTOS_private.h"
#include "RTOS_config.h"



static Task_t Tasks[Num_Of_Tasks];	// = {{0,0,0,NULL}};
//static u16 Tick_Counter = 0;


void RTOS_voidInit(void)	// Initialize the timer
{

}


void RTOS_voidStart(void)	// Start the timer
{
	// open the GIE at the timer init
	Timer0_voidInit();
	Timer0_voidCallBack(&Schedular);
}


void RTOS_voidStop(void)	// Stop the timer
{
	// stop the timer
	// or disable the global interrupt
	GIE_voidDisableGlobal();
}



void RTOS_voidCreateTask(u8 Copy_u8Periorty, u32 Copy_u16Periodicity, u8 Copy_u8FirstDelay, void (*Copy_pvTaskFunc)(void))
{
	if(Copy_pvTaskFunc != NULL)
	{
		Tasks[Copy_u8Periorty].Periodicity = Copy_u16Periodicity;
		Tasks[Copy_u8Periorty].FirstDelay = Copy_u8FirstDelay;
		Tasks[Copy_u8Periorty].TaskFun = Copy_pvTaskFunc;
	}
}


void RTOS_voidDeleteTask(u8 Copy_u8Periorty, u32 Copy_u16Periodicity, void (*Copy_pvTaskFunc)(void))	// Make the function = NULL
{
	Tasks[Copy_u8Periorty].Periodicity = Copy_u16Periodicity;
	Tasks[Copy_u8Periorty].TaskFun = Copy_pvTaskFunc;
}




static void Schedular(void)
{
	//Tick_Counter ++;
	for(u8 Local_u8Counter = 0; Local_u8Counter < Num_Of_Tasks; Local_u8Counter++)
	{
		if(Tasks[Local_u8Counter].FirstDelay == 0)	//(Tick_Counter % Tasks[Local_u8Counter].Periodicity) == 0)
		{
			Tasks[Local_u8Counter].TaskFun();	// Excute the function
			Tasks[Local_u8Counter].FirstDelay = (Tasks[Local_u8Counter].Periodicity) - 1;
		}

		else
		{
			Tasks[Local_u8Counter].FirstDelay --;
		}
	}
}

