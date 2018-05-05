/* Filename : dma.c
 * Brief : Contains all the dma related functions
 * Created on: Dec 7, 2017
 * Author: Nikhil Divekar and Vipraja Patil
 */

#include "MKL25Z4.h"
#include "dma.h"

void DMA_config()
{
	//Enable Clock gate
	SIM->SCGC6 |= SIM_SCGC6_DMAMUX_MASK;
	SIM->SCGC7 |= SIM_SCGC7_DMA_MASK;

	//Clock source selection
	SIM->SOPT2 |= SIM_SOPT2_MCGFLLCLK_MASK;

	//We have to disable DMAMUX before configuration
	DMAMUX0->CHCFG[0] = DMAMUX_DISABLE;

	// Clear Source size and Destination size fields.
	DMA_DCR0 &= ~(DMA_DCR_SSIZE_MASK | DMA_DCR_DSIZE_MASK);

	// Enables the DMA channel and select the DMA Channel Source
	DMAMUX0->CHCFG[0] |= DMAMUX_CHCFG_ENBL_MASK | DMAMUX_CHCFG_SOURCE(2);

	NVIC_EnableIRQ(DMA2_IRQn);

	DMA_DCR0 |= DMA_DCR_EINT_MASK;
}

void DMA2_IRQHandler()
{

	}
