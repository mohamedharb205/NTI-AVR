/*****************************************************************************************/
/*****************************************************************************************/
/***********************		AUTHOR	:	MOHAMED HARB		**************************/
/***********************		LAYER	:	APP					**************************/
/***********************		DES.	:	STORY PROJECT		**************************/
/***********************		DATE	:	3-11-2023			**************************/
/***********************		VERSION	:	V01					**************************/
/*****************************************************************************************/
/*****************************************************************************************/

#ifndef F_CPU
#define F_CPU	8000000
#endif

#include "../LIB/STD_TYPES.h"
#include "../HAL/LCD/LCD_interface.h"
#include "../HAL/LCD/LCD_config.h"
#include "util/delay.h"

u8 Hamoksha[] = { 0x04, 0x0A, 0x04, 0x1F, 0x04, 0x04, 0x0A, 0x00 };
u8 Dance1[] = {0x04, 0x0A, 0x04, 0x0E, 0x15, 0x04, 0x0A, 0x00};
u8 Dance2[] = {0x04, 0x0A, 0x05, 0x0E, 0x14, 0x04, 0x0E, 0x00};
u8 Dance3[] = {0x04, 0x0A, 0x14, 0x0E, 0x05, 0x04, 0x0E, 0x00};
u8 Dance4[] = {0x04, 0x0A, 0x15, 0x0E, 0x04, 0x04, 0x0E, 0x00};
u8 Dance5[] = {0x04, 0x0A, 0x04, 0x0E, 0x15, 0x04, 0x0E, 0x00};
u8 Dance6[] = {0x04, 0x0A, 0x04, 0x0E, 0x15, 0x04, 0x0A, 0x00};
u8 Dance7[] = {0x04, 0x0A, 0x04, 0x0E, 0x15, 0x04, 0x0E, 0x00};
u8 Dance8[] = {0x04, 0x0A, 0x04, 0x0E, 0x0E, 0x04, 0x0E, 0x00};


u8 Heart[] = {0x00, 0x0A, 0x15, 0x11, 0x0A, 0x04, 0x00, 0x00};
u8 Smile[] = {0x00, 0x00, 0x0A, 0x00, 0x11, 0x0E, 0x00, 0x00};

u8 Hazalkom[] = { 0x0E, 0x0E, 0x04, 0x0E, 0x15, 0x04, 0x0E, 0x00 };
u8 Sad[] = { 0x0E, 0x0E, 0x04, 0x0E, 0x0E, 0x04, 0x0E, 0x00 };
u8 Sit[] = { 0x00, 0x00, 0x0E, 0x0E, 0x04, 0x0E, 0x0A, 0x00 };

u8 True[] = { 0x00, 0x00, 0x01, 0x02, 0x14, 0x08, 0x00, 0x00 };
u8 False[] = { 0x00, 0x11, 0x0A, 0x04, 0x0A, 0x11, 0x00, 0x00 };

