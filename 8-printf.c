#include "main.h"

/**
 * print_with_dot - print a dot custom format type
 * @length: length for formatting
 * @iden: character identifier
 * @lst: va_list arguments
 * Return: a formatted string
 */
char *print_with_dot(char length, char iden, va_list lst)
{
	char *ptr;
	int i, len;

	ptr = create_width(length, iden, lst);
	len = strlen(ptr);
	if (len > length - '0' && iden == 's')
		ptr[length - '0'] = '\0';
	if (length == '0')
		return (ptr);
	for (i = 0; i < length - '0'; i++)
	{
		if (ptr[i] != ' ')
			break;
		ptr[i] = '0';
	}
	return (ptr);
}

/**
 * print_with_dash - print a dash custom format type
 * @length: length for formatting
 * @iden: character identifier
 * @lst: va_list arguments
 * Return: a formatted string
 */
char *print_with_dash(char length, char iden, va_list lst)
{
	char *ptr;
	int i, j, k, len;

	ptr = create_width(length, iden, lst);
	if (length == '0')
		return (ptr);
	for (i = 0; i < length - '0'; i++)
	{
		if (ptr[i] != ' ')
			break;
	}
	if (i == 0)
		return (ptr);
	len = strlen(ptr);
	for (j = i; j > 0; j--)
	{
		for (k = j; k < len; k++)
			ptr[k - 1] = ptr[k];
		ptr[k - 1] = ' ';
		len--;
	}
	return (ptr);
}

/**
 * print_with_zero - print a zero custom format type
 * @length: length for formatting
 * @iden: character identifier
 * @lst: va_list arguments
 * Return: number of printd characters
 */
int print_with_zero(char length, char iden, va_list lst)
{
	char *ptr;
	int i, j, len, count = 0;

	ptr = create_width(length, iden, lst);
	len = strlen(ptr);
	if (length == '0' || len > length - '0')
	{
		for (i = 0; i < len; i++)
			count += print_char(ptr[i]);
	}
	else
	{
		for (i = 0; i < len; i++)
		{
			if (ptr[i] != ' ')
			{
				for (j = i; j < len; j++)
					count += print_char(ptr[j]);
				break;
			}
			count += print_char('0');
		}
	}
	free(ptr);
	return (count);
}
