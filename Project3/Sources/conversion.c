/* Filename : conversion.c
 * Brief : Contains the itoa functions
 * Created on: Dec 7, 2017
 * Author: Nikhil Divekar and Vipraja Patil
 */

#include <stdio.h>
#include <stdint.h>
#include "conversion.h"

uint8_t * my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{
	if(ptr != NULL)
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
    }

    if ( data<0 && base==10)			//for negative numbers with base 10
    {
        data = data * (-1);
        negative = 1;
    }

    while (data != 0)
    {
        remain = data % base;		//gets the bits seperately using modulus operator
	if(remain <= 9)
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
    return ptr;
	}
}
