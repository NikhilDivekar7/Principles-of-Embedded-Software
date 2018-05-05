/*@file - uart.h
 *@brief - Configuration of the UART
 * We are configuring the UART interface of the Freedom Freescale board so that we have a method of
 * transmitting to and receiving characters from our board, without the use of the printf and the debug
 * console.
 *@author Vipraja Patil & Nikhil Divekar
 *@date 26 October 2017
 */

#ifndef INCLUDES_UART_H_
#define INCLUDES_UART_H_

#include"MKL25Z4.h"
#include"uart.h"

#define INTERRUPT

#define SIM_SOPT2_MCGFLLCLK_MASK   0x4000000u
#define UART0_INT_ENABLE_MASK      0x00001000u

#define OSR_VAL 0x0F
#define SBR_VAL 0x17


/*
 *@brief - Configure
 *Configures UART to the given settings.
 *@param -
 *@return
 */
void UART_configure();


/*
 *@brief - Send byte
 *This function will send a single byte down a specific UART device
 *@param - data: Pointer to the data item to send
 *@return - void
 */
void UART_send(uint8_t*);

/*
 *@brief - Send n bytes
 *This function will send n bytes down a specific UART device
 *@param - data: Pointer to a contiguous block of data that needs to be transmitted
 *@param - length: Number of items to transmit
 *@return - void
 */
void UART_send_n(uint8_t*, uint8_t);

/*
 *@brief - Receive byte
 *Wait for a byte to be received on the specified UART
 *@param - data: UART location to read from
 *@return - received byte on the UART
 */
int8_t UART_receive(uint8_t*);

/*
 *@brief - Receive n bytes
 *Wait for n bytes to be received on the specified UART
 *@param - data: UART location to read from
 *@param - length: Number of items to receive
 *@return - received bytes on the UART
 */
int8_t UART_receive_n(uint8_t*, uint8_t);


/*
 *@brief - IRQ Handler
 *This is the IRQ Handler for UART. We handle two types of interrupts in this function
 *Receive Interrupts and Transmit interrupt.
 *Each interrupt should clear their associated flag when completed but only if they were set.
 *@param
 *@return - void
 */
void UART0_IRQHandler(void);

#endif /* INCLUDES_UART_H_ */
