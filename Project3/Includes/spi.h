/*@file - spi.h
 *@brief - Configures the SPI and has all the SPI related functions.
 *@author Vipraja Patil & Nikhil Divekar
 *@date 3 December 2017
 */

#include <stdint.h>

#ifndef SPI_H_
#define SPI_H_

/*
 *@function - SPI_init()
 *@brief - Sets up the SPI configuration
 *@param - void
 *@return  void
 */
void SPI_init();

/*
 *@function - SPI_read()
 *@brief - Reads the data through SPI
 *@param - void
 *@return  data which is read
 */
uint8_t SPI_read(uint8_t byte);

/*
 *@function - SPI_write()
 *@brief - Writes the data through SPI
 *@param - data to be written
 *@return  void
 */
void SPI_write(uint8_t byte);

/*
 *@function - SPI_send_packet()
 *@brief - Sends the large amount of data through SPI
 *@param - *p : pointer at which data is written
 *@param  - length: length for which data is written
 *@return  void
 */
void SPI_send_packet(uint8_t * p, uint8_t length);

/*
 *@function - SPI_flush()
 *@brief - Flush the data through SPI
 *@param - void
 *@return  void
 */
void SPI_flush();

#endif /* SOURCES_SPI_H_ */
