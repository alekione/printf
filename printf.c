#include "main.h"
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

/**
 * print_char - print a character to stdout
 * @c: character to print
 * @count: int to keep counter of char printed
 * Return: char printed
 */
int print_char(char c, int count)
{
	write(1, &c, 1);
	return (count + 1);
}

/**
 * print_string - print a string to stdout
 * @str: string to print
 * @count: to keep counter of char printed
 * Return: char printed
 */
int print_string(char *str, int count)
{
	int j, i;

	if (str == NULL || strlen(str) == 0)
		return (count);
	i = strlen(str);
	for (j = 0; j < i; j++)
		count = print_char(str[j], count);
	return (count);
}

/**
 * _printf - print args to stdout
 * @format: arg specifiers
 * Return: char printed
 */
int _printf(const char *format, ...)
{
	va_list lst;
	int i = 0, count = 0;
	char next_char;

	va_start(lst, format);
	if (strlen(format) == 0 || format == NULL)
		return (count);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			next_char = format[i + 1];
			if (next_char == 'c')
				count = print_char(va_arg(lst, int), count);
			if (next_char == 's')
				count = print_string(va_arg(lst, char *), count);
			if (next_char == '%')
				count = print_char('%', count);
			i += 2;
			continue;
		}
		count = print_char(format[i], count);
		i++;
	}
	va_end(lst);
	return (count);
}
