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
	  
    if ( 0 == isThereArgs(&input_line)  ) // check if the user press enter and the input line is empty or full of spaces 
   	{ 
	    continue; 
    	}
    alloc_mem_for_arg(&input_line);
    parse_input(&input_line); 
    pid_t pid = fork();
    if (pid > 0) // shell process
    {
      int wstatus;
      waitpid(pid, &wstatus, 0);	// suspend the shell untill the new process terminated 
      dealloc_mem_for_arg(&input_line) ; // deallocate the memory that is dynamically allocated to store the arguments
    }

    else if (0 == pid) // the new process
    {

	int flag = execvp(input_line.arg_list[0] ,(input_line.arg_list)); // load the image of the new program by passing the name of the executable and the argv[]

      if (-1 == flag)
      {
        printf("Failed to execute the program\n");
        dealloc_mem_for_arg(&input_line) ; // deallocate the memory that is dynamically allocated to store the arguments in case of faliure to execute the new process

        return -1;
      }
      break;
    }
  }
}

