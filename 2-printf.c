#include "main.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * print_binary - print binary code of a number
 * @num: num to convert
 * @count: to keep count of char printed
 * Return: count of chars printed
 */
int print_binary(unsigned int num, int count)
{
	char chr, *ptr2, *ptr = (char *)malloc(sizeof(char));
	int i = 0, j;

	if (num == 0)
		return (print_char('0', count));
	if (num == 1)
		return (print_char('1', count));
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
		count = print_char(ptr[j - 1], count);
	free(ptr);
	return (count);
}

/**
 * print_octal - print octal numbers of num
 * @num: number to convert
 * @count: counter to keep record of char printed
 * Return: counter of chars printed
 */
int print_octal(unsigned int num, int count)
{
	int octnum = 0, i = 1;

	while (num != 0)
	{
		octnum += (num % 8) * i;
		num /= 8;
		i *= 10;
	}
	count = print_num(octnum, count);
	return (count);
}

/**
 * print_udecimal - print numbers
 * @num: number to print
 * @count: int val to keep counter of numbers printed
 * Return: count
 */
int print_udecimal(unsigned int num, int count)
{
	int i = 0, len;
	char last, *ptr2, *ptr = (void *)malloc(sizeof(char));

	if (num < 10)
		return (print_char(num + '0', count));
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
		count = print_char(ptr[len - 1], count);
	free(ptr);
	return (count);
}

/**
 * print_hex - print a number in hexadecimal
 * @num: number to convert
 * @identifier: to decide between uppercase and lowercase
 * @count: counter to keep record of chars printed
 * Return: count of chars printed
 */
int print_hex(unsigned int num, char identifier, int count)
{
	int i = 0, j, rem, start;
	char *ptr2, *ptr = (char *)malloc(3 * sizeof(char));

	identifier == 'x' ? (start = 97) : (start = 65);
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
		count = print_char(ptr[j - 1], count);
	return (count);
}

/**
 * print_xstring - print a string
 * @str: string to print
 * @count: to keep record of chars printed
 * Return: printed chars
 */
int print_xstring(char *str, int count)
{
	char chr;
	int i = 0, len;

	if (str == NULL || strlen(str) == 0)
		return (count);
	len = strlen(str);
	while (i < len)
	{
		chr = str[i];
		if (chr < 32 || chr > 126)
		{
			count = print_char(92, count);
			count = print_char('x', count);
			if (chr < 16)
				count = print_char('0', count);
			count = print_hex((unsigned int)chr, 'X', count);
			i++;
		}
		count = print_char(str[i], count);
		i++;
	}
	return (count);
}