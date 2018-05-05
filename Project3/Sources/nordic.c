/* Filename : nrf.c
 * Brief : Contains all the nordic functions
 * Created on: Dec 7, 2017
 * Author: Nikhil Divekar and Vipraja Patil
 */

#include "nordic.h"
#include "spi.h"
#include "gpio.h"
#include <stdlib.h>
#include <stdint.h>

uint8_t nrf_read_register(uint8_t Register)
{
	nrf_chip_enable();              // Enable NRF
	uint8_t a,b;
	SPI_write_byte(Register | READ);
	b = SPI_read_byte(a);
	SPI_write_byte(NOP);
	b = SPI_read_byte(a);
	nrf_chip_disable();
	return b;
}

void nrf_write_register(uint8_t Register, uint8_t value)
{
	nrf_chip_enable();              // Enable NRF
	uint8_t a, b;
	SPI_write_byte(Register|WRITE);
	b = SPI_read_byte(a);
	SPI_write_byte(value);
	b = SPI_read_byte(a);
	nrf_chip_disable();
}

uint8_t nrf_read_status()
{
	uint8_t a;
	a = nrf_read_register(STATUS);             // Read the STATUS register
	return a;
	}

void nrf_write_config(uint8_t config)
{
	nrf_write_register(CONFIG, config);        // Write to CONFIG register
}

uint8_t nrf_read_config()
{
	uint8_t a;
	a = nrf_read_register(CONFIG);             // Read the CONFIG register
	return a;
}

uint8_t nrf_read_rf_setup()
{
	uint8_t a;
	a = nrf_read_register(RF_SETUP);               // Reads RF_SETUP register
	return a;
}

void nrf_write_rf_setup(uint8_t config)
{
	nrf_write_register(RF_SETUP, config);          // Writes to the RF_SETUP register
}

uint8_t nrf_read_rf_ch()
{
	uint8_t a;
	a = nrf_read_register(RF_CH);         // Reads RF_CH register
	return a;
}

void nrf_write_rf_ch(uint8_t channel)
{
	nrf_write_register(RF_CH, channel);   // Writes to the RF_CH register
}

uint8_t nrf_read_TX_ADDR(uint8_t * address)
{
	uint8_t a,b;
		uint8_t c[5]={0};
		uint8_t *p;
		p = &c;
		int i;
		uint8_t read_reg_addr = READ | TX_ADDR;
		nrf_chip_enable();
		SPI_write_byte(read_reg_addr);
		b = SPI_read_byte(a);
		for (i = 0; i<6; i++)                          // Reads the 5 bytes of the TX_ADDR register
		{
		SPI_write_byte(NOP);
		*address = SPI_read_byte(a);
		c[i] = *address;
		address++;
		}
		nrf_chip_disable();
		return p;
}

void nrf_write_TX_ADDR(uint8_t * tx_addr)
{
	uint8_t a,b;
		int i;
		uint8_t write_reg_addr = WRITE | TX_ADDR;
		nrf_chip_enable();
		SPI_write_byte(write_reg_addr);
		b = SPI_read_byte(a);
		for (i=0; i<6; i++)                          // Writes the 5 byte TX_ADDR register
		{
		SPI_write_byte(*tx_addr);
		tx_addr++;
		}
		nrf_chip_disable();
}

uint8_t nrf_read_fifo_status()
{
	uint8_t a;
	a = nrf_read_register(FIFO_STATUS);         // Reads FIFO_STATUS register
	return a;
}

void nrf_flush_tx_fifo()
{
	while(!(SPI0_S & SPI_S_SPTEF_MASK));
	SPI0_D = FLUSH_TX;                                  // Sends the command FLUSH_TX
}

void nrf_flush_rx_fifo()
{
	while(!(SPI0_S & SPI_S_SPTEF_MASK));
	SPI0_D = FLUSH_TX;                                  // Sends the command FLUSH_RX
}
