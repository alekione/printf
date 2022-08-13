#include <string.h>
#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * process_long - print a modified long int
 * @num: number to modify
 * @chr: next char
 * Return: number of printed char
 */
char *process_long(long int num, char chr)
{
	char *str;

	if (chr == 'd' || chr == 'i' || chr == 'u')
	{
		if (num < 0)
		{
			str = process_char('-');
			num *= -1;
			return (strcat(str, process_lnum(num)));
		}
		return (process_lnum(num));
	}
	if (chr == 'o')
		return (process_octal(num));
	if (chr == 'x' || chr == 'X')
		return (process_hex(num, chr));
	str = (char *)malloc(4 * sizeof(char));
	*(str) = '%';
	*(str + 1) = 'l';
	*(str + 2) = chr;
	*(str + 3) = '\0';
	return (0);
}

/**
 * process_lnum - for long numbers
 * @num: number to print
 * Return: string number
 */
char *process_lnum(long int num)
{
	int i = 0, len, m;
	char last, *ptr3, *ptr2, *ptr = (void *)malloc(sizeof(char));

	if (num == 0)
		return (process_char('0'));
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
	ptr3 = (char *)malloc((i + 1) * sizeof(char));
	m = 0;
	for (len = i; len > 0; len--)
	{
		*(ptr3 + m) = ptr[len - 1];
		m++;
	}
	*(ptr3 + m) = '\0';
	free(ptr);
	return (ptr3);
}

/**
 * process_short -  short int
 * @num: num to print
 * @chr: format char
 * Return: string num
 */
char *process_short(int num, char chr)
{
	char *str;

	if (chr == 'd' || chr == 'i' || chr == 'u')
	{
		if (num < 0)
		{
			str = process_char('-');
			num *= -1;
			return (strcat(str, process_lnum(num)));
		}
		return (process_lnum(num));
	}
	if (chr == 'o')
		return (process_octal(num));
	if (chr == 'x' || chr == 'X')
		return (process_hex(num, chr));
	str = (char *)malloc(4 * sizeof(char));
	*(str) = '%';
	*(str + 1) = 'h';
	*(str + 2) = chr;
	*(str + 3) = '\0';
	return (str);
}
