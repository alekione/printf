#include "main.h"

/**
 * printf_rot13 - print string to rot13
 * @args: type struct
 *
 * Return: counter.
 */
int printf_rot13(va_list args)
{
	int l, m, counter = 0;
	int n = 0;
	char *s = va_arg(args, char*);
	char alpha[] = {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	char beta[] = {"qwertyuioplkjhgfdsazxcvbnmQWERTYUIOPLKJHGFDSAZXCVBNM"};

	if (s == NULL)
		s = "(null)";
	for (l = 0; s[l]; l++)
	{
		n = 0;
		for (m = 0; alpha[m] && !n; m++)
		{
			if (s[l] == alpha[m])
			{
				print_char(beta[m]);
				counter++;
				n = 1;
			}
		}
		if (!n)
		{
			print_char(s[l]);
			counter++;
		}
	}
	return (counter);
}
