/* dma.h
 * brief : buffer.h
 * In this file, we create the buffer structure and enums returned by circular buffer.
 * Created on: Nov 30, 2017
 * Author: Nikhil Divekar & Vipraja Patil
 */

#ifndef __CIRBUFF_H__
#define __CIRBUFF_H__

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

typedef enum{
SUCCESS,
FAIL,
Allocate_Free,
Invalid_Pointer,
Non_Initialized_Buffer,
Added,
Removed,
Buffer_Full,
Buffer_Not_Full,
Buffer_Empty,
Buffer_Not_Empty,
Wrap_Add,
Wrap_Remove,
Over_Fill,
Over_Empty
}CB_status;

typedef struct CB_struct {
int32_t * buffer;
int32_t * head;
int32_t * tail;
int32_t size;
int32_t count;
int32_t peek;
}CB_struct_t;

CB_status CB_init(CB_struct_t * ptr , int32_t length);
CB_status CB_buffer_add_item(CB_struct_t * ptr,int8_t add);
int8_t CB_buffer_remove_item(CB_struct_t * ptr,int8_t remove);
__attribute__((always_inline)) CB_is_full(CB_struct_t * ptr);
__attribute__((always_inline)) CB_is_empty(CB_struct_t * ptr);
CB_status CB_peek(CB_struct_t * ptr , int8_t position, int8_t * src);
CB_status CB_Destroy(CB_struct_t * ptr);

#endif
