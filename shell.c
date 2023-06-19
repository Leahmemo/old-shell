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
		 execve("/bin/ls", argv, NULL);
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

