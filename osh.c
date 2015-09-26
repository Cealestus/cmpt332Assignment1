

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>




int
main()
{
	

	//char ar[30];
	//fgets(ar , 40, stdin);
	//char *str2 = "exit";

	//if (strncmp(ar, str2, 1000)){
	//	return 0;
	//}

	//printf( "%s\n" , ar);
	
	
	char *line = NULL;
	ssize_t bufsize = 0;
	getline(&line, &bufsize, stdin);
	printf("%s\n", line);

	
	char **chArray  = malloc(128 * sizeof(char*));
	char *pch;

	int pos=0;
	pch = strtok( line, " \n");

	while(pch != NULL) {
		chArray[pos]= pch;
		pos= pos + 1;
		
		pch = strtok( NULL, " \n ");
	}
	chArray[pos] = NULL;
	
	


/*
	int rc = fork();
        /* fork failed; exit
	if (rc < 0) {
		fprintf(stderr, "fork failed\n");
		exit(1);
	/* child: redirect standard output to a file
	} else if (rc == 0) { 
		close(STDOUT_FILENO);
		open("./p4.output", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
			
		/* now exec "wc"...
		char *myargs[3];
		myargs[0] = strdup("wc");
		myargs[1] = strdup("p4.c");
		myargs[2] = NULL;
		execvp(myargs[0], myargs);
	} else { /* parent
	int wc = wait(NULL);
	}
*/
	return 0;
}

