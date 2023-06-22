#include "main.h"

/**
 * main - our version of a simple shell
 * Return: Hopefully a well working shell
 */

int main(void)
{
	pid_t child_pid = getpid();
	/*int status;*/
	size_t n = 0;
	char *buf = NULL;
	char **argv = NULL;
	char **envp = NULL;
	char *

	while (1)
	{
		printf("$shell> ");
		fflush(stdout);

		if(getline(&buf, &n, stdin) == -1)
		{
			perror("Error\n");
			break;
		}

		buf[strcspn(buf, "\n")] = '\0';
		if (strcmp(buf, "exit") == 0)
		{
			printf("You are leaving the shell ....\n");
			break;
		}
		printf("Before execve\n Ready to fork....\n ");
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error: \n");
			return (1);
		}
		if (child_pid == 0)
		{
			printf("Waiting....\n Executing\n");
			argv = (char **)malloc(sizeof(char *) * 2);
			argv[0] = strdup("bin/ls");
			argv[1] = NULL;

			envp = (char **)malloc(sizeof(char *));
			envp[0] = NULL;
			execve(argv[0], argv, envp);
			perror("Error: \n");
			sleep(3);
			exit(1);
		}
		else
		{
			wait(NULL);
			printf("All better now...\n");
		}
		free(argv[0]);
		free(argv);
		free(envp);
		/*free(buf);*/
		/*buf = NULL;*/
	}
	free(buf);
	return (0);
}

