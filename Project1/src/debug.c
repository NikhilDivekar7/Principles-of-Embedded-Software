/*@file - debug.c
 *@brief - The implementation file is to enable/disable debug printing with a compile
 *time switch.
 *@author Vipraja Patil & Nikhil Divekar
 *@date 3 October 2017
 */

#define myMacro 1;
#include <stdio.h>
#include <stdint.h>
#include "debug.h"

void print_memory(uint8_t * start, uint32_t length)
{
    for(int i = 0; i < length; i++)
    {
        printf("%x", * start);
        start++;
    }
}
