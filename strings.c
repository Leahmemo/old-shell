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
 * strcspn - checks if the current character of a string is present in another string
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
