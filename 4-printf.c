#include "main.h"

/**
 * print_unsigned_int - print numbers
 * @num: number to print
 * Return: count
 */
int print_unsigned_int(unsigned long int num)
{
	int count;
	char *ptr;

	if (num == 0)
		return (print_char('0'));
	ptr = create_number(num);
	count = print_string(ptr);
	free(ptr);
	return (count);
}

/**
 * print_width - prints a string with a given width
 * @next_char: width size
 * @iden: char identifier
 * @lst: va_list arguments
 * Return: number of characters printed
 */
int print_width(char next_char, char iden, va_list lst)
{
	char *ptr, *ptr2 = "-";
	int i, num, num2, len, fill, count = 0;

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
	if (iden == 'u')
		ptr = create_number(va_arg(lst, unsigned int));
	if (iden == 'o')
		ptr = create_octal(va_arg(lst, unsigned int));
	if (iden == 'x')
		ptr = create_hex(va_arg(lst, unsigned int), 'a');
	if (iden == 'X')
		ptr = create_hex(va_arg(lst, unsigned int), 'A');
	len = strlen(ptr);
	if (num2 < 0)
		strcat(ptr2, ptr);
	else
		ptr2 = ptr;
	if (len > fill)
		count = print_string(ptr2);
	else
	{
		for (i = 0; i < fill - len; i++)
			count += print_char(' ');
		count += print_string(ptr2);
	}
	free(ptr);
	return (count);
}

/**
 * print_num - print numbers
 * @number: number to print
 * Return: count
 */
int print_num(long int number)
{
	unsigned long int num;
	int count = 0;

	if (number == 0)
		return (print_char('0'));
	if (number < 0)
	{
		count += print_char('-');
		num = number * -1;
	}
	else
		num = number;
	count += print_unsigned_int(num);
	return (count);
}
