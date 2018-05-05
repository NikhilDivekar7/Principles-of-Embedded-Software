/* Filename : rtc.c
 * Brief : Contains all the logger functions
 * Created on: Dec 7, 2017
 * Author: Nikhil Divekar and Vipraja Patil
 */

#include <stdint.h>
#include <stdio.h>
#include <time.h>

#include "uart.h"
#include "buffer.h"
#include "conversion.h"
#include "logger.h"
#include "rtc.h"
#include "project3.h"

#define KL25Z

#ifdef KL25Z
#include "MKL25Z4.h"
#endif

#ifdef BBB
#include <time.h>
#include <sys/time.h>
#endif

int8_t flag = 1;
uint32_t checkSumValue = 0;

logger_status_t log_data(CB_struct_t * CB_data, uint8_t * ptr, size_t length)
{
	if(CB_data == NULL || ptr == NULL)
	{
		logger_status_t myStatus;
		myStatus = NULL_POINTER_PASSED;
		return myStatus;
	}

	while(length != 0)
	{
		CB_buffer_add_item(CB_data, *ptr);
		//UART_send(ptr);
		length--;
		ptr++;
	}
	//UART0_C2 |= UART0_C2_TIE_MASK;
	return success;
}

logger_status_t log_string(CB_struct_t * CB_data, uint8_t * ptr)
{
	if(CB_data == NULL || ptr == NULL)
	{
		logger_status_t myStatus;
		myStatus = NULL_POINTER_PASSED;
		return myStatus;
	}

	while(ptr != '\0')
	{
		CB_buffer_add_item(CB_data, *ptr);
		//UART_send(ptr);
		ptr++;
	}
	//UART0_C2 |= UART0_C2_TIE_MASK;
	return success;
}

logger_status_t log_integer(CB_struct_t * CB_data, int32_t data)
{
	if(CB_data == NULL)
	{
		logger_status_t myStatus;
		myStatus = NULL_POINTER_PASSED;
		return myStatus;
	}

	int8_t * ptr;
	int8_t a = 1;
	ptr = &a;
	ptr = my_itoa(data, ptr, 10);
	while(*ptr != '\0')
	{
		if(*ptr >= 48 && *ptr <= 57)
		CB_buffer_add_item(CB_data, *ptr);
		//UART_send(ptr);
		ptr++;
	}
	//UART0_C2 |= UART0_C2_TIE_MASK;
	return success;
}

logger_status_t log_flush(CB_struct_t * CB_data)
{
	if(CB_data == NULL)
	{
		logger_status_t myStatus;
		myStatus = NULL_POINTER_PASSED;
		return myStatus;
	}
	char enter1[] = "\r\n";
	log_data_to_UART(enter1, 4);
	__disable_irq();
	int8_t c;
	int8_t * sendvarptr;
	sendvarptr = &c;
	while(CB_data -> count != 0)
	{
		c = CB_buffer_remove_item(CB_data, c);
		#ifdef KL25Z
		{
		if(c != 0 && (c >= 97 && c <= 122) || (c >= 65 && c <= 90)
				|| (c >= 48 && c <= 57)
				||(c == 33 || c == 34 || c == 44 || c == 46
				|| c == 45 || c == 58 || c == 59 || c == 39
				|| c == 91 || c == 93 || c == 40 || c == 41 || c == 63 || c ==13 || c == 20 || c ==32))
		UART_send(sendvarptr);
		}
		#endif

		#ifdef BBB
		{
			printf("%c", *sendvarptr);
		}
		#endif
	}
	__enable_irq();

	return success;
}


logger_status_t log_data_to_UART(uint8_t * ptr, size_t length)
{
	if(ptr == NULL)
	{
		return	NULL_POINTER_PASSED;
	}

	while(length != 0)
	{
		if(*ptr != 0)
		UART_send(ptr);
		ptr++;
		length--;
	}
	return success;
}

