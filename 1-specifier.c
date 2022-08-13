#include "main.h"
#include <string.h>
#include <stdlib.h>

/**
 * process_char - create a str from a char
 * @c: char to use
 * Return: a string
 */
char *process_char(char c)
{
	char *ptr = (char *)malloc(2 * sizeof(char));

	*(ptr) = c;
	*(ptr + 1) = '\0';
	return (ptr);
}

/**
 * process_binary - create binary code of a number
 * @num: num to convert
 * Return: converted code
 */
char *process_binary(unsigned int num)
{
	char chr, *ptr3, *ptr2, *ptr = (char *)malloc(sizeof(char));
	int i = 0, j, m =0, count = 1;

	if (num == 0)
		return (process_char('0'));
	if (num == 1)
		return (process_char('1'));
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
		count++;
	}
	ptr3 = (char *)malloc(count * sizeof(char));
	for (j = i; j > 0; j--)
	{
		*(ptr3 + m) = ptr[ j - 1];
		m++;
	}
	*(ptr3 + m) = '\0';
	free(ptr);
	return (ptr3);
}

/**
 * process_octal - create octal numbers of num
 * @num: number to convert
 * Return: octal number in a string
 */
char *process_octal(unsigned int num)
{
	int rem, count = 1, i = 0, j, m = 0;
	char *ptr3, *ptr2, *ptr = (char *)malloc(sizeof(char));

	if (num == 0)
		return (process_char('0'));
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
		count++;
		num /= 8;
	}
	ptr3 = (char *)malloc(count * sizeof(char));
	for (j = i; j > 0; j--)
	{
		*(ptr3 + m) = ptr[j - 1];
		m++;
	}
	*(ptr3 + m) = '\0';
	free(ptr);
	return (ptr3);
}

/**
 * process_hex - convert a number to hexadecimal
 * @num: number to convert
 * @identifier: to decide between uppercase and lowercase
 * Return: num in string hexadecimal
 */
char *process_hex(unsigned int num, char identifier)
{
	int i = 0, j, rem, start, count = 1, m = 0;
	char *ptr3, *ptr2, *ptr = (char *)malloc(3 * sizeof(char));

	identifier == 'x' ? (start = 97) : (start = 65);
	if (num == 0)
		return (process_char('0'));
	while (num != 0)
	{
		rem = num % 16;
		if (rem < 10 && i == 0)
			*(ptr + i) = rem + '0';
		if (rem < 10 && i != 0)
		{
			ptr2 = (char *)realloc(ptr, i + 1);
			*(ptr2 + i) = rem + '0';
			ptr = ptr2;
		}
		if (rem > 10 && i == 0)
			*(ptr + i) = (rem - 10) + start;
		if (rem > 10 && i != 0)
		{
			ptr2 = (char *)realloc(ptr, i + 1);
			*(ptr2 + i) = (rem - 10) + start;
			ptr = ptr2;
		}
		count++, i++;
		num /= 16;
	}
	ptr3 = (char *)malloc(count * sizeof(char));
	for (j = i; j > 0; j--)
	{
		*(ptr3 + m)= ptr[j - 1];
		m++;
	}
	*(ptr3 + m) = '\0';
	free(ptr);
	return (ptr3);
}

/**
 * proces_xstring - process a string
 * @str: string to print
 * Return: processed str
 */
char *process_xstring(char *str)
{
	char chr, *ptr2, *ptr; 
	int i = 0, len, j = 1;

	if (str == NULL || strlen(str) == 0)
		return (str);
	ptr = (char *)malloc(sizeof(char));
	len = strlen(str);
	while (i < len)
	{
		chr = str[i];
		if (chr < 32 || chr > 126)
		{
			j++;
			ptr2 = (char *)realloc(ptr, j + 1);
			*(ptr2 + (j - 2)) = 92;
			*(ptr2 + (j - 1)) = 'x';
			ptr = ptr2;
			if (chr < 16)
			{
				j++;
				ptr2 = (char *)realloc(ptr, j + 1);
				*(ptr2 + (j - 1)) = '0';
				ptr = ptr2;
			}
			strcat(ptr, process_hex((unsigned int)chr, 'X'));
			i++;
			j += 2;
		}
		ptr2 = (char *)realloc(ptr, j + 1);
		*(ptr2 + (j - 1))= str[i];
		ptr = ptr2;
		j++;
		i++;
	}
	*(ptr + j) = '\0';
	return (ptr);
}