int main()
{

	LCD_voidInit();

	/*Welcome*/
	LCD_voidWriteStringAtXY("HELLO ...", 0, 0);
	LCD_voidWriteStringAtXY("Welcome Everybody", 1, 0);
	LCD_voidWriteStringAtXY("I'm Mohamed Harb", 2, 0);
	LCD_voidWriteCustomCharacter(0, Smile, 3, 7);
	LCD_voidWriteCustomCharacter(0, Smile, 3, 9);
	LCD_voidWriteCustomCharacter(0, Smile, 3, 11);
	_delay_ms(1500);
	LCD_voidClear();

	LCD_voidWriteStringAtXY("I will tell you", 0, 0);
	LCD_voidWriteStringAtXY("a short story about:", 1, 0);
	LCD_voidWriteStringAtXY("1- Hamoksha", 2, 0);
	LCD_voidWriteCustomCharacter(0, Hamoksha, 2, 16);
	LCD_voidWriteStringAtXY("2- Hazalkom", 3, 0);
	LCD_voidWriteCustomCharacter(1, Hazalkom, 3, 16);
	_delay_ms(1500);
	LCD_voidClear();

	/*Story*/
	LCD_voidWriteStringAtXY("They are Friends", 0, 0);
	LCD_voidWriteStringAtXY("....... and .......", 1, 0);
	LCD_voidWriteStringAtXY("They love Embedded", 2, 0);
	LCD_voidWriteStringAtXY("Systems Field, So ..", 3, 0);
	_delay_ms(2000);
	LCD_voidClear();

	/*NTI Application*/
	LCD_voidWriteStringAtXY("They applied to NTI", 0, 0);
	LCD_voidWriteCustomCharacter(0, Hamoksha, 1, 0);
	LCD_voidWriteStringAtXY("NTI", 2, 9);
	LCD_voidWriteCustomCharacter(1, Hazalkom, 3, 0);
	_delay_ms(100);
	LCD_voidWriteCharacterAtXY(' ', 1, 0);
	LCD_voidWriteCharacterAtXY(' ', 3, 0);
	LCD_voidWriteCustomCharacter(0, Hamoksha, 1, 1);
	LCD_voidWriteCustomCharacter(1, Hazalkom, 3, 1);
	_delay_ms(100);
	LCD_voidWriteCharacterAtXY(' ', 1, 1);
	LCD_voidWriteCharacterAtXY(' ', 3, 1);
	LCD_voidWriteCustomCharacter(0, Hamoksha, 1, 2);
	LCD_voidWriteCustomCharacter(1, Hazalkom, 3, 2);
	_delay_ms(100);
	LCD_voidWriteCharacterAtXY(' ', 1, 2);
	LCD_voidWriteCharacterAtXY(' ', 3, 2);
	LCD_voidWriteCustomCharacter(0, Hamoksha, 1, 3);
	LCD_voidWriteCustomCharacter(1, Hazalkom, 3, 3);
	_delay_ms(100);
	LCD_voidWriteCharacterAtXY(' ', 1, 3);
	LCD_voidWriteCharacterAtXY(' ', 3, 3);
	LCD_voidWriteCustomCharacter(0, Hamoksha, 1, 4);
	LCD_voidWriteCustomCharacter(1, Hazalkom, 3, 4);
	_delay_ms(100);
	LCD_voidWriteCharacterAtXY(' ', 1, 4);
	LCD_voidWriteCharacterAtXY(' ', 3, 4);
	LCD_voidWriteCustomCharacter(0, Hamoksha, 1, 5);
	LCD_voidWriteCustomCharacter(1, Hazalkom, 3, 5);
	_delay_ms(100);
	LCD_voidWriteCharacterAtXY(' ', 1, 5);
	LCD_voidWriteCharacterAtXY(' ', 3, 5);
	LCD_voidWriteCustomCharacter(0, Hamoksha, 1, 6);
	LCD_voidWriteCustomCharacter(1, Hazalkom, 3, 6);
	_delay_ms(100);
	LCD_voidWriteCharacterAtXY(' ', 1, 6);
	LCD_voidWriteCharacterAtXY(' ', 3, 6);
	LCD_voidWriteCustomCharacter(0, Hamoksha, 1, 7);
	LCD_voidWriteCustomCharacter(1, Hazalkom, 3, 7);
	_delay_ms(100);
	LCD_voidWriteCharacterAtXY(' ', 1, 7);
	LCD_voidWriteCharacterAtXY(' ', 3, 7);
	LCD_voidWriteCustomCharacter(0, Hamoksha, 1, 8);
	LCD_voidWriteCustomCharacter(1, Hazalkom, 3, 8);
	_delay_ms(100);
	LCD_voidWriteCharacterAtXY(' ', 1, 8);
	LCD_voidWriteCustomCharacter(0, Hamoksha, 1, 12);
	_delay_ms(100);
	LCD_voidWriteCharacterAtXY(' ', 1, 12);
	LCD_voidWriteCustomCharacter(0, Hamoksha, 1, 13);
	_delay_ms(100);
	LCD_voidWriteCharacterAtXY(' ', 1, 13);
	LCD_voidWriteCustomCharacter(0, Hamoksha, 1, 14);
	_delay_ms(100);
	LCD_voidWriteCharacterAtXY(' ', 1, 14);
	LCD_voidWriteCustomCharacter(0, Hamoksha, 1, 15);
	_delay_ms(100);
	LCD_voidWriteCharacterAtXY(' ', 1, 15);
	LCD_voidWriteCustomCharacter(0, Hamoksha, 1, 16);
	_delay_ms(100);
	LCD_voidWriteCharacterAtXY(' ', 1, 16);
	LCD_voidWriteCustomCharacter(0, Hamoksha, 1, 17);
	_delay_ms(100);
	LCD_voidWriteCharacterAtXY(' ', 1, 17);
	LCD_voidWriteCharacterAtXY(' ', 3, 8);
	LCD_voidWriteCustomCharacter(0, Hamoksha, 1, 18);
	LCD_voidWriteCustomCharacter(1, Hazalkom, 3, 18);
	LCD_voidWriteCustomCharacter(2, True, 1, 19);
	LCD_voidWriteCustomCharacter(3, False, 3, 19);

	_delay_ms(1000);
	LCD_voidClear();


	/*NTI Result*/
	/*Hamoksha accepted*/
	LCD_voidWriteStringAtXY("Hmoksha was accepted", 0, 0);
	LCD_voidWriteStringAtXY("So, He was Pleased", 1, 0);

	LCD_voidWriteCustomCharacter(0, Hamoksha, 3, 8);
	LCD_voidWriteCustomCharacter(0, Hamoksha, 3, 9);
	LCD_voidWriteCustomCharacter(0, Hamoksha, 3, 10);
	LCD_voidWriteCustomCharacter(0, Hamoksha, 3, 11);
	_delay_ms(100);
	LCD_voidWriteCustomCharacter(0, Dance1, 3, 8);
	LCD_voidWriteCustomCharacter(0, Dance1, 3, 9);
	LCD_voidWriteCustomCharacter(0, Dance1, 3, 10);
	LCD_voidWriteCustomCharacter(0, Dance1, 3, 11);
	_delay_ms(100);
	LCD_voidWriteCustomCharacter(0, Dance2, 3, 8);
	LCD_voidWriteCustomCharacter(0, Dance2, 3, 9);
	LCD_voidWriteCustomCharacter(0, Dance2, 3, 10);
	LCD_voidWriteCustomCharacter(0, Dance2, 3, 11);
	_delay_ms(100);
	LCD_voidWriteCustomCharacter(0, Dance3, 3, 8);
	LCD_voidWriteCustomCharacter(0, Dance3, 3, 9);
	LCD_voidWriteCustomCharacter(0, Dance3, 3, 10);
	LCD_voidWriteCustomCharacter(0, Dance3, 3, 11);
	_delay_ms(100);
	LCD_voidWriteCustomCharacter(0, Dance4, 3, 8);
	LCD_voidWriteCustomCharacter(0, Dance4, 3, 9);
	LCD_voidWriteCustomCharacter(0, Dance4, 3, 10);
	LCD_voidWriteCustomCharacter(0, Dance4, 3, 11);
	_delay_ms(100);
	LCD_voidWriteCustomCharacter(0, Dance5, 3, 8);
	LCD_voidWriteCustomCharacter(0, Dance5, 3, 9);
	LCD_voidWriteCustomCharacter(0, Dance5, 3, 10);
	LCD_voidWriteCustomCharacter(0, Dance5, 3, 11);
	_delay_ms(100);
	LCD_voidWriteCustomCharacter(0, Dance6, 3, 8);
	LCD_voidWriteCustomCharacter(0, Dance6, 3, 9);
	LCD_voidWriteCustomCharacter(0, Dance6, 3, 10);
	LCD_voidWriteCustomCharacter(0, Dance6, 3, 11);
	_delay_ms(100);
	LCD_voidWriteCustomCharacter(0, Dance7, 3, 8);
	LCD_voidWriteCustomCharacter(0, Dance7, 3, 9);
	LCD_voidWriteCustomCharacter(0, Dance7, 3, 10);
	LCD_voidWriteCustomCharacter(0, Dance7, 3, 11);
	_delay_ms(100);
	LCD_voidWriteCustomCharacter(0, Dance8, 3, 8);
	LCD_voidWriteCustomCharacter(0, Dance8, 3, 9);
	LCD_voidWriteCustomCharacter(0, Dance8, 3, 10);
	LCD_voidWriteCustomCharacter(0, Dance8, 3, 11);
	_delay_ms(100);

	_delay_ms(500);
	LCD_voidClear();


	/* Hazalkom rejected*/
	LCD_voidWriteStringAtXY("Hzlkom was rejected", 0, 0);
	LCD_voidWriteStringAtXY("So, He was Sad !!!", 1, 0);
	LCD_voidWriteCustomCharacter(1, Hazalkom, 3, 8);
	LCD_voidWriteCustomCharacter(1, Hazalkom, 3, 9);
	LCD_voidWriteCustomCharacter(1, Hazalkom, 3, 10);
	LCD_voidWriteCustomCharacter(1, Hazalkom, 3, 11);
	_delay_ms(100);
	LCD_voidWriteCustomCharacter(1, Sad, 3, 8);
	LCD_voidWriteCustomCharacter(1, Sad, 3, 9);
	LCD_voidWriteCustomCharacter(1, Sad, 3, 10);
	LCD_voidWriteCustomCharacter(1, Sad, 3, 11);
	_delay_ms(100);
	LCD_voidWriteCustomCharacter(1, Sit, 3, 8);
	LCD_voidWriteCustomCharacter(1, Sit, 3, 9);
	LCD_voidWriteCustomCharacter(1, Sit, 3, 10);
	LCD_voidWriteCustomCharacter(1, Sit, 3, 11);
	_delay_ms(100);
	LCD_voidWriteCustomCharacter(1, Hazalkom, 3, 8);
	LCD_voidWriteCustomCharacter(1, Hazalkom, 3, 9);
	LCD_voidWriteCustomCharacter(1, Hazalkom, 3, 10);
	LCD_voidWriteCustomCharacter(1, Hazalkom, 3, 11);
	_delay_ms(100);
	LCD_voidWriteCustomCharacter(1, Sad, 3, 8);
	LCD_voidWriteCustomCharacter(1, Sad, 3, 9);
	LCD_voidWriteCustomCharacter(1, Sad, 3, 10);
	LCD_voidWriteCustomCharacter(1, Sad, 3, 11);
	_delay_ms(100);
	LCD_voidWriteCustomCharacter(1, Sit, 3, 8);
	LCD_voidWriteCustomCharacter(1, Sit, 3, 9);
	LCD_voidWriteCustomCharacter(1, Sit, 3, 10);
	LCD_voidWriteCustomCharacter(1, Sit, 3, 11);
	_delay_ms(1000);
	LCD_voidClear();


	/*The End*/
	LCD_voidWriteStringAtXY("What is your advice", 0, 0);
	LCD_voidWriteStringAtXY("to both of them .. ?", 2, 0);
	_delay_ms(1500);
	LCD_voidClear();

	/*comment*/
	LCD_voidWriteStringAtXY("Please leave your", 0, 0);
	LCD_voidWriteStringAtXY("comment under this", 1, 0);
	LCD_voidWriteStringAtXY("Video ... ", 2, 0);
	_delay_ms(1500);
	LCD_voidClear();

	/*Thanks*/
	LCD_voidWriteStringAtXY("Thanks for your help", 1, 0);

	LCD_voidWriteCustomCharacter(7, Heart, 3, 7);
	LCD_voidWriteCustomCharacter(7, Heart, 3, 9);
	LCD_voidWriteCustomCharacter(7, Heart, 3, 11);
	//_delay_ms(1000);
	//LCD_voidClear();

	return 0;
}
