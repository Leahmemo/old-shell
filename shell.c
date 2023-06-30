#include "main.h"

/**
 * displayShell - A function that displays the shell prompt
 *
 */

void displayShell(void)
{
	printf("Shell >> ");
	fflush(stdout);
}

/**
 * command_execution -  function that executes a command
 * @command: The command to be executed
 */

void command_execution(const char *command)
{
	int response = system(command);
	if (response == -1)
	{
		perror("Sorry, does not recognise command");
	}
}


/**
 * main - A function that returns our version of a simple shell
 * Return: Hopefully a well working shell
 */
int main(void)
{
	char *command = NULL;
	size_t n = 0;

        while (1)
        {
                displayShell();
        if (getline(&command, &n, stdin) == -1)
        {
                perror("Exiting shell ");
                break;
        }
        command[strcspn(command, "\n")] = '\0';

        if (strcmp(command, "exit") == 0)
        {
                printf("You are leaving the shell...Sad to see you go...\n");
		break;
	}
	command_execution(command);
	}
	free(command);
	return (0);
}
