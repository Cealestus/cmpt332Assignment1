

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>




int
main()
{
	char *line = NULL;
	size_t bufsize = 0;
	char ** chArray = malloc(128 * sizeof(char*));
	char *pch;
	int pos = 0;
	
	char osh[4] = "osh>";
	printf("%s", osh);


	getline(&line, &bufsize, stdin);
	
	pch = strtok( line, " \n");

	while(pch != NULL) {
		chArray[pos]= pch;
		pos= pos + 1;
		
		pch = strtok( NULL, " \n ");
	}

	
	chArray[pos] = NULL;
	
		
	execvp(chArray[0],chArray);
	int arPos ;
	for(arPos = pos; arPos>0; arPos-- ){
		if(*chArray[arPos] == '|'){
			int rc = fork();
			if (rc<0){
				fprintf(stderr, "fork Failed\n");
				exit(1);
			}
			else if (rc ==0) {
				execvp(chArray[arPos +1], chArray);
				printf(" shouldnt hit here");
			}
			else {
				int wc = wait(NULL);
			}

		}

	

	}

	return 0;
}

