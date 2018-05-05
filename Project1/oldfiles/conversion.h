/*
 * @file conversion.h
 * @brief An abstraction for data manipulation functions
 *
 * This header file provides the prototypes of the function for
 * various data manipulation operations.
 *
 * @author Vipraja Patil & Nikhil Divekar
 * @date 3 October 2017
 *
 */


#ifndef CONVERSION_H_  
#define CONVERSION_H_

/*
 *@brief - Int to Ascii
 *This function will convert data from a standard integer type into an ASCII string.
 *The number you wish to convert is passed in as a signed 32-bit integer.
 *@param - data Input Integer
 *@param - ptr  Pointer which points towards the Input
 *@param - base It can be 2,8,10,16
 *@return the length of the converted data
 */
uint8_t my_itoa(int, char*, uint32_t);



/*
 *@brief - Ascii to Int
 *This function will convert data from an ASCII represented string into an integer type.
 *You should be able to support bases 2 to 16.
 *@param - ptr  Pointer which points towards the Input
 *@param - digits Number of characters
 *@param - base It can be 2,8,10,16
 *@return the converted 32-bit signed integer
 */
int32_t my_atoi(char*, uint8_t, uint32_t);


/*
 *@brief - Big to little endian
 *This function converts an array of data in memory from a big endian representation to little endian.
 *@param - data Input Integer
 *@param - length Length of the bytes
 *@return an error if the conversion fails for any reason
 */
int8_t big_to_little32(uint32_t*, uint32_t);


/*
 *@brief - Little to big endian
 *This function converts an array of data in memory from a little endian representation to big endian.
 *@param - data Input Integer
 *@param - length Length of the bytes
 *@return an error if the conversion fails for any reason
 */
int8_t little_to_big32(uint32_t*, uint32_t);

#endif // CONVERSION_H_
