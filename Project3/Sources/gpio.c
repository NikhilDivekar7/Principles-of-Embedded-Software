/*@file - gpio.c
 *@brief - Contains all the gpio functions connecting to nrf
 *@author Vipraja Patil & Nikhil Divekar
 *@date 3 December 2017*/

#include "dma.h"
#include "memory.h"
#include "stdlib.h"
#include "MKL25Z4.h"
#include "gpio.h"
#include "logger.h"
#include "buffer.h"

LoggedItem_t * logged_data;
CB_struct_t * Tx;

void GPIO_nrf_init()
{
	// Enable Clock for PortC
	SIM->SCGC5 |= SIM_SCGC5_PORTC_MASK;

	//Configuring PORT C PIN 4 to GPIO using MUX and use as slave select
	PORTC->PCR[4] = PORT_PCR_MUX(1);

	// Configuring PORT C PIN 3 to GPIO using MUX and use as transmit enable
	PORTC->PCR[3] = PORT_PCR_MUX(1);

	//PortC Pin 4 is configured as general-purpose output, for the GPIO function
	GPIOC->PDDR |= (1 << 4);

	//Corresponding bit in PDORn is set to logic 1
	GPIOC->PSOR |= (1 << 4);

	//PortC Pin 3 is configured as general-purpose output, for the GPIO function
	GPIOC->PDDR |= (1 << 3);

	//Corresponding bit in PDORn is set to logic 1
	GPIOC->PSOR |= (1 << 3);

//	logged_data = (LoggedItem_t *) malloc(sizeof(LoggedItem_t));
//	create_log(logged_data, GPIO_INITIALIZED, 1,1);
//	log_item(Tx, logged_data);
}
