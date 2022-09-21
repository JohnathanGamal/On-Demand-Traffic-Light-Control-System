/*
 * app.h
 *
 * Created: 9/12/2022 11:42:24 PM
 *  Author: Jonathan
 */ 


#ifndef APP_H_
#define APP_H_

#include "../ECUAL/LED driver/led.h"
#include "../ECUAL/Button Driver/button.h"

//enum to determine the mode
typedef enum traffic_Mode
{
	NORMAL,PED	
}traffic_Mode;

//enum to determine the traffic light color
typedef enum car_LED
{
	GREEN, YELLOW,RED
}car_LED;

//Pedestrian Mode status
typedef enum PED_status
{
	DONE, UNDONE
} PED_status;


void App_init(void);
void App_start(void);


void redPED_greenCars(void);	//Turning ON Red for pedestrian and Green for cars
void yellowBOTH(void);			//Turning ON blinking Yellow light for both pedestrian and cars
void greenPED_redCars(void); 	//Turning ON Green for pedestrian and Red for cars

#endif /* APP_H_ */