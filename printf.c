#include "main.h"

/**
 * print_char - print a character to stdout
 * @c: character to print
 * Return: char printed
 */
int print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

/**
 * print_string - print a string to stdout
 * @str: string to print
 * Return: char printed
 */
int print_string(char *str)
{
	int j, i, count = 0;

	if (str == NULL)
		str = "(null)";
	i = strlen(str);
	for (j = 0; j < i; j++)
		count += print_char(str[j]);
	return (count);
}

/**
 * print_num - print numbers
 * @number: number to print
 * Return: count
 */
int print_num(long int number)
{
	unsigned long int num;
	int count = 0;

	if (number == 0)
		return (print_char('0'));
	if (number < 0)
	{
		count += print_char('-');
		num = number * -1;
	}
	else
		num = number;
	count += print_unsigned_int(num);
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
	int i = 0, count = 0, len;
	char next_char;

	if (format == NULL || strlen(format) == 0)
		return (count);
	va_start(lst, format);
	len = strlen(format);
	while (i < len)
	{
		if (format[i] == '%')
		{
			next_char = format[i + 1];
			if (next_char == '+' || next_char == ' ')
			{
				if (!(isiden(format[i + 2])))
				{
					count += print_sign(lst, next_char, format[i + 2]);
				}
				else
				{
				count += print_sign(lst, format[i + 2], format[i + 3]);
				i++;
				}
			}
			if (next_char == '#')
				count += print_with_hash(lst, format[i + 2]);
			else
				count += continue_printf(next_char, format[i + 2], lst);
			if (next_char == '+' || next_char == '#' || next_char == ' ' ||
					next_char == 'l' || next_char == 'h')
				i++;
			i += 2;
			continue;
		}
		count += print_char(format[i]);
		i++;
	}
	va_end(lst);
	return (count);
}

/**
 * continue_printf - continue the other _printf function
 * @next_char: conversion specifier
 * @nnext_char: char after next char
 * @lst: argument list
 * Return: sum of char printed
 */
int continue_printf(char next_char, char nnext_char, va_list lst)
{
	int count = 0;

	if (next_char == 'h')
		count += print_short(va_arg(lst, int), nnext_char);
	if (next_char == 'l' && nnext_char != 'u')
		count += print_long(va_arg(lst, long int), nnext_char);
	if (next_char == 'l' && nnext_char == 'u')
		count += print_unsigned_int(va_arg(lst, unsigned long int));
	if (next_char == 'c')
		count += print_char(va_arg(lst, int));
	if (next_char == 's')
		count += print_string(va_arg(lst, char *));
	if (next_char == '%')
		count += print_char('%');
	if (next_char == 'i' || next_char == 'd')
		count += print_num(va_arg(lst, int));
	if (next_char == 'b')
		count += print_binary(va_arg(lst, unsigned int));
	if (next_char == 'o')
		count += print_octal(va_arg(lst, unsigned int));
	if (next_char == 'u')
		count += print_num(va_arg(lst, unsigned int));
	if (next_char == 'x' || next_char == 'X')
		count += print_hex(va_arg(lst, unsigned int), next_char);
	if (next_char == 'S')
		count += print_xstring(va_arg(lst, char *));
	if (next_char == 'R')
		count += printf_rot13(lst);
	if (next_char == 'r')
		count += printf_revstr(lst);
	if (next_char == 'p')
		count += print_address(va_arg(lst, void *));
	return (count);
}
