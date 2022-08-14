#include "main.h"
#include <stdarg.h>
#include <limits.h>
#include <stdlib.h>
**

/**
 * print_sign - adds a positive sign to numbers
 * @lst: va_list arguments
 * @next_char: char to determine the type of numunber
 * @sign: leading sign conversion
 * Return: char(s) printed upto this point
 */
int print_sign(va_list lst, char sign, char next_char)
{
	int num, count = 0;

	if (next_char == 'd' || next_char == 'i')
	{
		num = va_arg(lst, int);
		if (num > 0)
			count += print_char(sign);
		count += print_num(num);
	}
	if (next_char == 'u')
	{
		count += print_char(sign);
		count += print_num(va_arg(lst, unsigned int));
	}
	return (count);
}

/**
 * print_with_hash - print a more preformatted text
 * @lst: va_list argument
 * @next_char: char after #
 * Return: counter to char printed
 */
int print_with_hash(va_list lst, char next_char)
{
	unsigned int num = va_arg(lst, unsigned int);
	int count = 0;

	if (num == 0)
		return(print_char('0'));
	if (next_char == 'o')
	{
		count += print_char('0');
		count += print_octal(num);
	}
	if (next_char == 'x' || next_char == 'X')
	{
		count += print_char('0');
		next_char == 'x' ? (print_char('x')) : (print_char('X'));
		count++;
		count += print_hex(num, next_char);
	}
	return (count);
}

/**
 * print_short - print short int
 * @num: num to print
 * Return: counter to char printed
 */
int print_short(int num, char chr)
{
	if (chr == 'd' || chr == 'i' || chr == 'u')
		return (print_num(num));
	if (chr == 'o')
		return (print_octal(num));
	if (chr == 'x' || chr == 'X')
		return(print_hex(num, chr));
	print_char('%');
	print_char('h');
	print_char(chr);
	return (3);
}