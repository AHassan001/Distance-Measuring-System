/******************************************************************************
 *
 * Module: Ultra Sonic
 *
 * File Name: ultra_sonic.c
 *
 * Description: Ultra sonic driver
 *
 * Author: Abdelrahman Maher
 *
 ******************************************************************************/

#include "ultra_sonic.h"
#include "icu.h"
#include "gpio.h"
#include "util/delay.h"
#include "avr/io.h"

uint8 g_edgeCount = 0;
uint16 g_EchoTime = 0;


void Ultrasonic_init(void)
{
	Icu_ConfigType Icu_Config = {F_CPU_8,RISING};

	Icu_init (&Icu_Config);
	Icu_setCallBack(Ultrasonic_edgeProcessing);

	GPIO_setupPinDirection(TRIGGER_PORT_ID, TRIGGER_PIN_ID, PIN_OUTPUT);
	GPIO_writePin(TRIGGER_PORT_ID, TRIGGER_PIN_ID, LOGIC_LOW);
}

void Ultrasonic_Trigger(void)
{
	GPIO_writePin(TRIGGER_PORT_ID, TRIGGER_PIN_ID, LOGIC_HIGH);
	_delay_us(10);
	GPIO_writePin(TRIGGER_PORT_ID, TRIGGER_PIN_ID, LOGIC_LOW);
}

uint16 Ultrasonic_readDistance(void)
{
	uint16 distance = 0;
	Ultrasonic_Trigger();
	distance = g_EchoTime * 0.17;

	return distance;
}

void Ultrasonic_edgeProcessing(void)
{
	g_edgeCount++;

	if(g_edgeCount == 1)
	{
		Icu_clearTimerValue();
		Icu_setEdgeDetectionType(FALLING);
	}
	else if(g_edgeCount == 2)
	{
		g_EchoTime=Icu_getInputCaptureValue();
		Icu_clearTimerValue();
		Icu_setEdgeDetectionType(RISING);
		g_edgeCount=0;
	}

}

