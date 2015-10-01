

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

#define MAXARGS 10




struct commands
{
	char *arg[4];
};


int
main()
{
	char *line = NULL;
	size_t bufsize = 0;
	char ** chArray = malloc(128 * sizeof(char*));
	char *pch;
	int pos = 0;
	int pos2 = 0;
	/*int arPos;
	int wc;
	int rc;*/
	 
	struct commands com[5];

	char osh[4] = "osh>";
	while(1){	
		
	

		printf("%s", osh);
		
		/*com = malloc(sizeof(MAXARGS/2));*/
			
		getline(&line, &bufsize, stdin);
		
		
		if(strcmp(line, "exit\n")==0){
			return 0;
		}
		
		pch = strtok( line, " \n");
		
		int i ;
		int x;
		for (i = 0 ; i <= 3 ; i++ ) {
		         for (x =0; x<= 3; x++){
		                 if(com[i].arg[x] !=NULL){
			                   com[i].arg[x] = NULL;
				 }
			}
		}



		while(pch != NULL) {
			if(strcmp(pch,"|")==0){
				pos++;
				pos2=0;
				pch=strtok(NULL, " \n");
			}
			com[pos].arg[pos2]= pch;
			pos2 = pos2 + 1;
			
			pch = strtok( NULL, "|\n ");
			
		}
		int a;
		int b;
		for ( a = 0 ; a <= 2 ; a++ ) {
			for (  b = 0; b <= 3; b++){
				if(com[a].arg[b] != NULL){
					printf("%s", com[a].arg[b]);
				}
			}
			printf("\n");
		}






		chArray[pos] = NULL;
		/*execvp(chArray[0], chArray);*/
	}

	
	
/*
	
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
				
				dup2(pip[1],0);
				close(pip[1]);
				
				execvp(chArray[arPos +1], chArray);
				printf(" shouldnt hit here");
			}
			else {
				wc = wait(NULL);
				dup2(pip[0], 1);
				close(pip[0]);
			}
			chArray[arPos] =NULL;
		}
		arPos--;

	}	
	if(pipeDelim == 0){
		execvp(chArray[0], chArray);
	}

	*/
	return 0;
}

