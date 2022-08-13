#include <string.h>
#include "main.h"
#include <stdbool.h>
#include <stdlib.h>

/**
 * process_int - for processing all intergers
 * @num: int val to process
 * Return: string int
 */
char *process_int(int num)
{
	char *str;

	if (num < 0)
	{
		str = process_char('-');
		num *= -1;
		return (strcat(str, process_lnum(num)));
	}
	return (process_lnum(num));
}

/**
 * isformat - chaecks whether a char is a format
 * @chr: char to check
 * Return: true or false
 */
bool isformat(char chr)
{
	char *ptr, *str = "csdieE fouxXp%hlLrR*+-#0123456789";

	ptr = strchr(str, chr);
	if (ptr != NULL)
		return (true);
	return (false);
}

/**
 * process_with_hash - print a more preformatted text
 * @chr: char to determine format
 * @str: string to format
 * Return: formatted string
 */
char *process_with_hash(char chr, char *str)
{
	char *ptr;

	if (chr == 'o')
		ptr = process_char('0');
	else
	{
		ptr = (char *)malloc(3 * sizeof(char));
		*(ptr) = '0';
		*(ptr + 1) = chr;
		*(ptr + 2) = '\0';
	}
	return (strcat(ptr, str));
}
