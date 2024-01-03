 /******************************************************************************
 *
 * File Name: Mini_Project4.c
 *
 * Description: Main function of Mini Project 4
 *
 * Author: Abdelrahman Maher
 *
 ******************************************************************************/
#include "lcd.h"
#include "ultra_sonic.h"
#include "avr/io.h"

int main(void)
{
	uint8 distance = 0;
	uint8 prev_distance=0;


	SREG|=(1<<7);

	LCD_init();
	Ultrasonic_init();


	LCD_displayStringRowColumn(0, 1, "Distance=    cm");

	while(1)
	{
		distance = Ultrasonic_readDistance();
	if (distance == prev_distance)
	{

	}
	else
	{
		LCD_moveCursor(0, 11);
		if (distance >= 100)
		{
			LCD_intgerToString(distance);
		}
		else
		{
			LCD_intgerToString(distance);
			LCD_displayString(" ");
		}
	distance = prev_distance;
	}
	}
}
