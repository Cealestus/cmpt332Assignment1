

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
	int arPos;
	int wc;
	int rc;	
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
	
	arPos = pos-1;
	

	while(arPos>0 ){
		
		if(*chArray[arPos] == '|'){
			int pip[2];
			pipe(pip);
			rc = fork();
			
			if (rc<0){
				fprintf(stderr, "fork Failed\n");
				exit(1);
			}
			else if (rc ==0) {
				close(pip[0]);
				dup2(pip[1],STDOUT_FILENO);
				close(pip[1]);
				
				execvp(chArray[arPos +1], chArray);
				printf(" shouldnt hit here");
			}
			else {
				wc = wait(NULL);
				dup2(pip[0], STDIN_FILENO);
			}
			chArray[arPos] =NULL;
		}
		arPos--;

	}	
	execvp(chArray[0], chArray);

	return 0;
}

