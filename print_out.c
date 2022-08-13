#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "main.h"

/**
 * print_char - print a given char to stdout
 * @c: char to print
 * Return: count
 */
int print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

/**
 * print_string - print a given string to stdout
 * @str: string given
 * Return: number of char(s) printed
 */
int print_string(char *str)
{
	int count = 0, len, i;

	len = strlen(str);
	for (i = 0; i < len; i++)
		count += print_char(str[i]);
	return (count);
}
