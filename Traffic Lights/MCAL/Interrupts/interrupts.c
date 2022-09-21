/*
 * interrupts.c
 *
 * Created: 9/12/2022 10:59:36 PM
 *  Author: Jonathan
 */ 
#include "interrupts.h"

void INT_init(void)
{
	// Enable global interrupt
	sei();	
	//Choosing Interrupt sense to be rising edge
	MCUCR |= (1<<0) | (1 << 1);
	
	//Enable external interrupt
	GICR |= (1 << 6);		
	
}



