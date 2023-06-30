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
 * main - A function that returns our version of a simple shell
 * Return: Hopefully a well working shell
 */
int main(void)
{
        pid_t child_pid;
        int status;
        char *command = NULL;
        const char *delim = " \n";
        size_t n = 0;
        /*char *cmd[] = {"bin/sh", "-c", NULL, NULL};*/
        char **argv = NULL;
        int a, b;
        char *token;
        char *tokenised_command;
        char *custom_path = "/bin:/usr/bin";
        int total_tokens = 0;

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

        tokenised_command = strdup(command);

        token = strtok(tokenised_command, delim);

        while (token)
        {
                total_tokens++;
                token = strtok (NULL, delim);
        }

        argv = malloc((total_tokens + 2) * sizeof(char*));

        a = 0;
        token = strtok(command, delim);
        while (token)
        {
                argv[a] = strdup(token);
                token = strtok(NULL, delim);
                a++;
        }
        argv[a] = NULL;

        free(tokenised_command);
        child_pid = fork();
        if (child_pid == -1)
        {
                perror("Error: ");
                exit(1);
        }
        if (child_pid == 0)
        {
                setenv("PATH", custom_path, 1);
               /* argv[0] = "sh";*/
               /* execlp("/bin/sh", "sh", "-c",command, NULL);*/
		execvp(argv[0], argv);
                perror("Error: ");
                exit(1);
        }
        else
        {
                waitpid(child_pid, &status, 0);
        }

        for(b = 0; b < a; b++)
        {
                free(argv[b]);
        }
       /* free(argv);*/
        }
	free(command);
        return (0);
}
