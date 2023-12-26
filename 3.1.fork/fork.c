#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <err.h>

static void child()
{
	printf("I'm child! my pid is %d.\n", getpid());
	exit(EXIT_SUCCESS);
}

static void parent(pid_t pid_c)
{
	printf("I'm parent! my pid is %d and the pid of my child is %d.\n", getpid(), pid_c);
	exit(EXIT_SUCCESS);
}

int main(void)
{
	pid_t ret = fork();
	if (ret == -1)
	{
		printf("fork() failed.\n");
		err(EXIT_FAILURE, "fork() failed.");
	}

	if (ret == 0)
	{
		// fork 会返回0给子进程
		child();
	}
	else
	{
		// fork 会返回新创建的子进程的进程ID给父进程
		parent(ret);
	}

	printf("shouldn't reach here.\n");
	err(EXIT_FAILURE, "shouldn't reach here.");
}