#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * process_rot13 - print string to rot13
 * @str: str to convert
 *
 * Return: converted string
 */
char *process_rot13(char *str)
{
	int l, m, n, slen, alen, ind;
	char *ptr, chr;

	char alpha[] = {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	char beta[] = {"nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM"};

	slen = strlen(str);
	ptr = (char *)malloc((slen + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	alen = strlen(alpha);
	ind = 0;
	for (l = 0; l < slen; l++)
	{
		n = 0;
		chr = str[l];
		for (m = 0; m < alen; m++)
		{
			if (chr == alpha[m])
			{
				*(ptr + ind) = beta[m];
				n = 1;
			}
		}
		if (n == 0)
			*(ptr + ind) = chr;
		ind++;
	}
	*(ptr + ind) = '\0';
	return (ptr);
}
