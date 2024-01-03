 /******************************************************************************
 *
 * Module: Ultra Sonic
 *
 * File Name: ultra_sonic.h
 *
 * Description: Ultra sonic driver
 *
 * Author: Abdelrahman Maher
 *
 ******************************************************************************/


#ifndef ULTRA_SONIC_H_
#define ULTRA_SONIC_H_

#include "std_types.h"

#define TRIGGER_PORT_ID                PORTB_ID
#define TRIGGER_PIN_ID                 PIN5_ID

void Ultrasonic_init(void);

void Ultrasonic_Trigger(void);

uint16 Ultrasonic_readDistance(void);

void Ultrasonic_edgeProcessing(void);


#endif /* ULTRA_SONIC_H_ */
