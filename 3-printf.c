#include "main.h"
#include <stdarg.h>

/**
 * print_positive - adds a positive sign to numbers
 * @lst: va_list arguments
 * @next_char: char to determine the type of numunber
 * Return: char(s) printed upto this point
 */
int print_positive(va_list lst, char next_char)
{
	int num, count = 0;

	if (next_char == 'd' || next_char == 'i')
	{
		num = va_arg(lst, int);
		if (num > 0)
			count += print_char('+');
		count += print_num(num);
	}
	if (next_char == 'u')
	{
		count += print_char('+');
		count += print_udecimal(va_arg(lst, unsigned int));
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
		count+= print_hex(num, next_char);
	}
	return (count);
}
