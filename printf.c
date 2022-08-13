#include "main.h"
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * _printf - implementation of a stdio printf
 * @format: char format
 * Return: char(s) printed
 */
int _printf(const char *format, ...)
{
	va_list lst;
	int i, j, m, len, count = 0;
	char s_ptr[8];

	if (format == NULL || strlen(format) == 0)
		return (0);
	va_start(lst, format);
	len = strlen(format);
	for (i = 0; i < len; i++)
	{
		m = 0;
		if (format[i] == '%')
		{
			for (j = i + 1; j < i + 6; j++)
			{
				if (isformat(format[j]))
					s_ptr[m] = format[j];
				else
				{
					s_ptr[m] = '\0';
					break;
				}
				m++;
			}
			if (strlen(s_ptr) == 0)
				m = 0;
			else
			{
				count += continue_printf(s_ptr, lst);
				m++;
			}
		}
		i += m;
		count += print_char(format[i]);
	}
	va_end(lst);
	return (count);
}

/**
 * continue_printf - continues the _printf function
 * @format: formatted char
 * @lst: argument passed to the _printf
 * Return: char(s) printed
 */
int  continue_printf(char *format, va_list lst)
{
	int i, len, count = 0;
	char *str, chr;

	len = strlen(format);
	for (i = len; i > 0; i--)
	{
		chr = format[i - 1];
		if (chr == '%')
			return (print_char('%'));
		if (format[i - 1] == 'h' || format[i - 1] == 'l')
		{
			if (format[i - 1] == 'h')
				str = process_short(va_arg(lst, int), chr);
			else
				str = process_long(va_arg(lst, long int), chr);
			i -= 2;
			continue;
		}
		if (isdigit(chr) && isdigit(format[i - 2]))
		{
			str = fill_width(format[i - 2], chr, str);
			i -= 2;
			continue;
		}
		if (isdigit(chr) && !(isdigit(format[i - 2])))
			str = fill_width(32, chr, str);
		if (chr == '-')
			str = allign_left(format[i + 1], str);
		if (chr == '#')
			str = process_with_hash(format[len - 1], str);
		str = continue_process(str, chr, lst);
	}
	count += print_string(str);
	free (str);
	return (count);
}

/**
 * continue_process - continues continue_printf function
 * @ptr: string pointer (parrtially formatted string)
 * @chr: char to compare formatting option
 * @lst: arguments from _printf function
 * Return: a formatted string
 */
char *continue_process(char *ptr, char chr, va_list lst)
{
	char **str = &ptr;

	if (chr == 'd' || chr == 'i')
		*str = process_int(va_arg(lst, int));
	if (chr == 'c')
		*str = process_char(va_arg(lst, int));
	if (chr == 's')
		*str = va_arg(lst, char *);
	if (chr == 'u')
		*str = process_lnum(va_arg(lst, unsigned int));
	if (chr == 'b')
		*str = process_binary(va_arg(lst, unsigned int));
	if (chr == 'o')
		*str = process_octal(va_arg(lst, unsigned int));
	if (chr == 'x' || chr == 'X')
		*str = process_hex(va_arg(lst, unsigned int), chr);
	if (chr == 'S')
		*str = process_xstring(va_arg(lst, char *));
	if (chr == '+' || chr == ' ')
		*str = process_sign(*str, chr);
	return (*str);
}
