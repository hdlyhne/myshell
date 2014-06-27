#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

char * argv[100];

void file_find(char fullpaths[100], char * pathargs[100])
{
	int i = 0;
	int j = 0;
	char mypath[200];
	char * envpath;
    char * pch;
	char * cmd = argv[0]; //the command to be executed
	 
	//get environment variable
    envpath = getenv("PATH");
    
    //copy to mypath
    strcpy(mypath, envpath);  
    
    //parse using ":" delimeter  
    pch = strtok(mypath, ":");
    while (pch != NULL)
	{
		pathargs[i]=pch;
		i++;
		pch = strtok(NULL, ":");
	}
	
	//set last element to null string
	pathargs[i] = '\0';
	
	//append /$COMMANDNAME to path; breaks if file is found
	while(pathargs[j] != NULL)
	{
		fullpaths[0] = '\0';
		strcpy(fullpaths, pathargs[j]);
		strcat(fullpaths, "/");
		strcat(fullpaths, cmd);
		if(open(fullpaths, O_RDONLY) >= 0)
		{
			//store full pathname in first element
			argv[0] = fullpaths; 
			break;
		}
		j++;
	}
	//indicates that the loop finished without breaking, file not found
	if(pathargs[j] == NULL) 
	{
		printf("File not found.\n");
	}
}
