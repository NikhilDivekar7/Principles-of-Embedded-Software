/* dma.h
 * brief : DMA config
 * In this file, we configure the DMA.
 *  Created on: Nov 30, 2017
 *  Author: Nikhil Divekar & Vipraja Patil
 */

#ifndef INCLUDES_DMA_H_
#define INCLUDES_DMA_H_

#define DMAMUX_DISABLE 0x00
#define SIM_SOPT2_MCGFLLCLK_MASK 0x4000000u

/*
 *@brief - DMA config
 *In this function, we can configure the DMA by selecting clocks, enabling clocking source etc.
 *@param
 *@return void
 */
void DMA_config();

void DMA2_IRQHandler();


#endif /* INCLUDES_DMA_H_ */
