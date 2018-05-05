/* Filename : spi.c
 * Brief : Contains all the spi functions
 * Created on: Dec 7, 2017
 * Author: Nikhil Divekar and Vipraja Patil
 */

#include <stdio.h>
#include "spi.h"
#include "MKL25Z4.h"

void SPI_init()
{
	SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK;
	SIM_SCGC4 |= SIM_SCGC4_SPI0_MASK;

	PTB_BASE_PTR -> PDDR |= 0x100;
	PTB_BASE_PTR -> PDOR |= 0x100;

	PORTC ->PCR[4] = PORT_PCR_MUX(1);	//Chip select
	PORTC ->PCR[5] = PORT_PCR_MUX(2);	//clk src
	PORTC ->PCR[6] = PORT_PCR_MUX(2);	//MOSI
	PORTC ->PCR[7] = PORT_PCR_MUX(2);	//MISO

	PTB_BASE_PTR->PSOR = 1<<4;

	SPI0_C1 = SPI_C1_SPE_MASK | SPI_C1_MSTR_MASK;

	SPI0_BR &= ~( SPI_BR_SPR_MASK | SPI_BR_SPPR_MASK);
}

uint8_t SPI_read_byte(uint8_t byte)
{
	while(!(SPI0_S & SPI_S_SPRF_MASK));;
	byte = SPI0_D;
	return byte;
}

void SPI_write_byte(uint8_t byte)
{
	while (!(SPI0_S & SPI_S_SPTEF_MASK));
	//SPIO_S &= 0xFF;
	SPI0_D = byte;
}

void SPI_send_packet(uint8_t * p, uint8_t length)
{
	uint8_t i;
	for(i = 0; i < length; i ++)
	{
		while(!(SPI0_S & SPI_S_SPTEF_MASK));
	    SPI0_D = *p;

	    while(!(SPI0_S & SPI_S_SPRF_MASK));
	    *p= SPI0_D;

	    p++;
    }
}

void SPI_flush()
{
	while (!(SPI0_S & SPI_S_SPRF_MASK));
}
