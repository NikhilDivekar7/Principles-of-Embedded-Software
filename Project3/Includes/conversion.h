#ifndef CONVERSION_H_
#define CONVERSION_H_
#include <stdint.h>

/*
 *@brief - Int to Ascii
 *This function will convert data from a standard integer type into an ASCII string.
 *The number you wish to convert is passed in as a signed 32-bit integer.
 *@param - data: Input Integer
 *@param - * ptr: Pointer which stores the output
 *@param - base: It can be 2,8,10,16
 *@return the length of the converted data
 */
uint8_t * my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

#endif
