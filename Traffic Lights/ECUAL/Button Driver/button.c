/*
 * button.c
 *
 * Created: 9/12/2022 8:08:43 PM
 *  Author: Jonathan
 */ 

#include "button.h"

void button_init(uint8_t buttonPin, uint8_t buttonPort)
{
	DIO_init(buttonPin,buttonPort,IN);
	
}