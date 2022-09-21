/*
 * app.c
 *
 * Created: 9/12/2022 11:48:03 PM
 *  Author: Jonathan
 */ 
#include "app.h"
//Variable to detect mode
traffic_Mode mode = NORMAL;

//Variables to trace the sequence of lights
car_LED carLED;
car_LED previousLED;
//Flag to check if Pedestrian mode is done
PED_status flag = UNDONE;
void App_init(void)
{
	//Initializing interrupts
	INT_init();
	
	//Initializing Car Traffic LEDs
	LED_init(GREEN_LED_PIN,CAR_LED_PORT);
	LED_init(YELLOW_LED_PIN,CAR_LED_PORT);
	LED_init(RED_LED_PIN,CAR_LED_PORT);
	
	//Initializing Pedestrian Traffic LEDs
	LED_init(GREEN_LED_PIN,PED_LED_PORT);
	LED_init(YELLOW_LED_PIN,PED_LED_PORT);
	LED_init(RED_LED_PIN,PED_LED_PORT);
	
	//Initializing Button
	button_init(BUTTON_PIN,BUTTON_PORT);
	
}

void App_start(void)
{
	if(mode == NORMAL)
	{
		switch(carLED)
		{	
			//In Case the green light will operate
		
			case GREEN:
			LED_ON(GREEN_LED_PIN,CAR_LED_PORT); //Turning ON green light
		
			for(int i = 0; i < 100; i++)
			{
				LED_state_time(49);					// Total delay 4900 ms 
				if(mode == PED)						//Checking if the Button is pressed
				break;
			}		
			LED_OFF(GREEN_LED_PIN,CAR_LED_PORT);	//Turning OFF green light
			previousLED = GREEN;						//The Current light
			carLED = YELLOW;						//The next light to be operated
			break;
		
			//In Case the yellow light will operate

			case YELLOW:
			LED_ON(YELLOW_LED_PIN, CAR_LED_PORT);	//Turning ON yellow light
			for(int i = 0; i < 10; i++)
			{
				for(int j = 0; j < 10; j++) 
				{
					LED_state_time(49); //Total time 4900 ms
					if(mode == PED) //Checking if the button is pressed
					{ 
						i = 10;
						break;
					}
				}
				LED_toggle(YELLOW_LED_PIN, CAR_LED_PORT);
			}
			LED_OFF(YELLOW_LED_PIN,CAR_LED_PORT);
			if(previousLED == GREEN) //The next light to be operated
			carLED = RED;			
			else
			carLED = GREEN;				
			previousLED = YELLOW;
			break;
		
			//In Case the red light will operate

			case RED:
			LED_ON(RED_LED_PIN,CAR_LED_PORT);
			for(int i = 0; i < 100; i++)
			{
				LED_state_time(49); // Total delay 4900 ms
				if(mode == PED)  //Checking if the Button is pressed
				break;
			}		
			LED_OFF(RED_LED_PIN,CAR_LED_PORT);
			previousLED = RED;						//The Current light
			carLED = YELLOW;						//The next light to be operated
			break;
		}
		
			}
		else
		{
				
		switch(previousLED)
		{
			//If the button was pressed while the cars' red light was ON 
			case RED:
			//Turning ON Green for pedestrian and red for cars
			greenPED_redCars();	
			
			
			//Turning ON blinking yellow light for both pedestrian and cars
			yellowBOTH();
			
			//Turning ON Green for cars and red for pedestrian
			redPED_greenCars();
			
			//Determine next light to be operated in Normal mode
			previousLED = GREEN;
			carLED = YELLOW;
			
			flag = DONE;
			break;
			
			
			//If the button was pressed while the cars' green or yellow light was ON
			case GREEN:
			case YELLOW:
			//Turning ON blinking yellow light for both pedestrian and cars
			yellowBOTH();
			
			//Turning ON Green for pedestrian and red for cars
			greenPED_redCars();
			
			//Turning ON blinking yellow light for both pedestrian and cars
			yellowBOTH();
						
			//Turning ON Green for cars and red for pedestrian
			redPED_greenCars();
			
			//Determine next light to be operated in Normal mode
			previousLED = GREEN;
			carLED = YELLOW;
			
			flag = DONE;
			break;
			
			
				
			
		
		
		}
		
		
			
	}
	
	
	//Returning to first state
	if(mode == PED && flag == DONE)
	{

			mode = NORMAL;
			flag = UNDONE;
	}
	
}
	
void greenPED_redCars(void)
{
			LED_ON(GREEN_LED_PIN, PED_LED_PORT);
			LED_ON(RED_LED_PIN, CAR_LED_PORT);
			LED_state_time(4900);
			LED_OFF(GREEN_LED_PIN, PED_LED_PORT);
			LED_OFF(RED_LED_PIN, CAR_LED_PORT);
}

void yellowBOTH(void)
{
	LED_ON(YELLOW_LED_PIN,CAR_LED_PORT);
	LED_ON(YELLOW_LED_PIN,PED_LED_PORT);
	for(int i = 0; i < 10; i++)
	{
		LED_state_time(490);
		LED_toggle(YELLOW_LED_PIN, CAR_LED_PORT);
		LED_toggle(YELLOW_LED_PIN, PED_LED_PORT);
	}
	LED_OFF(YELLOW_LED_PIN,CAR_LED_PORT);
	LED_OFF(YELLOW_LED_PIN,PED_LED_PORT);
}

void redPED_greenCars(void)
{
				LED_ON(RED_LED_PIN, PED_LED_PORT);
				LED_ON(GREEN_LED_PIN, CAR_LED_PORT);
				LED_state_time(4900);
				LED_OFF(RED_LED_PIN, PED_LED_PORT);
				LED_OFF(GREEN_LED_PIN, CAR_LED_PORT);
}
	
	


ISR(EXT_INT_0)
{
	mode = PED;
	return;
}