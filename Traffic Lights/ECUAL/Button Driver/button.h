/*
 * button.h
 *
 * Created: 9/12/2022 8:08:34 PM
 *  Author: Jonathan
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO Driver/dio.h"
#include "../../MCAL/Interrupts/interrupts.h"
//Button Port and Pin
#define BUTTON_PIN PIN2
#define BUTTON_PORT PORT_D

void button_init(uint8_t buttonPin, uint8_t buttonPort); //Initializing Button


#endif /* BUTTON_H_ */