logger_status_t log_string_to_UART(uint8_t * ptr)
{
	if(ptr == NULL)
	{
		return	NULL_POINTER_PASSED;
	}

	while(* ptr != '\0')
	{
		if(*ptr != 0)
		uart_send(ptr);
		ptr++;
	}
	return SUCCESS;
}

logger_status_t log_integer_to_UART(int32_t data)
{
	int8_t * ptr = (int8_t *)malloc(sizeof(data));

	ptr = my_itoa(data, ptr, 10);

	while(* ptr != '\0')
	{
		if(*ptr != 0)
		UART_send(ptr);
		ptr++;
	}

	return SUCCESS;
}


logger_status_t create_log(LoggedItem_t * Item , logger_status_t ID, size_t length, uint8_t * payload)
{
	if(Item == NULL || payload == NULL)
	{
		logger_status_t myStatus;
		myStatus = NULL_POINTER_PASSED;
		return myStatus;
	}

	Item -> logID = (int8_t)ID;
	Item -> Payload_Length = length;
	#ifdef KL25Z
	time_t tStamp = RTC_TSR;
	Item -> TimeStamp = tStamp;
	#endif

	#ifdef HOST || BBB
	struct timeval time;
	gettimeofday(&time, NULL);
	Item->TimeStamp = (int32_t)time.tv_sec;
	#endif

	Item -> Payload = (uint8_t *)malloc(sizeof(uint8_t));
	int i;
	for(i = 0; i < length; i++)
	{
		*(Item -> Payload + i) = *(payload + i);
	}
	checkSumValue = (Item->logID) + (Item->TimeStamp) +
				(Item->Payload_Length);

	Item ->Checksum = checkSumValue;

	return success;
}

logger_status_t log_item(CB_struct_t * CB_data, LoggedItem_t *Item)
{
	int8_t a1;
	if(CB_data == NULL || Item == NULL)
	{
		return NULL_POINTER_PASSED;
	}

	uint8_t ID_Tag[] = "Log ID: ";
	uint8_t Payload_Tag[] = "PayLoad: ";
	uint8_t Time_Tag[] = "Timestamp: ";
	uint8_t Checksum_Tag[] = "Checksum: ";

	if(Item -> logID != 17)
	{

	log_data(CB_data, ID_Tag, 8);
	log_integer(CB_data, Item -> logID);
	log_data(CB_data, " ", 1);

	log_data(CB_data, Time_Tag, 11);
	log_integer(CB_data, Item -> TimeStamp);
	log_data(CB_data, " ", 1);

	if(Item -> Payload_Length != 0)
	{
		log_data(CB_data, Payload_Tag, 9);
		log_data(CB_data, Item -> Payload, Item -> Payload_Length);
		log_data(CB_data, " ", 1);
	}

	log_data(CB_data, Checksum_Tag, 10);
	log_integer(CB_data, Item -> Checksum);
	log_data(CB_data, " ", 1);

	char enter[] = "\r\n";
	log_data(CB_data, enter, 4);
	}

	else if(Item -> logID == 17 && flag == 1)
	{
		log_data_to_UART(ID_Tag, 8);
		log_integer_to_UART(Item -> logID);
		log_data_to_UART(" ", 1);

		log_data_to_UART(Time_Tag, 11);
		log_integer_to_UART(Item -> TimeStamp);
		log_data_to_UART(" ", 1);

		if(Item -> Payload_Length != 0)
		{
			log_data_to_UART(Payload_Tag, 9);
			log_data_to_UART(Item -> Payload, Item -> Payload_Length);
			log_data_to_UART(" ", 1);
		}

		char enter[] = "\r\n";
		log_data_to_UART(enter, 4);
	}
}

void toggleHeartbeat()
{
	if(flag == 0)
	{
		flag = 1;
	}
	else if(flag == 1)
	{
		flag = 0;
	}
}
