#ifndef PARSER_H
#define PARSER_H

#include "input.h"

void parse_input(input *in_line);
int find_next_arg_occ(char *buff, int index ,  int len );
int isThereArgs(input *in_line);
#endif