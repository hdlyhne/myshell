#include <stdio.h>
#include <string.h>

char * argv[100];

/*
 * Clear out array beginning at the passed startingelement.
 */
void clear_out(int startingelement)
{
	int x = startingelement;
	
	while (argv[x] != NULL)
	{
		argv[x] = NULL;
		x++;
	}
}

/*
 * Check the array for "<" to determine whether the command contains
 * input redirection. If it does contain input redirection, the function
 * returns the index at which "<" is found. If there is no input 
 * redirection, the function returns 0.
 */
int get_input()
{
	int inputindex = 0;
	int i = 0;
	
	while (argv[i] != NULL)
	{
		if (strcmp(argv[i],"<") == 0)
		{
			inputindex = i; 
		}
	i++;
	}
	return inputindex;
}

/*
 * This function returns the name of the input file.
 */
char * get_input_file()
{
	int x = get_input();
	char * filename = argv[x + 1];
	
	return filename;
}

/*
 * Check the array for ">" to determine whether the command contains
 * output redirection. If it does contain output redirection, the function
 * returns the index at which ">" is found. If there is no output 
 * redirection, the function returns 0.
 */	
int get_output()
{
	int outputindex = 0;
	int i = 0;
	
	while (argv[i] != NULL)
	{
		if (strcmp(argv[i],">") == 0)
		{
			outputindex = i; 
		}
	i++;
	}
	return outputindex;
}

/*
 * This function returns the name of the output file.
 */
char * get_output_file()
{
	int x = get_output();
	char * filename = argv[x + 1];
	
	return filename;
}

/* 
 * Parse passed commandstring using whitespace delimeter and store in 
 * array. 
 */
void parse_command(char * commandstring)
{
	char * pch;
	int i = 0;
	
	//parse command with space and new line delimeters
	pch = strtok(commandstring, " \n\t");
	
	//store in argv
	while (pch != NULL)
	{
		argv[i]=pch;
		i++;
		pch = strtok(NULL, " \n\t");
	}
}
