#include <string.h>
#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * fill_width - fill width if str is short
 * @fill: char to fill with
 * @size: size to fill
 * @str: string to format
 * Return: a formatted string
 */
char *fill_width(char fill, char size, char *str)
{
	int i, num, len;
	char *ptr;

	num = (int)size - '0';
	len = strlen(str);
	if (len < num)
	{
		ptr = (char *)malloc((num - len) * sizeof(char));
		for (i = 0; i < num - len; i++)
			*(ptr + i) = fill;
		*(ptr + i) = '\0';
		return (strcat(ptr, str));
	}
	return (str);
}

/**
 * allign_left - allign text to the left
 * @chr: char to fill
 * @str: string to allign
 * Return: formatted string
 */
char *allign_left(char chr, char *str)
{
	int i, j, m = 0, len1, len2;
	char *ptr3, *ptr2, *ptr = "cdieEfgGosuxXp";

	ptr2 = strchr(ptr, chr);
	if (ptr2 != NULL)
		chr = ' ';
	len1 = strlen(str);
	for (i = 0; i < len1; i++)
	{
		if (str[i] != chr)
		{
			ptr2 = (char *)malloc(((len1 - i) + 1) * sizeof(char));
			for (j = i; j < len1; j++)
			{
				*(ptr2 + m) = str[j];
				m++;
			}
			*(ptr2 + m) = '\0';
			break;
		}
	}
	len2 = strlen(ptr2);
	ptr3 = (char *)realloc(ptr2, len1 + 1);
	for (i = len2; i < len1; i++)
		*(ptr3 + i) = chr;
	*(ptr3 + i) = '\0';
	free(ptr2);
	return (ptr3);
}

/**
 * process_sign - put sign infront of numbers
 * @str: num string
 * @chr: sign char
 * Return: formatted string
 */
char *process_sign(char *str, char chr)
{
	char *ptr;

	if (str[0] == '-')
		return (str);
	ptr = process_char(chr);
	return (strcat(ptr, str));
}
