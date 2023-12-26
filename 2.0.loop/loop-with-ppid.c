#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
	for (;;)
	{
		pid_t pid = getpid();
		pid_t ppid = getppid();
		printf("PID is %d, and PPID is %d\n", pid, ppid);
	}
}