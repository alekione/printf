#include "main.h"

/**
 * create_xstring - creates a preformatted string
 * @str: string to format
 * Return: a formatted string
 */
char *create_xstring(char *str)
{
	char chr, *ptr, *ptr2;
	int i = 0, j, len, ind = -1;

	len = strlen(str);
	ptr = malloc((len * 2) * sizeof(char));
	if (ptr == NULL)
		exit(EXIT_FAILURE);
	while (i < len)
	{
		chr = str[i];
		if (chr < 32 || chr > 126)
		{
			ptr[ind++] = 92;
			ptr[ind++] = 'x';
			if (chr < 16)
				ptr[ind++] = '0';
			ptr2 = create_hex((unsigned int)chr, 'A');
			for (j = 0; ptr2[j] != '\0'; j++)
				ptr[ind++] = ptr2[j];
			free(ptr2);
			i++;
			continue;
		}
		ptr[ind++] = str[i];
		i++;
	}
	ptr[ind++] = '\0';
	return (ptr);
}

/**
 * create_width - creates a string with a given width
 * @next_char: width size
 * @iden: char identifier
 * @lst: va_list arguments
 * Return: str with the given width
 */
char *create_width(char next_char, char iden, va_list lst)
{
	char *str, *ptr, *ptr2 = "-";
	int i, num, num2, len, fill;

	if (next_char == '*')
		fill = va_arg(lst, int);
	else
		fill = next_char - '0';
	if (iden == 'd' || iden == 'i')
	{
		num = num2 = va_arg(lst, int);
		if (num < 0)
			num *= -1;
		ptr = create_number(num);
	}
	else if (iden == 'u')
		ptr = create_number(va_arg(lst, unsigned int));
	else if (iden == 'o')
		ptr = create_octal(va_arg(lst, unsigned int));
	else
		ptr = create_width2(iden, lst);
	len = strlen(ptr);
	if (num2 < 0)
	{
		strjn(&ptr2, ptr);
		free(ptr);
		ptr = _strdup(ptr2);
		free(ptr2);
	}
	if (len > fill || fill == 0)
		return (ptr);
	str = malloc((fill - len + 1) * sizeof(char));
	for (i = 0; i < fill - len; i++)
		str[i] = ' ';
	str[i] = '\0';
	strjn(&str, ptr2);
	free(ptr);
	return (str);
}

/**
 * create_width2 - continues create_width
 * @iden: character identifier
 * @lst: va_list arguments
 * Return: string
 */
char *create_width2(char iden, va_list lst)
{
	char *ptr;

	if (iden == 'x')
		ptr = create_hex(va_arg(lst, unsigned int), 'a');
	if (iden == 'X')
		ptr = create_hex(va_arg(lst, unsigned int), 'A');
	if (iden == 's')
		ptr = va_arg(lst, char *);
	if (iden == 'c')
		ptr = str_char(va_arg(lst, int));
	return (ptr);
}

/**
 * str_char - converts a character into  a string
 * @chr: character passed;
 * Return: a string character
 */
char *str_char(char chr)
{
	char *ptr = malloc(2 * sizeof(char));

	ptr[0] = chr;
	ptr[1] = '\0';
	return (ptr);
}
