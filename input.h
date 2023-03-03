#ifndef INPUT_H
#define INPUT_H

#include <sys/types.h>
#define buff_size (1000UL)

enum char_st
{
  WAS_CHAR,
  WAS_SPACE
};
typedef enum char_st char_st;

struct input
{

  char buffer[buff_size];
  size_t input_line_size;
  u_int8_t arg_count;
  char **arg_list;
};
typedef struct input input;

void take_input(input *in_line);
void set_number_of_args(input *in_line);

#endif
