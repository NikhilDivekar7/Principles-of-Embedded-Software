/*@file - logger.h
 *@brief - Configures the logger buffer structure and various enums to be allocated
 *@brief - in the log
 *@author Vipraja Patil & Nikhil Divekar
 *@date 3 December 2017
 */

#include <stdio.h>
#include <stdint.h>
#include "buffer.h"

#ifndef LOGGER_H_
#define LOGGER_H_

typedef enum
{
	fail,
	success,
	NULL_POINTER_PASSED,
	ALLOCATION_FAILED,
}logger_status_t;

typedef enum
{
	LOGGER_INITIALIZED,
	GPIO_INITIALIZED,
	SYSTEM_INITIALIZED,
	SYSTEM_HALTED,
	INFO,
	WARNING,
	ERROR,
	PROFILING_STARTED,
	PROFILING_RESULT,
	PROFILING_COMPLETED,
	DATA_RECEIVED,
	DATA_ANALYSIS_STARTED,
	DATA_ALPHA_COUNT,
	DATA_NUMERIC_COUNT,
	DATA_PUNCTUATION_COUNT,
	DATA_MISC_COUNT,
	DATA_ANALYSIS_COMPLETED,
	HEARTBEAT,
}logger_enum_t;

typedef struct LoggedItem
{
	logger_enum_t logID;
	uint32_t TimeStamp;
	size_t Payload_Length;
	uint8_t * Payload;
	uint32_t Checksum;
}LoggedItem_t;

/*
 *@brief - log data
 *Takes a pointer to a sequence of bytes and length of bytes to log
 *@param -
 *         ptr: Source Pointer
 *         CB_data: Destination Pointer
 *         length: Length of the bytes
 *@return  NULL_POINTER_PASSED: for null pointer
 *@return  success: if logging is successful
 */
logger_status_t log_data(CB_struct_t * CB_data, uint8_t * ptr, size_t length);

/*
 *@brief - log string
 *Takes a C-string and logs that to the terminal
 *@param -
 *         data_ptr: Source Pointer
 *         CB_data: Destination Pointer
 *@return  NULL_POINTER_PASSED: for null pointer
 *@return  success: if logging is successful
 */
logger_status_t log_string(CB_struct_t * CB_data, uint8_t *data_ptr);

/*
 *@brief - log integer
 *Takes an integer and logs that to the terminal
 *@param -
 *         data: integer data to be logged
 *         CB_data: Destination Pointer
 *@return  NULL_POINTER_PASSED: for null pointer
 *@return  success: if logging is successful
 */
logger_status_t log_integer(CB_struct_t * CB_data, int32_t data);

/*
 *@brief - log flush
 *Blocks until the current logger buffer is empty
 *@param -
 *         CB_data: buffer to be flushed
 *@return  NULL_POINTER_PASSED: for null pointer
 *@return  success: if operation is successful
 */
logger_status_t log_flush(CB_struct_t * CB_data);

/*
 *@brief - log data to UART
 *Takes a pointer to a sequence of bytes and length of bytes and adds it to the log buffer. This is used for HEARTBEAT
 *@param -
 *         data_ptr: Destination Pointer
 *         length: Length of the bytes
 *@return  NULL_POINTER_PASSED: for null pointer
 *@return  success: if logging is successful
 */
logger_status_t log_data_to_UART(uint8_t *data_ptr, size_t length);

/*
 *@brief - log string to UART
 *Takes a C-string and adds it to the log buffer. This is used for HEARTBEAT
 *@param -
 *         data_ptr: Destination Pointer
 *@return  NULL_POINTER_PASSED: for null pointer
 *@return  success: if logging is successful
 */
logger_status_t log_string_to_UART(uint8_t *data_ptr);

/*
 *@brief - log integer to UART
 *Takes an integer and adds it to the log buffer. This is used for HEARTBEAT
 *@param -
 *         data: integer data to be logged
 *         CB_data: Destination Pointer
 *@return  NULL_POINTER_PASSED: for null pointer
 *@return  success: if logging is successful
 */
logger_status_t log_integer_to_UART(int32_t data);

/*
 *@brief - Create log item
 *Updates the logger struct.
 *@param -
 *         Item: logger buffer
 *         ID: Indicator on what the log is
 *         length: Number of bytes of Payload
 *         payload: Any associated data that is sent with the log
 *@return  NULL_POINTER_PASSED: for null pointer
 *@return  success: if the operation is successful
 */
logger_status_t create_log(LoggedItem_t *Item , logger_status_t ID, size_t length, uint8_t *payload);

/*
 *@brief - log item
 *It updates the logger buffer
 *@param -
 *         CB_data: circular buffer
 *         Item: logger buffer
 *@return  NULL_POINTER_PASSED: for null pointer
 *@return  success: if the operation is successful
 */
logger_status_t log_item(CB_struct_t * CB_data, LoggedItem_t *Item);

void toggleHeartbeat();

#endif

