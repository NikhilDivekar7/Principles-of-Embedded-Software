/*@file - uart.c
 *@brief - Configuration of the UART
 * We are configuring the UART interface of the Freedom Freescale board so that we have a method of
 * transmitting to and receiving characters from our board, without the use of the printf and the debug
 * console.
 *@author Vipraja Patil & Nikhil Divekar
 *@date 26 October 2017
 */

#include "MKL25Z4.h"
#include "uart.h"
#include "buffer.h"
#include "project3.h"
#include "logger.h"

CB_struct_t * Tx;
CB_struct_t * Rx;

void UART0_IRQHandler(void);
void UART_send(uint8_t *data);
int8_t UART_receive(uint8_t* data);
LoggedItem_t * logged_data;

void UART_configure()
{
	//enable global interrupts

	SIM_SCGC4 |= SIM_SCGC4_UART0_MASK;          //enable clock gate
	SIM_SOPT2 |= SIM_SOPT2_MCGFLLCLK_MASK;      //clock source selection

	//We have to disable the transmitter and receiver for the configuration
	UART0_C2 &= ~(UART0_C2_TE_MASK | UART0_C2_RE_MASK);

	//configuration
	//create a preprocessor macro for baud rate
	UART0_BDH &= 0x00;
	UART0_BDL |= SBR_VAL;                      //57600 baud rate
	UART0_C4 |= OSR_VAL;                       //OSR = 16
	UART0_C1 &= 0x00;                          // 8 bit data

	//enable PortA
	SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;

	// UART0 RX/TX is connected to pins 27/28, PTA1/PTA2 (ALT2)
    PORTA_PCR1 = PORT_PCR_MUX(2);
    PORTA_PCR2 = PORT_PCR_MUX(2);

	//enable transmitter and receiver
	UART0_C2 |= (UART0_C2_TE_MASK | UART0_C2_RE_MASK );

	//enable receiver transmitter interrupt
	UART0_C2 |= UART0_C2_RIE_MASK;

	__enable_irq();

	NVIC_EnableIRQ(UART0_IRQn);
}

void UART_send(uint8_t *data)
{
	if(data != NULL)
	{
	while(!(UART0_S1_REG(UART0_BASE_PTR) & UART0_S1_TDRE_MASK));    // Wait until transmit buffer empty
	UART0_D_REG(UART0_BASE_PTR) = *data;
	}// Send the data
}

void UART_send_n(uint8_t *data, uint8_t length)
{	int i;
	if(data != NULL)
	{
	for(i=0;i<length;i++)
	{
	while(!(UART0_S1_REG(UART0_BASE_PTR) & UART0_S1_TDRE_MASK));    // Wait until transmit buffer empty
	UART0_D_REG(UART0_BASE_PTR)  = *data;                                                // Send the data
	data++;
	}
	}
}

int8_t UART_receive(uint8_t* data)
{
	while((UART0_S1 & UART_S1_RDRF_MASK) == 0);	// Wait until character has been received
	int8_t var;
	var = UART0_D_REG(UART0_BASE_PTR);// Return the 8-bit data from the receiver
	return var;
}

int8_t UART_receive_n(uint8_t* data, uint8_t length)  //Return n number of 8-bit data
{
	int i;
	if(data != NULL)
	{
	for(i=0;i<length;i++)
	{
	while((UART0_S1 & UART_S1_RDRF_MASK) == 0);
	*data = UART0_D_REG(UART0_BASE_PTR);
	data++;
	}
	}
}

void UART0_IRQHandler(void)				//ISR Handler
{
	__disable_irq();
	static int8_t e, f;
	int8_t c = 7;
	if ((UART0_C2 & UART0_C2_TIE_MASK) == UART0_C2_TIE_MASK) //if transmit interrupt is received
	{

		CB_buffer_remove_item(Rx, e);		//Removed from buffer
		if(e != 0 && e != 13)
		UART_send(&e);						//sent to terminal
		getStatistics(e);

		UART0_C2 &= ~UART0_C2_TIE_MASK;
		UART0_C2 |= UART0_C2_RIE_MASK;
	}
	else if((UART0_C2 & UART0_C2_RIE_MASK) == UART0_C2_RIE_MASK)	//if receiver interrupt
	{
		//int8_t count;
		uint8_t * d = NULL;
		e = UART0_D;		//receives bit from keyboard
		if(e != 0)
		CB_buffer_add_item(Rx, e);		//add it to the buffer

		logged_data = (LoggedItem_t *) malloc(sizeof(LoggedItem_t));
		create_log(logged_data, DATA_RECEIVED, 0,1);
		log_item(Tx, logged_data);

		UART0_C2 &= ~UART0_C2_RIE_MASK;
		UART0_C2 |= UART0_C2_TIE_MASK;
	}
	else
	return;
	__enable_irq();
}
