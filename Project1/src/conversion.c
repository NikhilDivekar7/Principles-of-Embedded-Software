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
#include "platform.h"

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{
    int32_t i=0;
    int32_t negative=0;
    int remain = 0;
    int l=0;
    char charval,tempVariable;
    uint8_t length;

    if(data == 0)				//checking if data is 0
    {
        *(ptr+i)='0';
        i++;
        *(ptr+i)='\0';
        return 1;
    }

    if ( data<0 && base==10)			//for negative numbers with base 10
    {
        data = data * (-1);
        negative = 1;
    }

    while (data != 0)
    {
        remain = data % base;		//gets the bits seperately using modulus operator
	if(remain < 9)
	{
		charval = remain +'0';		//for 1 to 9 digits
	}
	else if(remain > 9)
	{	
		charval = (remain-10)+'a';	//for hex values 'A' to 'F'
	}
        *(ptr+i) = charval;
        data = data / base;
        i++;
    }

    if(negative)				// for negative number
    {
        *(ptr+i) = '-';
        i++;
    }

    *(ptr+i)='\0';				// adding null character

    length=i;

    i=0;
    if(length%2 == 0)
    {l=length/2;}
    else if (length%2 !=0)
    {l = (length-1)/2;}
    while(i<l)				//swaping the positions of pointers
    {
        tempVariable=*(ptr+i);
        *(ptr+i)=*(ptr+length-i-1);
        *(ptr+length-i-1)=tempVariable;
        i++;
    }
    return length;

}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)
{
    int32_t number = 0;
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
 if(length <= 0 || data == 0) 					// error for negative length or 0 data
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
    printf("There is an error.");                       	// error for negative length or 0 data                  
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
