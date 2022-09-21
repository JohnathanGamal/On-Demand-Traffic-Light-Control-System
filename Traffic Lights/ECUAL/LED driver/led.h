/*
 * led.h
 *
 * Created: 9/12/2022 6:15:25 PM
 *  Author: Jonathan
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO Driver/dio.h"
#include "../../MCAL/Timer Driver/timer.h"
//LEDs Ports
#define CAR_LED_PORT PORT_A
#define PED_LED_PORT PORT_B

//LEDs pins
#define GREEN_LED_PIN PIN0
#define YELLOW_LED_PIN PIN1
#define RED_LED_PIN PIN2




void LED_init(uint8_t ledPin, uint8_t ledPort);		//Initialize LEDs
void LED_ON(uint8_t ledPin, uint8_t ledPort);		//Turn ON LED
void LED_OFF(uint8_t ledPin, uint8_t ledPort);		//Turn OFF LED
void LED_toggle(uint8_t ledPin, uint8_t ledPort);	//Toggle LED state
void LED_state_time(uint16_t time);			//Determine LED's current state duration in ms



#endif /* LED_H_ */