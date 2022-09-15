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

/**
 * print_custom - prints a string with custom modifiers
 * @next_char: custom modifier
 * @nnext_char: length modifier/ specifier
 * @n_nnext_char:  specifier or none
 * @lst: va_list arguments
 * Return: count of printed characters
 */
int print_custom(char next_char, char nnext_char, char n_nnext_char,
		va_list lst)
{
	char *ptr = NULL, iden, length;
	int count;

	if (nnext_char != '*' && !(isdigit(nnext_char)))
	{
		iden = nnext_char;
		length = '0';
	}
	else
	{
		length = nnext_char;
		iden = n_nnext_char;
	}
	if (next_char == '.')
		ptr = print_with_dot(length, iden, lst);
	if (next_char == '-')
		ptr = print_with_dash(length, iden, lst);
	if (next_char == '0')
		ptr = print_with_zero(length, iden, lst);
	count = print_string(ptr);
	free(ptr);
	return (count);
}
