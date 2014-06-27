#include <stdio.h>
#include <string.h>

char * argv[100];

void clear_out(int startingelement);
int get_input();
char * get_input_file();
int get_output();
char * get_output_file();
void parse_command(char * commandstring);
