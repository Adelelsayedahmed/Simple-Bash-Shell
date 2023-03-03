
#include "mem_management.h"
#include "stddef.h"
#include <stdlib.h>

void dealloc_mem_for_arg(input *in_line)
{

  /*deallocate multiple arrays of chracter with maximum argument length*/
  for (size_t i = 0; i < in_line->arg_count; i++)
  {
   free(in_line->arg_list[i]) ;
    in_line->arg_list[i] = NULL ; 
  }
  free(in_line->arg_list) ; 
  in_line->arg_list = NULL ; 


}
void alloc_mem_for_arg(input *in_line)
{
  in_line->arg_list = (char **)malloc(sizeof(char *) * (in_line->arg_count + 1));
  in_line->arg_list[in_line->arg_count] = NULL ; 
  /*Create multiple arrays of chracter with maximum argument length*/
  for (size_t i = 0; i < in_line->arg_count; i++)
  {
    in_line->arg_list[i] = (char *)malloc(sizeof(char) * 50);
  }
}