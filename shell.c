#include "main.h"

/**
 * main - our version of a simple shell
 *
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: Hopefully a well working shell
 */

int main(void)
{
	char *argv[] = {"bin/ls", "-l", "/usr/", NULL};
	pid_t child_pid = getpid();
	int status;
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		printf("$shell> ");

		fgets(command, sizeof(command), stdin);

		command[strcspn(command, "\n")] = '\0';

		if (strcmp(command, "exit") == 0)
		{
			printf("You are leaving the shell ....\n");
			break;
		}



	printf("Before execve\n");

	 printf("Ready to fork...\n");
        child_pid = fork();

         if (child_pid == -1)
         {
		 perror ("Error: \n");
                 return (1);
         }
	 if (child_pid == 0)
         {
		 printf("Waiting....\n");
		 printf("Executing\n");
		execve("/bin/ls", argv, NULL) == 1;
		 perror("Error: \n");
                 sleep(3);
         }
         else
          {
                  wait(&status);
                  printf("All better now...\n");
          }

	  printf("After execve\n");
	  return (0);
	}
	printf("Still in shell");
	return (0);
}
