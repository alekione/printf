#include "main.h"

/**
 * print_unsigned_int - print numbers
 * @num: number to print
 * Return: count
 */
int print_unsigned_int(unsigned long int num)
{
	int i = 0, len, count = 0;
	char last, *ptr2, *ptr = (void *)malloc(sizeof(char));

	if (num == 0)
		return (print_char('0'));
	while (num != 0)
	{
		last = (num % 10) + '0';
		if (i == 0)
			*(ptr) = last;
		else
		{
			ptr2 = realloc(ptr, i + 1);
			*(ptr2 + i) = last;
			ptr = ptr2;
		}
		num /= 10;
		i++;
	}

	for (len = i; len > 0; len--)
		count += print_char(ptr[len - 1]);
	free(ptr);
	return (count);
}
