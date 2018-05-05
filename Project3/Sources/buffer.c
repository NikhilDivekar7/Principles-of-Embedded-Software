/* Filename : buffer.c
 * Brief : Contains all the circular buffer functions
 * Created on: Dec 7, 2017
 * Author: Nikhil Divekar and Vipraja Patil
 */

#include <stdint.h>
#include <stdlib.h>
#include "buffer.h"
#include <stdint.h>
#include "logger.h"

LoggedItem_t * data_received;

CB_status CB_init(CB_struct_t * ptr , int32_t length)
{
	CB_status status;

	if (ptr ->buffer == NULL || length <= 0)
    	{
        	status = FAIL;
    	}
 	else
    	{
		    ptr -> buffer = (int8_t *)malloc(sizeof(int8_t)* length);
        	ptr -> head = ptr->buffer;
        	ptr -> tail = ptr->buffer;
        	ptr -> count = 0;
        	ptr -> size = length;
        	ptr -> peek = 0;
        	status = Allocate_Free;
    	}
 	return status;
}


__attribute__((always_inline)) CB_is_full(CB_struct_t * ptr)
{
	CB_status status;
	if(ptr == NULL)
	{
		status = FAIL;
	}
	else if(ptr -> count == ptr -> size)
    	{
        	status = Buffer_Full;
    	}
    	else
    	{
        	status = Buffer_Not_Full;
    	}
 	return status;
}

__attribute__((always_inline)) CB_is_empty(CB_struct_t * ptr)
{
	CB_status status;
	if(ptr == NULL)
		{
			status = FAIL;
		}
	else if(ptr -> count == 0)
    	{
        	status = Buffer_Empty;
    	}
    	else
    	{
        	status = Buffer_Not_Empty;
    	}
 	return status;
}

CB_status CB_buffer_add_item(CB_struct_t * ptr,int8_t add)
{
	CB_status status;
	if(ptr == NULL)
		{
			status = FAIL;
		}
	else if(ptr -> count == ptr -> size)
    	{
        status = Over_Fill;
		return status;
    	}
 	else if(ptr -> head == ptr-> buffer + ptr-> size -1)
 	{
   		*ptr-> head = add;
   		ptr-> head = ptr-> buffer;
   		ptr-> count++;
   		status = Wrap_Add;
 	}
 	else
 	{
		*ptr-> head = add;
 		ptr -> head++;
		ptr -> count++;
   		status = Added;
 	}
 	return status;
}

int8_t CB_buffer_remove_item(CB_struct_t * ptr,int8_t remove)
{
	static int8_t temp;
	CB_status status;
	if(ptr == NULL)
		{
			status = FAIL;
		}
	else if(CB_is_empty(ptr) == Buffer_Empty)
    	{
		status = Over_Empty;
        	return status;
    	}
 	else if(ptr -> tail == ptr-> buffer + ptr-> size -1)
 	{
		remove = *ptr-> tail;
  		ptr -> tail = ptr->buffer;
   		ptr->count--;
   		status = Wrap_Remove;
 	}
 	else
 	{
   		temp = *ptr->tail;
   		remove = temp;
   		ptr->tail++;
   		ptr->count--;
   		status = Removed;
 	}
 	return temp;
}

CB_status CB_peek(CB_struct_t *ptr ,int8_t position, int8_t * src)
{
	CB_status status;
	if(ptr == NULL)
		{
			status = FAIL;
		}
	else if(position <= 0 || position >= ptr-> size)
	{
   		status = FAIL;
	}
	else
	{
  		ptr-> peek = *( ptr-> buffer + position );
  		status = SUCCESS;
	}
	return status;
}

CB_status CB_Destroy(CB_struct_t * ptr)
{

  	CB_status status;
  	if(ptr == NULL)
  			{
  				status = FAIL;
  			}
  	else{
 	free( ptr-> buffer );
 	status = SUCCESS;
  	}
 	return status;
}
