#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

void main()
{
pid_t child;
//child =fork();

if(fork()==0){
	printf("---------CHILD PROCESS------------");
	printf("\nChild ID: %d", getpid());
	printf("\nParent ID: %d", getppid());
	exit(0);
	}
else{
	// wait makes child process to return it's ID after termination.. It also tells exit status(i.e why child terminated).. Here "NULL"
	child = wait(NULL);
	printf("\n----------PARENT PROCESS----------");
	printf("\nParent ID: %d", getpid());
	printf("\nChild ID: %d\n", child);
	}
}	
