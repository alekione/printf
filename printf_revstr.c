#include "main.h"
#include <string.h>
#include <stdlib.h>

/**
 * process_strrev - function that print a string in reverse
 * @str: string to print
 *
 * Return: reversed string
 */
char *process_strrev(char *str)
{
	char *ptr;
	int i, len, m = 0;

	if (str == NULL || strlen(str) == 0)
	{
		return (str);
	}

	len = strlen(str);
	ptr = (char *)malloc((len + 1) * sizeof(char));
	m = 0;
	for (i = len - 1; i >= 0; i--)
	{
		*(ptr + m) = str[i];
		m++;
	}
	*(ptr + m) = '\0';
	return (ptr);
}
