#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

#include "input.h"
#include "parser.h"
#include "mem_management.h"

extern char **environ;

int main()
{
  printf("This is simple shell program developed for learining objective\n");
  input input_line;

  while (1)
  { 
    printf("Adel's shell is ready > ");
    take_input(&input_line);
    set_number_of_args(&input_line);
    if ( isThereArgs(&input_line) == 0 )
          continue; ; 
    alloc_mem_for_arg(&input_line);
    parse_input(&input_line); 
   
    pid_t pid = fork();
    if (pid > 0) // executer process
    {
      int wstatus;
      waitpid(pid, &wstatus, 0);
      dealloc_mem_for_arg(&input_line) ; 
    }

    else if (pid == 0) // the new process
    {
      char *const newargv[] = {NULL};
      char *const newenvp[] = {"ADEL", NULL};


	int flag = execvp(input_line.arg_list[0] ,(input_line.arg_list));

      if (-1 == flag)
      {
        printf("Failed to execute the program\n");
        dealloc_mem_for_arg(&input_line) ; 

        return -1;
      }
      break;
    }
  }
}

