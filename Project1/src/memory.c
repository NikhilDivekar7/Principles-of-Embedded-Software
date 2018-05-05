/*@file - memory.h
 *@brief - The implementation file for memory manipulation
 * This implementation file provides the function definitions for
 * copying data using pointers from one memory location to another,setting data, reversing the order of bytes
 * from certain memory locations.
 *@author Vipraja Patil & Nikhil Divekar
 *@date 3 October 2017
 */

#include <stdio.h>
#include <stdint.h>
#include "memory.h"
#include <stdlib.h>

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length)
{
    if(dst > src)				// checks location of source and destination pointer
    {
        for(int i = length-1; i >=0; i--)	// if source address comes first, start moving bytes from last location in the source to destination
						// This avoids overlap data corruption
        {
            *(dst+i) = *(src+i);		// moves the corresponding bytes of source to destination
        }
    }
    else if(dst < src)				// checks location of source and destination pointer
    {
        for(int i = 0; i < length; i++)		// if destination address comes first, start moving bytes from first location in the source to destination
						// This avoids overlap data corruption
        {
            *(dst+i) = *(src+i);		// moves the corresponding bytes of source to destination
        }
    }
    return dst;
}

uint8_t * my_memcpy(uint8_t * src, uint8_t * dst, size_t length)
{
    for(int i = 0; i < length; i++)
    {
        *(dst+ i) = *(src+ i);			// copies the corresponding bytes of source to destination
    }
    return dst;
}

int8_t * my_memset(uint8_t * src, size_t length, uint8_t value)
{
    int8_t * ptr;
    for(int i = 0; i < length; i++)
    {
        *(src + i) = value;			// sets the bytes of src to the assigned value
    }
    ptr = (int8_t *)src;
    return ptr;
}

uint8_t * my_memzero(uint8_t * src, size_t length)
{
    for(int i = 0; i < length; i++)
    {
        uint8_t value = 0;
        *(src + i) = value;			// zeroes all the bytes of src
    }
    return src;
}

uint8_t * my_reverse(uint8_t * src, size_t length)
{
    	uint8_t temp;
	int l = 0;
	int i = 0;
	
	if(length % 2 == 0)			// if length of array is even
	{
	    l=length / 2;			// checks elements only till the half length of an array so that data is not overwritten
	}
	else					// if length of array is odd
	{
	    l=(length - 1) / 2;			// checks elements only till the half length of an array so that data is not overwritten
	}
	
	for(i=0;i<l;i++)
	{
		temp=*(src + i);		// swaps the contents of the elements with the address that corresponds in reverse order by making use of 							temporary variable
		*(src + i) =*(src + length - i - 1);
		*(src + length - i - 1) = temp;
	}
    return src;
}


int32_t * reserve_words(size_t length)
{
    int i;
    int32_t *ptr;
    ptr = (int32_t *) malloc(length);	
    for(i=0; i<length; i++)
    {
        ptr++;				// if memory allocation is successful
    }		// assigns pointer to the allocated memory
    if(length < 0)
    {
	return NULL;
    }
    return ptr;
}


void free_words(int32_t * src)
{
    src = NULL;				// frees the location assigned by the pointer by assigning to the null pointer
}
