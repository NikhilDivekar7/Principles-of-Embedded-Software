/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "MKL25Z4.h"
#include "uart.h"
#include "buffer.h"
#include "project3.h"
#include "logger.h"
#include "memory.h"
#include "dma.h"
#include "spi.h"
#include "rtc.h"
#include "profiler.h"
#include "gpio.h"
#include "nordic.h"

#include <stdio.h>
#include <stdint.h>
#include <string.h>

LoggedItem_t * data_received;

CB_struct_t * Tx;
int8_t ec1 = 1;

#define project_2

int main(void)
{
	uint8_t c,e;
		uint8_t b;
	SPI_init();
		GPIO_nrf_init();
//		nrf_write_config(0x23);
//		b = nrf_read_config();
	uint8_t *s, *d;
	uint8_t a[10] = {1,2,3,4,5,6,7,8,9,10};
	//uint8_t a[10];
	SysTick_config();
	UART_configure();
	int i;
//	for(i = 0; i < 5; i++)
//	{
//		a[i] = 1;
//	}
//	for(i = 5; i < 10; i++)
//	{
//		a[i] = 2;
//	}

	s = &a[0];
	d = &a[6];
	DMA_config();
	rtc_config();
	uint32_t startVal = 0;
	uint32_t endVal = 0;
	uint32_t diff = 0;

	startVal = SysTick->VAL;


	if(ec1 == 1)
	{
		uint8_t srcstring1[] = "Before memmove: Dest ";
			uint8_t * srcptr1;
			srcptr1 = &srcstring1;
				for(int i =0; i < 21; i++)
				{
					UART_send(srcptr1);
					srcptr1++;
				}

				for(int i =6 ; i< 10; i++)
				{
					log_integer_to_UART(a[i]);
				}
	memmove_dma(s, d, 5, 1);


	s = my_itoa(*s, s, 10);
	//d = my_itoa(*d, d, 10);

	uint8_t srcstring[] = " After memmove: Dest ";
	uint8_t * srcptr;
	srcptr = &srcstring;
	for(int i =0; i < 21; i++)
	{
		UART_send(srcptr);
		srcptr++;
	}

	for(int i =6 ; i< 10; i++)
	{
		log_integer_to_UART(a[i]);
	}

//	for(int i = 0; i < 5; i++)
//	{
//		UART_send(d+i);
//	}

	//UART_send(d);

	}

	endVal = SysTick->VAL;

	diff = startVal - endVal;

	nrf_write_config(0x40);
	e = nrf_read_config();

//	SPI_write_byte(45);
//	d = SPI_read_byte(b);

	#ifdef project_2
	project3();
	#endif

	while(1)
    {

    }
    return 0;
}


