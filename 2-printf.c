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
