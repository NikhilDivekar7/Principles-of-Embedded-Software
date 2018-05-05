/* rtc.c
 *
 *  Created on: Dec 7, 2017
 *      Author: vipra
 */


#include "MKL25Z4.h"
#include <stdint.h>
#include "logger.h"
#include "time.h"

uint32_t sec = 0;
LoggedItem_t * data_received;
CB_struct_t * Tx;

void rtc_config()
{
	// Enable the internal reference clock
	MCG->C1 |= MCG_C1_IRCLKEN_MASK;

	// Select the slow internal reference clock source
	MCG->C2 &= ~(MCG_C2_IRCS_MASK);

	//
	SIM->SCGC5 |= SIM_SCGC5_PORTC_MASK;

	// Set PTC1 as RTC_CLKIN and select 32 KHz clock source for the RTC module
	PORTC->PCR[1] |= PORT_PCR_MUX(1);
	SIM->SOPT1 |= SIM_SOPT1_OSC32KSEL(2);

	// Set PTC3 as CLKOUT pin and selects the MCGIRCLK clock to output on the CLKOUT pin
	SIM->SOPT2 |= SIM_SOPT2_CLKOUTSEL(4);
	PORTC->PCR[3] |= PORT_PCR_MUX(5);

	// Enable software access and interrupts to the RTC module
	SIM->SCGC6 |= SIM_SCGC6_RTC_MASK;

	// Clear all RTC registers
	RTC->CR |= RTC_CR_SWR_MASK;
	RTC->CR &= ~(RTC_CR_SWR_MASK);

	//
	if (RTC_SR & RTC_SR_TIF_MASK)                  // Time is invalid and time counter is read as zero
	{
	       RTC_TSR = 0x00000000;
	}

	RTC->TCR = RTC_TCR_CIR(1) | RTC_TCR_TCR(0xFF);

	//RTC->CR |= RTC_CR_OSCE_MASK;

	RTC->IER = 0;

	__enable_irq();

	NVIC_EnableIRQ(RTC_Seconds_IRQn);

	RTC->IER |= RTC_IER_TSIE_MASK;

	//NVIC_SetPriority(RTC_Seconds_IRQn, 2);

	RTC->SR |= RTC_SR_TCE_MASK;
}

void RTC_Seconds_IRQHandler()
{
	sec++;
	uint8_t heartbeatstr[]="Heartbeat";
	data_received = (LoggedItem_t *) malloc(sizeof(LoggedItem_t));
	create_log(data_received, HEARTBEAT, 1,1);
	log_item(Tx, data_received);
}
