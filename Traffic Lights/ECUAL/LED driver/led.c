/*
 * led.c
 *
 * Created: 9/12/2022 6:15:02 PM
 *  Author: Jonathan
 */ 

#include "led.h"

void LED_init(uint8_t ledPin, uint8_t ledPort)
{
	DIO_init(ledPin,ledPort,OUT);
}

void LED_ON(uint8_t ledPin, uint8_t ledPort)
{
	DIO_write(ledPin,ledPort,HIGH);
}
void LED_OFF(uint8_t ledPin, uint8_t ledPort)
{
		DIO_write(ledPin,ledPort,LOW);

}
void LED_toggle(uint8_t ledPin, uint8_t ledPort)
{
	DIO_toggle(ledPin,ledPort);
}

void LED_state_time(uint16_t time)
{
	TIMER_delay(time);
}
