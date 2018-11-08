#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void sighandler(int sig)
{
	if (sig == SIGINT)
	{
		int file = open("signal.txt", O_WRONLY | O_CREAT, 0666);
		
		if (file < 0) 
		{
			printf("FAILED TO WRITE FILE\n");
			exit(1);
		}

		write(file, "Program exited due to SIGINT (2)", 32);
		close(file);
		exit(0);
	}
	else if (sig == SIGUSR1)
	{
		printf("Parent pid: %d\n", getppid());
		sleep(1);
	}
}

int main()
{
	signal(SIGUSR1, sighandler);
	signal(SIGINT, sighandler);

	while(1)
	{
		printf("PID of this process: %d\n", getpid());
		sleep(1);
	}
	return 0;
}
