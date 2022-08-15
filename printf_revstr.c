#include "main.h"
#include <unistd.h>
#include <string.h>

/**
 * printf_revstr - function that print a string in reverse
 * @types: Lista of arguments
 *
 * Return: number of char printed
 */
int printf_revstr(va_list types)
{
	char *str;
	int i, len, count = 0;

	str = va_arg(types, char *);

	if (str == NULL || strlen(str) == 0)
	{
		return (0);
	}

	len = strlen(str);
	for (i = len - 1; i >= 0; i--)
	{
		count += print_char(str[i]);
	}
	return (count);
}
