/*@file - memory.h
 *@brief - The implementation file for memory manipulation
 * This implementation file provides the function definitions for
 * copying data using pointers from one memory location to another,setting data, reversing the order of bytes
 * from certain memory locations.
 *@author Vipraja Patil & Nikhil Divekar
 *@date 26 October 2017
 */

#ifndef _MEMORY_H_
#define _MEMORY_H_

#include <stdint.h>
#include <stdlib.h>

#define byte_transfer_1 1
#define byte_transfer_2 2
#define byte_transfer_4 4

typedef enum  {
	INVALID_POINTER,
  	NO_OVERLAP,
  	SRC_IN_DST_REGION_OVERLAP,
  	DST_IN_SRC_REGION_OVERLAP,
  	CHECK_SET,
	CHECK_ODD_REVERSE,
	CHECK_EVEN_REVERSE,
  	CHECK_CHARACTERS
}memory_status;

struct memory_parameters {
  	int8_t *src;
  	int8_t *dst;
  	int8_t length;
  	int8_t value;
  	int8_t size;
};

typedef struct memory_parameters mem_param;
mem_param *mem_pointer;


/*
 *@brief - Memory move
 *This function takes two byte pointers (one source and one destination)
 *and a length of bytes tocopy from the source location to the destination.
 *The behavior should handle overlap of source and destination. Copy should occur, with no data
 *corruption.
 *@param - mem_pointer structure which has
 * src: Source Pointer
 * dst: Destination Pointer
 * length: Length of the bytes
 *@return Invalid Pointers - Should return fail if pointers are NULL
 * No Overlap - Should return a pass for a move
 * SRC in DST region Overlap - Should succeed at this
 * DST in SRC region Overlap - Should succeed at this
 */
memory_status my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/*
 *@brief - Memory move DMA
 *This function takes two byte pointers (one source and one destination)
 *and a length of bytes tocopy from the source location to the destination using DMA.
 *The behavior should handle overlap of source and destination. Copy should occur, with no data
 *corruption.
 *@param -
 *         src: Source Pointer
 *         dst: Destination Pointer
 *         length: Length of the bytes
 *         size: Transfer byte size
 *@return  void
 */
memory_status memmove_dma(uint8_t * src, uint8_t * dst, size_t length, size_t size);

memory_status my_memmove_overlap(uint8_t * src, uint8_t * dst, size_t length);

/*
 *@brief - Set values to a location
 *This should take a pointer to a source memory location, a length in bytes and set all locations of
 *that memory to a given value.
 *@param - mem_pointer structure which has
 *         src: Source Pointer
 *         length: Length of the bytes
 *         value: Value to be copied
 *@return Invalid Pointers - Should return fail if pointers are NULL
 *        Check Set - Should accurately set region for length Value
 */
memory_status my_memset(uint8_t * dst, size_t length, uint8_t value);

/*
 *@brief - Memory set value using DMA
 *@brief  *This should take a pointer to a source memory location, a length in bytes and set all locations of
 *that memory to a given value using DMA transfer.
 *@param -
 *         dst: Destination Pointer
 *         length: Length of the bytes
 *         value: Value to be copied
 *         size: Transfer byte size
 *@return void
 */
memory_status memset_dma(uint8_t * dst, size_t length, uint8_t value, size_t size);


#endif // MEMORY_H_






