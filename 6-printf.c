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
