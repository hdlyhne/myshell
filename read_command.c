#include <stdio.h>
#include "parse_command.h"

/*
 * Reads the command from the command line and passes it to
 * parse_command() to parse it.
 */
void read_command()
{
	char * commandstring;
	char buf[1024];
	
	//read command
	fgets(buf, 1024, stdin);
	commandstring = buf;
	
	//pass the command to be parsed
	parse_command(commandstring);
}
