/*@file - project2.h
 *@brief - This function is called first by the main function.
 *@author Vipraja Patil & Nikhil Divekar
 *@date 3 December 2017
 */

#ifndef __PROJECT2_H__
#define __PROJECT2_H__

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

/*
 *@function - project2()
 *@brief - Configures all required elements
 *@param - void
 *@return  void
 */
void project2();

/*
 *@function - getStatistics()
 *@brief - Analyze all the characters received
 *@param - void
 *@return  void
 */
void getStatistics(int8_t data);

/*
 *@function - printStatistics()
 *@brief - Prints the analyzed data
 *@param - void
 *@return  void
 */
void printStatistics();

#endif
