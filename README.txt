------
Simple Shell
By: Hannah Lyhne
02/14/2014
------

This is my solution for assignment 2 in CSCI 340.

The program is made up of the following parts:
1. print_prompt simply prints the prompt
2. read_command reads the user input and parses it
3. parse_command parses the command
4. file_find finds the full pathname of the file
5. fork_and_exec creates a process to execute the command
6. myshell contains the main
7. Makefile 

The program is a simple shell that runs in the command line
that prompts the user to enter a command, with or without
input/output redirection, and processes and executes the 
user's command.

To run this program:
$ make
$ ./prog2

At any point during the execution of the program, you may
quit by typing q and pressing return.

