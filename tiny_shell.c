#include <stdio.h> 
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_LINE 512
#define MAX_HIST 10

#define clear() printf("\033[H\033[J")

typedef struct history{
	char typed_cmd[MAX_LINE];
	char cmdHist[MAX_HIST][MAX_LINE];
	int hist_Num;
} HISTORY;

typedef struct process {
	pid_t id;
	char* cmd;
} PROCESS;

void initialize_Shell();
int my_system(char *line);

int main(){
	char cmd[MAX_LINE];
	char *argv[MAX_LINE];
	HISTORY history;
	PROCESS process;

	while(1){
		initialize_Shell();
		printf("\nCOMMAND >> ");
		fflush(stdout);
		fgets(cmd, MAX_LINE, stdin);
		printf("\n");
		fflush(stdout);

		if(strcmp(cmd, "exit") == 0) break;

		if(strlen(cmd) > 1){
			my_system(cmd);
			return(0);
		}
		else{
			exit(0);
		}
	}
}

void initialize_Shell(){
	clear();
	printf("\n\n-----------------------------");
	printf("\n-----------MY SHELL----------");
	printf("\n-----------------------------\n");
}

int my_system(char *line){
	#ifdef FORK
		//child processing using fork() function
		pid_t pid;
		int status;

		pid = fork();
		if(pid < 0){
			printf("ERROR: forking child process failed");
			exit(1);
		}
		else if(pid == 0){
			//child
			
			sleep(3);
			printf("\nI'm your baby!\n");
			execl("/bin/sh", "sh", "-c", line, (char *) 0);
		}
		else {
			//parent
			waitpid(pid, &status, 0);
			printf("\nI'm your father\n");
			
		}
		return(0);
	#elif VFORK

	#elif CLONE

	#elif PIPE

	#else 

	#endif
}