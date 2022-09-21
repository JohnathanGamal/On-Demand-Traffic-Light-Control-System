/*
 * timer.c
 *
 * Created: 9/12/2022 11:01:48 AM
 *  Author: Jonathan
 */ 

#include "timer.h"
#include <math.h>



void TIMER_delay(uint16_t delayTime)
{
	//Set timer to normal mode
	TCCR0 = 0x00;
	
	//Calculate No. of overflows and timer starting value
	double tick = (double)1024/1000; //tick time in ms
	double maxDelay = tick * 256; //Max delay in ms
	int N = ceil((float)delayTime/maxDelay);
	int initValue = round(256 - ((double)delayTime/tick)/N);
	
	int overflows = 0;
	//Set timer initial value
	TCNT0 = initValue;
	
	//Set Prescaler to 1024
	TCCR0 = 0x05;
	
	while (overflows < N)
	{
		//Busywait for an overflow
		while((TIFR & (1<<0))>> 0  == 0);
		
		//clear overflow flag
		TIFR |=(1<<0);
		
		//Incrementing no of overflows
		overflows++;
		
	}
	overflows = 0;
	
	//End timer
	
	TCCR0 = 0x00;
}



