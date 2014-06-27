CC=gcc
CFLAGS=-Wall -g
LIBS=

default: prog2

prog2: myshell.o print_prompt.o read_command.o parse_command.o file_find.o fork_and_exec.o
	$(CC) $(CFLAGS) -o prog2 myshell.o print_prompt.o read_command.o parse_command.o file_find.o fork_and_exec.o

print_prompt.o: print_prompt.c print_prompt.h
	$(CC) $(CFLAGS) -c print_prompt.c

read_command.o: read_command.c read_command.h parse_command.h
	$(CC) $(CFLAGS) -c read_command.c
	
parse_command.o: parse_command.c parse_command.h
	$(CC) $(CFLAGS) -c parse_command.c
	
file_find.o: file_find.c file_find.h
	$(CC) $(CFLAGS) -c file_find.c
	
fork_and_exec.o: fork_and_exec.c fork_and_exec.h parse_command.h
	$(CC) $(CFLAGS) -c fork_and_exec.c
	
myshell.o: myshell.c
	$(CC) $(CFLAGS) -c myshell.c
	
clean:
	rm -f prog2 *.o *~
