/*@file - profiler.h
 *@brief - Configure Systick counter and getTicks counts the CPU cycles taken for each function
 *@author Vipraja Patil & Nikhil Divekar
 *@date 3 December 2017
 */

#include <stdio.h>
#include <stdint.h>

/*
 *@function - Systick_config()
 *@brief - Sets up the systick timer
 *@param - void
 *@return  void
 */
void SysTick_config();


/*
 *@function - getTicks()
 *@brief - gets the clock cycles spent
 *@param - option which selects the function to be profiled
 *@return  void
 */
void getTicks(uint8_t option);
