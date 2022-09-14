#include "main.h"

/**
 * _strdup - duplicates a given string
 * @str: string to duplicate
 * Return: a new string
 */
char *_strdup(char *str)
{
	int len, i;
	char *ptr;

	len = strlen(str);
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (ptr == NULL)
	{
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < len; i++)
		ptr[i] = str[i];
	ptr[len] = '\0';
	return (ptr);
}

/**
 * create_binary - convert a number int  a string binary
 * @num: number ro convert
 * Return: a string binary
 */
char *create_binary(unsigned int num)
{
	char chr, ptr2[65], ptr[65];
	int i = 0, j = 0, ind = 0;

	if (num == 0)
	{
		ptr[0] = '0';
		ptr[1] = '\0';
		return (_strdup(ptr));
	}
	while (num > 0)
	{
		chr = (num % 2) + '0';
		ptr[i] = chr;
		num /= 2;
		i++;
	}
	ptr[i] = '\0';
	for (j = i; j > 0; j--, ind++)
		ptr2[ind] = ptr[j - 1];
	ptr2[ind] = '\0';
	return (_strdup(ptr2));
}

/**
 * create_octal - converts a number into a string octal
 * @num: number to convert
 * Return: string octal
 */
char *create_octal(unsigned int num)
{
	int i = 0, j, ind = 0, rem;
	char ptr2[70], ptr[70];

	if (num == 0)
	{
		ptr[0] = '0';
		ptr[1] = '\0';
		return (_strdup(ptr));
	}
	while (num != 0)
	{
		rem = num % 8;
		ptr[i] = rem + '0';
		num /= 8;
		i++;
	}
	ptr[i] = '\0';
	for (j = i; j > 0; j--, ind++)
		ptr2[ind] = ptr[j - 1];
	ptr2[ind] = '\0';
	return (_strdup(ptr2));
}

/**
 * create_number - converts a number into a string
 * @num: number to convert
 * Return: a string number
 */
char *create_number(unsigned long int num)
{
	int i = 0, j, ind = 0;
	char last, ptr2[30], ptr[30];

	if (num == 0)
	{
		ptr[0] = '0';
		ptr[1] = '\0';
		return (_strdup(ptr));
	}
	while (num != 0)
	{
		last = (num % 10) + '0';
		ptr[i] = last;
		num /= 10;
		i++;
	}
	ptr[i] = '\0';
	for (j = i; j > 0; j--, ind++)
		ptr2[ind] = ptr[j - 1];
	ptr2[ind] = '\0';
	return (_strdup(ptr2));
}

/**
 * create_hex - converts a number into a string hexadecimal
 * @num: number to convert
 * @start: starting point of hexadecimal
 * Return: a string hexadecial number
 */
char *create_hex(unsigned int num, int start)
{
	int i = 0, j, rem, ind;
	char ptr2[65], ptr[65];

	if (num == 0)
	{
		ptr[0] = '0';
		ptr[1] = '\0';
		return (_strdup(ptr));
	}
	while (num != 0)
	{
		rem = num % 16;
		if (rem < 10)
			ptr[i] = rem + '0';
		else
		ptr[i] = (rem - 10) + start;
		i++;
		num /= 16;
	}
	ptr[i] = '\0';
	for (j = i; j > 0; j--, ind++)
		ptr2[ind] = ptr[j - 1];
	ptr2[i] = '\0';
	return (_strdup(ptr2));
}
