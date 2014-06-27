/* fork.c - example of a fork in a program. The program asks for UNIX
commands to be typed and inputted to a string.  The string is then
"parsed" by locating blanks etc.  Each command and corresponding
arguments are put in a args array.  execvp is called to execute these
commands in child process spawned by fork() */

/* cc -Wall -o fork fork.c */

#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "parse_command.h"

char * argv[100];

/*
 * Creates a process that checks for and handles redirection and 
 * executes a command.
 */
void fork_and_exec()
{
	int pid, status;
	int newfd;
	int newfd2;
	int hasinput = get_input();	
	int hasoutput = get_output();
	char * inputfile = get_input_file();
	char * outputfile = get_output_file();
	
   /*
    * Get a child process.
    */
   if ((pid = fork ()) < 0) {
      perror ("fork");
      exit (1);

      /* NOTE: perror() produces a short error message on the standard
         error describing the last error encountered during a call to
         a system or library function.
      */
   }

   /*
    * The child executes the code inside the if.
    */
   if (pid == 0) 
   {
		//Handle output redirection
		if (hasoutput != 0) 
		{
			clear_out(hasoutput); // Clear array beginning at ">" until end
			if((newfd = open(outputfile, O_CREAT|O_TRUNC|O_WRONLY, 0644))< 0)
			{
				perror(outputfile);
				exit(1);
			}
			dup2(newfd, 1);
		}
	
		// Handle input redirection
		if (hasinput != 0) 
		{
			clear_out(hasinput); // Clear array beginning at "<" until end
			if((newfd2 = open(inputfile, O_RDONLY)) < 0)
			{
				perror(inputfile);
				exit(1);
			}
			dup2(newfd2, 0);
		}

	execvp (*argv, argv);
	perror (*argv);
	exit (1);

      /* NOTE: The execv() and execvp versions of execl() are useful
         when the number of arguments is unknown in advance; The
         arguments to execv() and execvp() are the name of the file to
         be executed and a vector of strings containing the arguments.
         The last argument string must be followed by a 0 pointer.

         execlp() and execvp() are called with the same arguments as
         execl()  and  execv(),  but duplicate the shell's actions in
         searching for an executable file in a list  of  directories.
         The directory list is obtained from the environment.  */
   }

   /*
    * The parent executes the wait.
    */
   while (wait (&status) != pid)
      /* empty */ ;
}
