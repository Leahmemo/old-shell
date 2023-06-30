#include "main.h"

/**
 * strcmp - compares two strings
 * @str1: first string
 * @str2: second string
 *
 * Return: 0
 */
int strcmp(const char *str1, const char *str2)
{
	while (*str1 != '\0' && *str2 != '\0')
	{
		if (*str1 < *str2)
			return (-1);
		else if (*str1 > *str2)
			return (1);

	str1++;
	str2++;
	}

	if (*str1 == '\0' && *str2 == '\0')
		return (0);
	else if (*str1 == '\0')
		return  (-1);
	return (0);
}
/**
 * strcspn - checks if the current character of a string is present
 * @str1: first string
 * @str2: second string
 *
 * Return: the length of str1
 */
size_t strcspn(const char *str1, const char *str2)
{
	size_t count = 0;

	while (*str1 && !strchr(str2, *str1))
	{
		str1++;
		count++;
	}
	return (count);
}

/**
 * our_strtok - A function that tokenises the user's input
 *
 * @str: The string to tokenise
 *
 * @delim: The delimitor separator
 *
 * Return: Tokens
 *
 */
char *our_strtok(char *str, const char *delim)
{
	static char *token;
	static char *next;

	if (str == 0)
	{
		token = str;
	}
	else if (token == NULL)
	{
		return (NULL);
	}
	else if (*token == '\0')
	{
		return (NULL);
	}
	token = token + strspn(token, delim);

	if (*token == '\0')
	{
		next = NULL;
		return (NULL);
	}

	next = token + strcspn(token, delim);

	if (next != NULL)
	{
		*next = '\0';
		next++;
	}
	else
	{
		next = NULL;
	}

	return (token);
}

/*
 * our_strdup - creates a duplicate of a string
 * @str: string to be duplicated
 * @new_str: string that has been duplicated
 *
 * Return: new string that has been made
 */
char* our_strdup(const char* str)
{
	size_t len = strlen(str) + 1;
	char* new_str = malloc(len);

	if (new_str != NULL)
	{
		memcpy(new_str, str, len);
	}

	return (new_str);
}
