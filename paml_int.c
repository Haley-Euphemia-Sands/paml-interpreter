/*
(c) Haley Euphemia Eleanor Ashley Lisa Praesent (Codeawayhaley) 6-10-2017
This work is licensed under a Creative Commons Attribution-ShareAlike 4.0 International License.
See: http://creativecommons.org/licenses/by-sa/4.0/
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

void sig_handler(int signo)
{
  if (signo == SIGCHLD){
    exit(0);
  }
}

int main(){
	char *input, *history, *yesno, *parsematrix;
	input = (char *) malloc(sizeof(char) * 65536);
	yesno = (char *) malloc(sizeof(char));
	parsematrix = (char *) malloc(sizeof(char));
	int count = 0;
	int dimensions=0;
	char * token[100];
	if (signal(SIGINT, sig_handler) == SIG_ERR){
		perror("Failed!\n");
		exit(-1);
	}
	while (1){
		printf("paml interpreter | [insert working directory]>> \n");
		gets(input);
		int forkloop = (int) fork();
		if (forkloop == 0){
			while( (token[count-1] = strsep(&input," ")) != NULL ){
				if (strcmp(token[0],"exit")==0){
					exit(0);
				}
				count++;
			}
			count = 0;
		}
		else if (forkloop < 0) {
			exit(-2);
		}
		
	}
}