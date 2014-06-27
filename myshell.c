#include <stdio.h>
#include <string.h>
#include "print_prompt.h"
#include "read_command.h"
#include "parse_command.h"
#include "file_find.h"
#include "fork_and_exec.h"

char * argv[100];

int main()
{
	char fullpaths[100]; 
	char * pathargs[100];
	
	//shell initialization
	
	//inform user that myshell can be terminated by entering q or quit
	printf("To terminate myshell, enter q or quit and hit return.\n");
	
	// Main loop
	while(1)
	{
		// Print the prompt string.
		print_prompt();

		// Read the command line and parse it.
		read_command();
		
		// Quit program if "q" or "quit" are entered at the command line.
		if((strcmp(argv[0],"q") == 0) || (strcmp(argv[0],"quit") == 0))
		{
			break;
		}
		
		// Find the full pathname for the file.
		file_find(fullpaths, pathargs);
		
		// Create a process to execute the command.
		fork_and_exec();
		
		// Clear out array.
		clear_out(0);
	}
	return 0;

}
