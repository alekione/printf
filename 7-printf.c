#include "main.h"

/**
 * printf_rot13 - print string to rot13
 * @args: type struct
 *
 * Return: counter.
 */
int print_rot13(va_list args)
{
	int l, m, n, count = 0, slen, alen;

	char *s = va_arg(args, char *);

	char alpha[] = {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	char beta[] = {"nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM"};

	if (s == NULL)
		return (count);
	slen = strlen(s);
	alen = strlen(alpha);
	for (l = 0; l < slen; l++)
	{
		n = 0;
		for (m = 0; m < alen; m++)
		{
			if (s[l] == alpha[m])
			{
				count += print_char(beta[m]);
				n = 1;
			}
		}
		if (n == 0)
			count += print_char(s[l]);
	}
	return (count);
}

/**
 * printf_revstr - function that print a string in reverse
 * @types: Lista of arguments
 *
 * Return: number of char printed
 */
int print_revstr(va_list types)
{
	char *str;
	int i, len, count = 0;

	str = va_arg(types, char *);

	if (str == NULL || strlen(str) == 0)
	{
		return (0);
	}

	len = strlen(str);
	for (i = len - 1; i >= 0; i--)
	{
		count += print_char(str[i]);
	}
	return (count);
}