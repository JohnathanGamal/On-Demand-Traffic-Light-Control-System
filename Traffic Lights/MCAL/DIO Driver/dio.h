/*
 * dio.h
 *
 * Created: 9/11/2022 5:07:40 PM
 *  Author: Jonathan
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../../Utilities/registers.h"
// Driver Macros
//Ports
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

//Direction defines
#define IN 0
#define OUT 1

//Value defines
#define LOW 0
#define HIGH 1




//Driver function prototypes

void DIO_init(uint8_t pinNumber, uint8_t portNumber, uint8_t direction ); //Initialize DIO direction
void DIO_write(uint8_t pinNumber, uint8_t portNumber, uint8_t value); //Write data to DIO
void DIO_toggle(uint8_t pinNumber, uint8_t portNumber); //Toggle DIO
void DIO_read(uint8_t pinNumber, uint8_t portNumber, uint8_t* value); //Read data from DIO



#endif /* DIO_H_ */