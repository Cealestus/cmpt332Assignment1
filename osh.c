

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>




int
main()
{
	
<<<<<<< HEAD
	//char ar[30];
	//fgets(ar , 40, stdin);
	//char *str2 = "exit";

	//if (strncmp(ar, str2, 1000)){
	//	return 0;
	//}

	//printf( "%s\n" , ar);
>>>>>>> ef5fd8234821c5bf911c16cc57608e255d294dda
	
	char *line = NULL;
	ssize_t bufsize = 0;
	getline(&line, &bufsize, stdin);
	printf("%s\n", line);








/*		
	fgets(      );

	char * pch;
	pch = strtok( argv[], " \n");
	
	while(pch != NULL){
		
		pch = strtok( NULL, " \n ");
	}
	



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

