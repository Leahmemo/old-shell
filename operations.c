#define _GNU_SOURCE
#include "main.h"

/**
 * gline - gets a line from a stream
 * @argc: argument count
 * @argv: argument vector
 * Return: the the number of characters read
 */
int gline(int argc, char *argv[])
{
	FILE *filePtr;
	char *lineBuffer = NULL;
	size_t bufferSize = 0;
	ssize_t bytesRead;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	filePtr = fopen(argv[1], "r");
	if (filePtr == NULL)
	{
		perror("fopen");
		exit(EXIT_FAILURE);
	}

	while ((bytesRead = getline(&lineBuffer, &bufferSize, filePtr)) != -1)
	{
		printf("Retrieved line of length %lu:\n", bytesRead);
		fwrite(lineBuffer, bytesRead, 1, stdout);
	}

	free(lineBuffer);
	fclose(filePtr);
	exit(EXIT_SUCCESS);
}
