#include "main.h"
#include <string.h>
**
/**
 * printf_rot13 - print string to rot13
 * @args: type struct
 *
 * Return: counter.
 */
int printf_rot13(va_list args)
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
