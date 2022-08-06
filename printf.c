#include "main.h"
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>

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

	if (num < 10)
	{
		chr = num + '0';
		write(1, &chr, 1);
		if (!(first))
		{
			i = strlen(str); 
			while (i > 0) {i--; write(i, &str[i], 1);}
		}
	}
	else
	{
		chr = (num % 10) + '0';
		if (first)
		{
			*(str) = chr;
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
		print_num(num / 10, str, first, counter + 1);
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
		write(1, &str[i], 1);
		i++;
	}
}

/**
 * _printf - own version of printf
 * @format: string formart specifier
 * Return: o for success
 */
int _printf(const char *format, ...)
{
	size_t i = 0, j;
	va_list lst;
	char chr, next_char, *ptr;

	if (format == NULL || strlen(format) == 0) return(EXIT_SUCCESS);
	va_start(lst, format);
	ptr = (char *)malloc(sizeof(char));
	while (i < strlen(format))
	{
		j = i;
		if (format[i] == '%')
		{
			next_char = format[i + 1];
			if (next_char == 'c')
			{
				chr = va_arg(lst, int);
				write(1, &chr, 1);
				i += 2;
			}
			if (next_char == 's') {print_str(va_arg(lst, char *)); i += 2;}
			if (next_char == 'd') {print_num(va_arg(lst, int), ptr, true, 1); i += 2;}
			if (next_char == 'i') {print_num(va_arg(lst, int), ptr, true, 1); i += 2;}
			if (next_char == '%') {write(1, &next_char, 1); i+= 2;}
			if (i != j) continue;
		}
		write(1, &format[i], 1);
		i++;
	}
	va_end(lst);
	free(ptr);
	return (EXIT_SUCCESS);
}
