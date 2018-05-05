/*
 * nordic.h
 * It has all the Nordic functions
 * Created on: Dec 4, 2017
 * Author: Nikhil Divekar & Vipraja Patil
 */

#ifndef INCLUDES_NORDIC_H_
#define INCLUDES_NORDIC_H_

#include "gpio.h"
#include "MKL25Z4.h"

#define  nrf_chip_enable()      GPIOC_PCOR |= (1 << 4);   // Enable NRF chip
#define  nrf_chip_disable()     GPIOC_PSOR |= (1 << 4);   // Disable NRF chip
#define  nrf_transmit_enable()  GPIOC_PCOR |= (1 << 3);   // Enable NRF transmission
#define  nrf_transmit_disable() GPIOC_PSOR |= (1 << 3);   // Disable NRF transmission

// Register Map
#define CONFIG                  (0x00)                    // Configuration
#define RF_CH                   (0x05)                    // Rf Channel
#define RF_SETUP                (0x06)                    // Rf Setup register
#define STATUS                  (0x07)                    // Status register
#define TX_ADDR                 (0x10)                    // Transmit address
#define FIFO_STATUS             (0x17)                    // FIFO Status register


#define NRF_POWER_UP_MASK       (0x02)
#define NRF_POWER_DOWN_MASK 	(0X00)
#define NRF_CHANNEL_FREQ_MASK   (0x03)
#define NRF_SET_LAN_GAIN_MASK   (0x01)
#define FLUSH_TX                (0xE1)                    // Flush TX FIFO, used in TX mode
#define FLUSH_RX                (0xE2)                    // Flush RX FIFO, used in RX mode
#define NOP                     (0xFF)                    // No Operation Command for NRF

#define READ 0x00
#define WRITE 0x20
/*
 *@brief - NRF read register
 *Read the register and return the value
 *@param -
 *         Register: register from which data is read
 *@return  data read from Register
 */
uint8_t nrf_read_register(uint8_t Register);

/*
 *@brief - NRF write register
 *Write to the given register with the data.
 *@param -
 *         Register: register to be written
 *         value: Data to be written
 *@return  void
 */
void nrf_write_register(uint8_t Register, uint8_t value);

/*
 *@brief - NRF read status
 *Read STATUS register and return the value
 *@param -
 *@return  data read from STATUS
 */
uint8_t nrf_read_status();

/*
 *@brief - NRF write config
 *Write to the CONFIG register with the data.
 *@param -
 *         config: Data to be written
 *@return  void
 */
void nrf_write_config(uint8_t config);

/*
 *@brief - NRF read config
 *Read CONFIG register and return the value
 *@param -
 *@return  data read from CONFIG
 */
uint8_t nrf_read_config();

/*
 *@brief - NRF read rf setup
 *Read RF_SETUP register and return the value
 *@param -
 *@return  data read from RF_SETUP
 */
uint8_t nrf_read_rf_setup();

/*
 *@brief - NRF write rf setup
 *Write to the RF_SETUP register with the data.
 *@param -
 *         config: Data to be written
 *@return  void
 */
void nrf_write_rf_setup(uint8_t config);

/*
 *@brief - NRF read rf channel
 *Read RF_CH register and return the value
 *@param -
 *@return  data read from RF_CH
 */
uint8_t nrf_read_rf_ch();

/*
 *@brief - NRF write rf channel
 *Write to the RF_CH register with the data.
 *@param -
 *         channel: Data to be written
 *@return  void
 */
void nrf_write_rf_ch(uint8_t channel);

/*
 *@brief - NRF read tx addr
 *Reads the 5 bytes of the TX_ADDR register
 *@param - address: ptr which is used to read
 *@return  data read from TX_ADDR
 */
uint8_t nrf_read_TX_ADDR(uint8_t * address);

/*
 *@brief - NRF write tx addr
 *Writes the 5 byte TX_ADDR register
 *@param -
 *         tx_addr: points towards destination
 *@return  void
 */
void nrf_write_TX_ADDR(uint8_t * tx_addr);

/*
 *@brief - NRF read fifo status
 *Read FIFO_STATUS register and return the value
 *@param -
 *@return  data read from FIFO_STATUS
 */
uint8_t nrf_read_fifo_status();

/*
 *@brief - NRF flush tx fifo
 *Sends the command FLUSH_TX
 *@param -
 *@return  void
 */
void nrf_flush_tx_fifo();

/*
 *@brief - NRF flush rx fifo
 *Sends the command FLUSH_RX
 *@param -
 *@return  void
 */
void nrf_flush_rx_fifo();


#endif /* INCLUDES_NORDIC_H_ */

