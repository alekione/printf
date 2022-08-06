#include "main.h"
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
void print_char(char);

/**
 * print_num - print numbers to stdout
 * @num: numbers to print
 * @str: pointer to hold string numbers
 * @first: bool true only on entry
 * @counter: keep counter of str length
 */
void print_num(int num, char *str, bool first, int counter)
{
	char chr, *str2;
	size_t i;

	if (num < 0)
		print_char('-');
	num = abs(num);
	while (num != 0)
	{
		if (num < 10)
		{
			chr = num + '0';
			print_char(chr);
			if (!(first))
			{
				for (i = strlen(str); i > 0; --i)
					print_char(str[i - 1]);
			}
			break;
		}
		else
		{
			chr = (num % 10) + '0';
			if (first)
			{
				*(str + 0) = chr;
				first = false;
			}
			else
			{
				str2 = (char *)realloc(str, counter);
				if (str2 == NULL)
					return;
				*(str2 + (counter - 1)) = chr;
				str = str2;
			}
			counter++;
			num /= 10;
		}
	}
}

/**
 * print_str - print string to stdout
 * @str: string to print
 */
void print_str(char *str)
{
	int i, j;

	i = 0, j = strlen(str);
	while (i < j)
	{
		print_char(str[i]);
		i++;
	}
}

/**
 * print_char - print a character to the stdout
 * @s: character to print
 */
void print_char(char s)
{
	write(1, &s, 1);
}

/**
 * _printf - own version of printf
 * @format: string formart specifier
 * Return: o for success
 */
int _printf(const char *format, ...)
{
	size_t i = 0;
	va_list lst;
	char next_char, *char_s, *ptr, *s = "csdi%";

	if (format == NULL || strlen(format) == 0)
		return (EXIT_SUCCESS);
	va_start(lst, format);
	ptr = (char *)malloc(sizeof(char));
	while (i < strlen(format))
	{
		if (format[i] == '%')
		{
			next_char = format[i + 1];
			char_s = strchr(s, next_char);
			if (char_s != NULL)
			{
				if (next_char == 'c')
					print_char(va_arg(lst, int));
				if (next_char == 's')
					print_str(va_arg(lst, char *));
				if (next_char == 'd')
					print_num(va_arg(lst, int), ptr, true, 1);
				if (next_char == 'i')
					print_num(va_arg(lst, int), ptr, true, 1);
				if (next_char == '%')
					print_char(next_char);
				i += 2;
				continue;
			}
		}
		print_char(format[i]);
		i++;
	}
	va_end(lst);
	free(ptr);
	return (EXIT_SUCCESS);
}
