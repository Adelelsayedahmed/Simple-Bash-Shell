#include "input.h"
#include <stdio.h>
#include <sys/types.h>
#include <string.h>
void take_input(input *in_line)
{

    fgets(in_line->buffer, buff_size, stdin);

    in_line->input_line_size = strlen(in_line->buffer);
    in_line->buffer[in_line->input_line_size - 1] = '\0';
}

void set_number_of_args(input *in_line)
{
    u_int8_t arg_count = 0;
    char_st prev_state = WAS_CHAR;
    if (in_line->buffer[0] == ' ' || in_line->buffer[0] == '\t' || in_line->buffer[0] == '\0')
    {
        prev_state = WAS_SPACE;
    }
    else
    {
        arg_count++;
        prev_state = WAS_CHAR;
    }

    for (int i = 1; i < in_line->input_line_size; i++)
    {
        if (prev_state == WAS_SPACE && in_line->buffer[i] != ' ' && in_line->buffer[i] != '\t' && in_line->buffer[i] != '\0')
        {
            arg_count++;
            prev_state = WAS_CHAR;
        }

        else if (prev_state == WAS_CHAR)
        {
            if (in_line->buffer[i] == ' ' || in_line->buffer[i] == '\t')
            {
                prev_state = WAS_SPACE;
            }
            continue;
        }
    }
    in_line->arg_count = arg_count;
}
