/* Filename : project2.c
 * Brief : Contains all the project2 important functions
 * Created on: Dec 7, 2017
 * Author: Nikhil Divekar and Vipraja Patil
 */

#include "buffer.h"
#include "project3.h"
#include "uart.h"
#include "conversion.h"
#include "logger.h"

CB_struct_t * Tx;
CB_struct_t * Rx;
CB_struct_t * logBuffer;

LoggedItem_t * logged_data;

int8_t c;
uint8_t alpha = 0, num = 0, punc = 0, misc = 0;
uint8_t * alphaptr;

static int i = 0;

int32_t length = 100;
int32_t logBufferLength = 100000;
extern CB_struct_t * Tx;
extern CB_struct_t * Rx;
extern CB_struct_t * logBuffer;

void project3()
{
	Tx = malloc(sizeof(CB_struct_t));
	Tx->buffer = malloc(sizeof(int32_t) * 100);

	Rx = malloc(sizeof(CB_struct_t));
	Rx->buffer = malloc(sizeof(int32_t) * 100);

	//logBuffer = malloc(sizeof(CB_struct_t));
	//logBuffer->buffer = malloc(sizeof(int32_t) * 10000);

	UART_configure();
	CB_init(Rx, length);
	CB_init(Tx, 1000);
	//CB_init(logBuffer, logBufferLength);

	logged_data = (LoggedItem_t *) malloc(sizeof(LoggedItem_t));
	create_log(logged_data, LOGGER_INITIALIZED, 1,1);
	log_item(Tx, logged_data);

	getTicks(2);

	logged_data = (LoggedItem_t *) malloc(sizeof(LoggedItem_t));
	create_log(logged_data, PROFILING_COMPLETED, 1,1);
	log_item(Tx, logged_data);
}

void getStatistics(int8_t c)
{
		UART0_C2 &= ~UART0_C2_TIE_MASK;
		UART0_C2 &= ~UART0_C2_RIE_MASK;
		if(c == 13)
		{
			printStatistics();
		}
		else if(c == 27)
		{
			log_flush(Tx);
		}
		else if(c == 32)
		{
			toggleHeartbeat();
		}
		else if((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		{
			alpha++;
		}
		else if(c >= 48 && c <= 57)	//numeric
		{
			num++;
		}
		else if(c == 33 || c == 34 || c == 44 || c == 46 || c == 45 || c == 58 || c == 59 || c == 39 || c == 91 || c == 93 || c == 40 || c == 41 || c == 63)
		{
			punc++;
		}
		else							//miscellaneous
		{
			misc++;
		}
}

void printStatistics()
{
		logged_data = (LoggedItem_t *) malloc(sizeof(LoggedItem_t));

		create_log(logged_data, DATA_ANALYSIS_STARTED, 0,1);
		log_item(Tx, logged_data);
		//destroy_log_item(data_received);
		char enter[] = "\n";
		char * ptrline;
		ptrline = &enter;
		UART_send(ptrline);

		char a1[9] = "Alpha:   ";
		int length1 = 9;
		char * ptr1;
		ptr1 = &a1[0];
		for(int i = 0; i < length1; i++)
		{
			UART_send(ptr1);
			ptr1++;
		}

		uint8_t a2[10];
		uint8_t * ptr2;
		uint8_t * alphaptr;
		ptr2 = &a2[0];
		uint8_t length2;
		ptr2 = my_itoa(alpha, ptr2, 10);
		alphaptr = ptr2;
		while(*ptr2 != '\0')
		{
			UART_send(ptr2);
			ptr2++;
		}

		create_log(logged_data, DATA_ALPHA_COUNT, 1, alphaptr);
		log_item(Tx, logged_data);
		//destroy_log_item(data_received);

		char a3[13] = "    Digit:   ";
		int length3 = 13;
		char * ptr3;
		ptr3 = &a3[0];
		for(int i = 0; i < length3; i++)
		{
			UART_send(ptr3);
			ptr3++;
		}

		uint8_t a4[10];
		uint8_t * ptr4;
		uint8_t * digitptr;
		ptr4 = &a4[0];
		ptr4 = my_itoa(num, ptr4, 10);
		digitptr = ptr4;
		while(*ptr4 != '\0')
		{
			UART_send(ptr4);
			ptr4++;
		}

		create_log(logged_data, DATA_NUMERIC_COUNT, 1, digitptr);
		log_item(Tx, logged_data);
		//destroy_log_item(data_received);

		char a5[12] = "    Punc:   ";
		int length5 = 12;
		char * ptr5;
		ptr5 = &a5[0];
		for(int i = 0; i < length5; i++)
		{
			UART_send(ptr5);
			ptr5++;
		}

		uint8_t a6[10];
		uint8_t * ptr6;
		uint8_t * puncptr;
		ptr6 = &a6[0];
		ptr6 = my_itoa(punc, ptr6, 10);
		puncptr = ptr6;
		while(*ptr6 != '\0')
		{
			UART_send(ptr6);
			ptr6++;
		}

		create_log(logged_data, DATA_PUNCTUATION_COUNT, 1, puncptr);
		log_item(Tx, logged_data);
		//destroy_log_item(data_received);

		char a7[12] = "    Misc:   ";
		int length7 = 12;
		char * ptr7;
		ptr7 = &a7[0];
		for(int i = 0; i < length7; i++)
		{
			UART_send(ptr7);
			ptr7++;
		}

		uint8_t a8[10];
		uint8_t * ptr8;
		uint8_t * miscptr;
		ptr8 = &a8[0];
		ptr8 = my_itoa(misc, ptr8, 10);
		miscptr = ptr8;
		while(*ptr8 != '\0')
		{
			UART_send(ptr8);
			ptr8++;
		}

		create_log(logged_data, DATA_MISC_COUNT, 1, miscptr);
		log_item(Tx, logged_data);
		//destroy_log_item(data_received);

		alpha = 0;
		num = 0;
		punc = 0;
		misc = 0;

		create_log(logged_data, DATA_ANALYSIS_COMPLETED, 0,1);
		log_item(Tx, logged_data);
		//destroy_log_item(data_received);
}



