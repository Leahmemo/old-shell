#include "main.h"
/**
 * main - our version of a simple shell
 * Return: Hopefully a well working shell
 */
int main(void)
{
	pid_t child_pid;
	int status;
	char *command = NULL;
	size_t n = 0;
	char *argv[] = {"/bin/sh", "-c", NULL, NULL};

	while (1)
	{
		printf("$shell> ");
		fflush(stdout);
	if (getline(&command, &n, stdin) == -1)
	{
		perror("Error: ");
		break;
	}
	command[strcspn(command, "\n")] = '\0';
	if (strcmp(command, "exit") == 0)
	{
		printf("You are leaving the shell ....\n");
		break;
	}
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error: ");
		exit(1);
	}
	if (child_pid == 0)
	{
		printf("Executing...\n");
		argv[2] = command;
		execve("/bin/sh", argv, NULL);
		perror("Error: ");
		exit(1);
	}
	else
	{
		wait(&status);
		printf("All better now...\n");
	}
	}
	free(command);
	return (0);
}
