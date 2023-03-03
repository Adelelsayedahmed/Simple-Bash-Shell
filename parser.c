#include "parser.h"

int find_next_arg_occ(char *buff, int index, int len)
{
  int occ_index = -1;
  for (int i = index; i < len; i++)
  {
    if (buff[i] != ' ' && buff[i] != '\t')
    {
      occ_index = i;
      break;
    }
  }
  return occ_index;
}

void parse_input(input *in_line)
{
  int start_index = 0;
  int arg_num = 0;
  int curr_index = 0;
  for (; arg_num < in_line->arg_count; arg_num++)
  {
    start_index = find_next_arg_occ(in_line->buffer, start_index, in_line->input_line_size);
    curr_index = 0;
    while (in_line->buffer[start_index] != ' ' && in_line->buffer[start_index] != '\t' & in_line->buffer[start_index] != '\0')
    {
      in_line->arg_list[arg_num][curr_index++] = in_line->buffer[start_index++];
    }
    in_line->arg_list[arg_num][curr_index] = '\0';
  }
}

int isThereArgs(input *in_line)
{
  if (in_line->arg_count == 0)
    return 0;
  else
    return 1;
}