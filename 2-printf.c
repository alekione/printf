#include "main.h"
#include <string.h>
#include <stdlib.h>
#include <limits.h>
/**
 * print_long - print a modified long int
 * @num: number to modify
 * @char: next char
 * Return: number of printed char
 */
int print_long(long int num, char chr)
{
	if (chr == 'd' || chr == 'i' || chr == 'u')
		return (print_num(num));
	if (chr == 'o')
		return (print_octal(num));
	if (chr == 'x' || chr == 'X')
		return (print_hex(num, chr));
	print_char('%');
	print_char('l');
	print_char(chr);
	return (0);
}

/**
 * print_binary - print binary code of a number
 * @num: num to convert
 * Return: count of chars printed
 */
int print_binary(unsigned int num)
{
	char chr, *ptr2, *ptr = (char *)malloc(sizeof(char));
	int i = 0, j, count = 0;

	if (num == 0)
		return (print_char('0') + count);
	if (num == 1)
		return (print_char('1') + count);
	while (num > 0)
	{
		chr = (num % 2) + '0';
		if (i == 0)
			*(ptr) = chr;
		else
		{
			ptr2 = (char *)realloc(ptr, i + 1);
			*(ptr2 + i) = chr;
			ptr = ptr2;
		}
		num /= 2;
		i++;
	}
	for (j = i; j > 0; j--)
		count += print_char(ptr[j - 1]);
	free(ptr);
	return (count);
}

/**
 * print_octal - print octal numbers of num
 * @num: number to convert
 * Return: counter of chars printed
 */
int print_octal(unsigned int num)
{
	int rem, count = 0, i = 0, j;
	char *ptr2, *ptr = (char *)malloc(sizeof(char));

	if (num == 0)
		count += print_char('0');
	while (num != 0)
	{
		rem = num % 8;
		if (i == 0)
			*(ptr) = rem + '0';
		else
		{
			ptr2 = (char *)realloc(ptr, i + 1);
			*(ptr2 + i) = rem + '0';
			ptr = ptr2;
		}
		i++;
		num /= 8;
	}
	for (j = i; j > 0; j--)
		count += print_char(ptr[j - 1]);
	return (count);
}

/**
 * print_hex - print a number in hexadecimal
 * @num: number to convert
 * @identifier: to decide between uppercase and lowercase
 * Return: count of chars printed
 */
int print_hex(unsigned int num, char identifier)
{
	int i = 0, j, rem, start, count = 0;
	char *ptr2, *ptr = (char *)malloc(3 * sizeof(char));

	identifier == 'x' ? (start = 97) : (start = 65);
	if (num == 0)
		count += print_char('0');
	while (num != 0)
	{
		rem = num % 16;
		if (rem < 10)
		{
			if (i == 0)
				*(ptr + i) = rem + '0';
			else
			{
				ptr2 = (char *)realloc(ptr, i + 1);
				*(ptr2 + i) = rem + '0';
				ptr = ptr2;
			}
		}
		else
		{
			if (i == 0)
				*(ptr + i) = (rem - 10) + start;
			else
			{
				ptr2 = (char *)realloc(ptr, i + 1);
				*(ptr2 + i) = (rem - 10) + start;
				ptr = ptr2;
			}
		}
		i++;
		num /= 16;
	}
	for (j = i; j > 0; j--)
		count += print_char(ptr[j - 1]);
	return (count);
}

/**
 * print_xstring - print a string
 * @str: string to print
 * Return: printed chars
 */
int print_xstring(char *str)
{
	char chr;
	int i = 0, len, count = 0;

	if (str == NULL || strlen(str) == 0)
		return (count);
	len = strlen(str);
	while (i < len)
	{
		chr = str[i];
		if (chr < 32 || chr > 126)
		{
			count += print_char(92);
			count += print_char('x');
			if (chr < 16)
				count += print_char('0');
			count += print_hex((unsigned int)chr, 'X');
			i++;
		}
		count += print_char(str[i]);
		i++;
	}
	return (count);
}
