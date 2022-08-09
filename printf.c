#include "main.h"
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

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

	if (str == NULL || strlen(str) == 0)
		return (count);
	i = strlen(str);
	for (j = 0; j < i; j++)
		count += print_char(str[j]);
	return (count);
}

/**
 * print_num - print numbers
 * @num: number to print
 * Return: count
 */
int print_num(int num)
{
	int i = 0, len, count = 0;
	char last, *ptr2, *ptr = (void *)malloc(sizeof(char));

	if (num == 0)
		return (print_char('0') + count);
	if (num < 0)
		count += print_char('-');
	num = abs(num);
	while (num != 0)
	{
		last = (num % 10) + '0';
		if (i == 0)
			*(ptr) = last;
		else
		{
			ptr2 = realloc(ptr, i + 1);
			*(ptr2 + i) = last;
			ptr = ptr2;
		}
		num /= 10;
		i++;
	}

	for (len = i; len > 0; len--)
		count += print_char(ptr[len - 1]);
	free(ptr);
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
				count += print_sign(lst, next_char, format[i + 2]);
			if (next_char == '#')
				count += print_with_hash(lst, format[i + 2]);
			else
				count += continue_printf(next_char, lst);
			if (next_char == '+' || next_char == '#' || next_char == ' ')
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
 * @lst: argument list
 * Return: sum of char printed
 */
int continue_printf(char next_char, va_list lst)
{
	int count = 0;

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
		count += print_udecimal(va_arg(lst, unsigned int));
	if (next_char == 'x' || next_char == 'X')
		count += print_hex(va_arg(lst, unsigned int), next_char);
	if (next_char == 'S')
		count += print_xstring(va_arg(lst, char *));
	if (next_char == 'R')
		count += printf_rot13(lst);
	return (count);
}
