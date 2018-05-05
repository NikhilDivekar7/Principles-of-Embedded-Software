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
int8_t * buffer;
int8_t * head;
int8_t * tail;
int8_t size;
int8_t count;
int8_t peek;
int8_t waitcode;
}CB_struct_t;

CB_status CB_init(CB_struct_t * ptr , int8_t length);
CB_status CB_buffer_add_item(CB_struct_t * ptr,int8_t add);
CB_status CB_buffer_remove_item(CB_struct_t * ptr,int8_t remove);
CB_status CB_is_full(CB_struct_t * ptr);
CB_status CB_is_empty(CB_struct_t * ptr);
CB_status CB_peek(CB_struct_t * ptr , int8_t position, int8_t * src);
CB_status CB_Destroy(CB_struct_t * ptr);

#endif
