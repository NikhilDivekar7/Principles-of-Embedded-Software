/* Filename : rtc.c
 * Brief : Contains all the profiler functions
 * Created on: Dec 7, 2017
 * Author: Nikhil Divekar and Vipraja Patil
 */

#include <stdio.h>
#include "profiler.h"
#include "MKL25Z4.h"
#include "memory.h"
#include "logger.h"
#include "buffer.h"
#include "sys/time.h"
#include "time.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define KL25Z

CB_struct_t * Tx;

LoggedItem_t * logged_data;

void SysTick_config()
{
	//SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk | SysTick_CTRL_CLKSOURCE_Msk;
	SysTick->LOAD |= SysTick_LOAD_RELOAD_Msk;
	SysTick -> CTRL = 0x5;
	SysTick -> VAL = 0X0;
}

void getTicks(uint8_t option)
{
	logged_data = (LoggedItem_t *) malloc(sizeof(LoggedItem_t));
	create_log(logged_data, PROFILING_STARTED, 1,1);
	log_item(Tx, logged_data);

	uint32_t valueLength = 0;
	uint32_t startVal = 0;
	uint32_t endVal = 0;
	uint32_t diff = 0;
	uint32_t diffcopy;
	uint32_t difflength;
	uint32_t * diffptr;
	uint8_t value = 1;
	uint8_t * valueptr;
	valueptr = &value;
	diffptr = &diff;

	uint8_t *s, *d;
	uint8_t a[10000];
	int i;
	for(i = 0; i < 5000; i++)
	{
		a[i] = 1;
	}
	for(i = 5000; i < 10000; i++)
	{
		a[i] = 2;
	}

	s = &a[0];
	d = &a[4999];

	#ifdef KL25Z
	if(option == 1)
	{
		startVal = SysTick -> VAL;
		my_memmove(s, d, 10);
		endVal = SysTick -> VAL;
		diff = startVal - endVal;

		diffcopy = diff;
		while(diffcopy != 0)
		{
			diffcopy = diffcopy % 10;
			difflength++;
		}

		logged_data = (LoggedItem_t *) malloc(sizeof(LoggedItem_t));
		create_log(logged_data, PROFILING_RESULT, difflength, diffptr);
		log_item(Tx, logged_data);
	}
	else if(option == 2)
	{
		startVal = SysTick -> VAL;
		memmove_dma(s, d, 10, 1);
		endVal = SysTick -> VAL;
		diff = startVal - endVal;

		logged_data = (LoggedItem_t *) malloc(sizeof(LoggedItem_t));
		create_log(logged_data, PROFILING_RESULT, difflength, diffptr);
		log_item(Tx, logged_data);
	}
	else if(option == 3)
	{
		startVal = SysTick -> VAL;
		my_memset(d, 10, value);
		endVal = SysTick -> VAL;
		diff = startVal - endVal;

		logged_data = (LoggedItem_t *) malloc(sizeof(LoggedItem_t));
		create_log(logged_data, PROFILING_RESULT, difflength, diffptr);
		log_item(Tx, logged_data);
	}
	else if(option == 4)
	{
		startVal = SysTick -> VAL;
		memset_dma(d, 10, value, 1);
		endVal = SysTick -> VAL;
		diff = startVal - endVal;

		logged_data = (LoggedItem_t *) malloc(sizeof(LoggedItem_t));
		create_log(logged_data, PROFILING_RESULT, difflength, diffptr);
		log_item(Tx, logged_data);
	}
	#endif

	#ifdef BBB
	int i = 0;
	int status = 0;
	struct timespec start_time, end_time;
	double diff;
	int8_t arr1[10],arr2[10];
	status = clock_gettime(CLOCK_REALTIME, &start_time);
	memmove(arr1,arr2,10);
	status = clock_gettime(CLOCK_REALTIME, &end_time);

	diff_time = (( end_time.tv_sec - start_time.tv_sec ) + ( end_time.tv_nsec - start_time.tv_nsec ));
	printf("Time taken is %lf\n", diff);
	#endif

}
