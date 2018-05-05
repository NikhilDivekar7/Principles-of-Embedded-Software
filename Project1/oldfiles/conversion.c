/**
 * @file conversion.c
 * @brief The implementation file for data manipulation functions
 *
 * This implementation file provides the function definitions for
 * various data manipulation operations.
 *
 * @author Vipraja Patil & Nikhil Divekar
 * @date 3 October 2017
 *
 */

#include <stdio.h>
#include <stdint.h>
#include "conversion.h"

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{
    int32_t remain;
    int i = 0;
    int length = 0;
    for(i = 0; i < 100; i++)
    {
        ptr++;
    }
    if (data > 0)				// checks whether data is positive
    {
        while(data != 0)
        {
            remain = data % base;		// seperate the bits by using modulus operator	
            if (remain < 10)
            {
                * ptr = 48 + remain;		// gets the corresponding ascii character of the integer
            }
            else
            {
                * ptr = 55 + remain;		// This is specifically for the hex value where remainder can be greater than 10  
            }
      	    ptr--;
      	    length++;				// gets the length of converted string
      	    data = data/base;
        }
    }

    else if (data < 0)				// for negative number
    {
        data = data * (-1);
        while(data != 0)
        {
            remain = data % base;		// seperate the bits by using modulus operator
            if (remain < 10)
            {
                * ptr = 48 + remain;		// gets the corresponding ascii character of the integer
            }
            else
            {
                * ptr = 55 + remain;		// This is specifically for the hex value where remainder can be greater than 10
            }
      	    ptr--;
      	    length++;				// gets the length of converted string
      	    data = data/base;
        }
        * ptr = '-';				// Annotates the negative sign to the converted string
        length++;
        ptr--;
    }
return length;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)
{
    int number = 0;
    int negative = 0;
    if(* ptr == '-')					// checks whether the string is in negative format
    {
        negative = 1;					// sets the negative flag
        ptr++;						// pointer increment to include minus sign
    }
    while ( * ptr != '\0' )				// checks the end of the string
    {
      number = number * base;
      if(*ptr == 'A' || *ptr == 'B'|| *ptr == 'C'|| *ptr == 'D'|| *ptr == 'E'|| *ptr == 'F')
      {
          number = number + (*ptr) - 55;		// for base 16, where characters from A to F can be the part of input
      }
      else if (*ptr == 'a' || *ptr == 'b'|| *ptr == 'c'|| *ptr == 'd'|| *ptr == 'e'|| *ptr == 'f')
      {
          number = number + (*ptr) - 87;		// for 'a' to 'f' in lower cases
      }
      else
      {
          number = number + (*ptr) - 48;    		// for converting int in char format to integer
      }
      ptr++;
    }
    if ( negative == 1 )
    {
       number *= -1;					// negates the number if negative flag is set
    }
    return number;
}


int8_t big_to_little32 (uint32_t * data, uint32_t length)
{
 uint8_t *tempVariable;
 uint8_t swapVariable;
 int index;
 
 tempVariable = (uint8_t*) data;
 if(length <= 0 || data == 0) 
 {
    printf("There is an error.");                                         
    return 1;                                        
 }
 for(index = 0;index < length;) 
 {  
    swapVariable = *(tempVariable+index);			// swaps the element for index 0 and 3
    *(tempVariable+index) = *(tempVariable+index+3);
    *(tempVariable+index+3) = swapVariable;
    
    swapVariable = *(tempVariable+index+1);
    *(tempVariable+index+1) = *(tempVariable+index+2);	// swaps the element for index 1 and 2
    *(tempVariable+index+2) = swapVariable;
    
    index = index+4;           				// increments the index to pointer which is 4 bytes ahead                               
 }
 return 0;
}

int8_t little_to_big32 (uint32_t * data, uint32_t length)
{
 uint8_t *tempVariable;
 uint8_t swapVariable;
 int index;
 
 tempVariable = (uint8_t*) data;
 if(length <= 0 || data == 0) 
 {
    printf("There is an error.");                                         
    return 1;                                        
 }
 for(index = 0;index < length;) 
 {  
    swapVariable = *(tempVariable+index);			// swaps the element for index 0 and 3
    *(tempVariable+index) = *(tempVariable+index+3);
    *(tempVariable+index+3) = swapVariable;
    
    swapVariable = *(tempVariable+index+1);			// swaps the element for index 1 and 2
    *(tempVariable+index+1) = *(tempVariable+index+2);
    *(tempVariable+index+2) = swapVariable;
    
    index = index+4;      				// increments the index to pointer which is 4 bytes ahead                                     
 }
 return 0;
}
