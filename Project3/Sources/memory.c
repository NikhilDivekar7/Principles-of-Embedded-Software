/*
 * memory.c
 * The functions here are used to transfer data from source to destination and also copy certain value into preferred destinations using DMA transfer.
 *
 *  Created on: Dec 5, 2017
 *  Author: Nikhil Divekar & Vipraja Patil
 */

#include "dma.h"
#include "memory.h"
#include "MKL25Z4.h"
#include <stdint.h>

memory_status my_memmove(uint8_t * src, uint8_t * dst, size_t length)
{
	memory_status mystatus;
	int8_t i;

	if ( src <= 0 || dst <= 0 || length <= 0)          // pointers are NULL
	{
		mystatus = INVALID_POINTER;
	}
	else if ((dst + length  < src) && (src + length  < dst))    //Should return a pass for a move
	{
		mystatus = NO_OVERLAP;
	}
	else                                                           //destination overlaps source
	{
		for(i = 0; i<length; i++)
		{
		    *(dst+i) = *(src+i);
		}
	}
}

memory_status my_memmove_overlap(uint8_t * src, uint8_t * dst, size_t length)
{
	memory_status mystatus;
	//int8_t i;
	uint8_t * temp = (uint8_t *)malloc(sizeof(uint8_t));

	for(int i = 0; i < length; i++)
	{
		*(temp+i) = *(src+i);
	}

	{

		DMA_SAR0 = temp;
		// Set BCR to know how many bytes to transfer
		DMA_DSR_BCR0 = DMA_DSR_BCR_BCR(length);
		// Enable interrupt on completion of transfer, Source and destination address increment after every transfer & Set Source and Destination size as 8bit
		DMA_DCR0 |= ( DMA_DCR_EINT_MASK | DMA_DCR_DINC_MASK | DMA_DCR_SINC_MASK | DMA_DCR_SSIZE(1) | DMA_DCR_DSIZE(1));
		// Set Destination Address
		DMA_DAR0 = dst;
		// Start DMA transfer
		DMA_DCR0 |= DMA_DCR_START_MASK;

		mystatus = DST_IN_SRC_REGION_OVERLAP;
	}
    return mystatus;
}

memory_status memmove_dma(uint8_t * src, uint8_t * dst, size_t length, size_t size)
{
	__disable_irq();
//	uint8_t *s;
//	uint8_t *d;
//	for(int i = 0; i < length; i++)
//	{
//		*s = *src;
//		*d = *dst;
//	}
	memory_status mystatus;
	int8_t i;

	if (src <= 0 || dst <= 0 || length <= 0)          // pointers are NULL
        {
		mystatus = INVALID_POINTER;
	}
	else if ((dst + length  < src) && (src + length  < dst))    //Should return a pass for a move
	{
		mystatus = NO_OVERLAP;
	}
	else if ((dst > src) && (src + length  > dst))      //source overlaps destination
	{
		int ODL = src + length - dst; //overlap data length
			//First we handle the overlapping data
		my_memmove_overlap(dst, dst + length - ODL, ODL );
			//Now, we handle the remaining part
		my_memmove_overlap(src, dst, length-ODL );

        mystatus = SRC_IN_DST_REGION_OVERLAP;
	}
	else                                                      //destination overlaps source
	{
		// Set BCR to know how many bytes to transfer
		if (length%2 ==  1 && size == byte_transfer_2)
		{
			DMA_DSR_BCR0 = DMA_DSR_BCR_BCR(length-1);
		}
		else if (length % 4 != 0 && size == byte_transfer_4)
		{
			DMA_DSR_BCR0 = DMA_DSR_BCR_BCR(length-(length%4));
		}
		else
		{
		DMA_DSR_BCR0 = DMA_DSR_BCR_BCR(length);
		}
		// Enable interrupt on completion of transfer, Source and destination address increment after every transfer & Set Source and Destination size as 8bit
		DMA_DCR0 |= ( DMA_DCR_EINT_MASK | DMA_DCR_DINC_MASK | DMA_DCR_SINC_MASK | DMA_DCR_SSIZE(size) | DMA_DCR_DSIZE(size));
		// Set Source Address
		DMA_SAR0 = src;
		// Set Destination Address
		DMA_DAR0 = dst;
		// Start DMA transfer
		DMA_DCR0 |= DMA_DCR_START_MASK;

		if (length%2 ==  1 && size == byte_transfer_2)
		{
			my_memmove(src + (length - length%2), dst + (length - length%2), length%2);
		}
		else if (length % 4 != 0 && size == byte_transfer_4)
		{
			my_memmove(src + (length - length%4), dst + (length - length%4), length%4);
		}
        mystatus = DST_IN_SRC_REGION_OVERLAP;
	}
	__enable_irq();
//	log_integer_to_UART(*s);
//	log_integer_to_UART(*d);
    return mystatus;

}


memory_status my_memset(uint8_t * dst, size_t length, uint8_t value)
{
	memory_status mystatus;
  	int8_t i;

	if (dst == 0 || length <= 0)                 //null pointer
	{
		mystatus = INVALID_POINTER;
	}
    else
	{
    	for (i = 0; i <length; i++)                  //copying value to destination
    	{
    		*(dst + i) = value;
    	}
	}
    return mystatus;
}

memory_status memset_dma(uint8_t * dst, size_t length, uint8_t value, size_t size)
{
	uint8_t * valptr = (uint8_t *)malloc(sizeof(uint8_t));
	*valptr = value;
	memory_status mystatus;
  	int8_t i;

	if (dst == 0 || length <= 0)                  //null pointer
	{
		mystatus = INVALID_POINTER;
	}
    else
	{
    			// Set BCR to know how many bytes to transfer
    			DMA_DSR_BCR0 = DMA_DSR_BCR_BCR(length);
    			// Enable interrupt on completion of transfer, Source and destination address increment after every transfer & Set Source and Destination size as 8bit
    			DMA_DCR0 |= ( DMA_DCR_EINT_MASK | DMA_DCR_DINC_MASK | DMA_DCR_SSIZE(size) | DMA_DCR_DSIZE(size));
    			// Set Source Address
    			DMA_SAR0 = valptr;
    			// Set Destination Address
    			DMA_DAR0 = dst;
    			// Start DMA transfer
    			DMA_DCR0 |= DMA_DCR_START_MASK;

    			if (size == byte_transfer_2)
    			{
    				my_memset(dst + (length - length%2), length%2, value);
    			}
    			else if (size == byte_transfer_4)
    			{
    				my_memset(dst + (length - length%4), length%4, value);
    			}
    	        mystatus = DST_IN_SRC_REGION_OVERLAP;

    	        return mystatus;
	}

}
