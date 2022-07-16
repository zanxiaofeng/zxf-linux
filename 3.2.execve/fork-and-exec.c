#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <err.h>

static void child(){
	char  *args[] = {"/bin/echo", "hello davis", NULL};
	printf("I'm child! my pid is %d.\n", getpid());
	fflush(stdout);
	execve("/bin/echo", args, NULL);
	err(EXIT_FAILURE, "execev() failed");
}


static void parent(pid_t pid_c){
	printf("I'm parent! my pid is %d and the pid of my child is %d.\n", getpid(), pid_c);
    exit(EXIT_SUCCESS);
}


int main(void){
	pid_t ret = fork();
	if (ret == -1){
		err(EXIT_FAILURE, "fork() failed");
	}

	if (ret == 0){
		//fork 会返回0给子进程
		child();
	} else {
		//fork 会返回新创建的子进程的进程ID给父进程
		parent(ret);
	}

	err(EXIT_FAILURE, "shouldn't reach here");
}