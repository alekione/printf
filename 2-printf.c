#include "main.h"

/**
 * print_long - print a modified long int
 * @num: number to modify
 * @chr: next char
 * Return: number of printed char
 */
int print_long(long int num, char chr)
{
	if (chr == 'd' || chr == 'i' || chr == 'u')
		return (print_num(num));
	if (chr == 'o')
		return (print_octal(num));
	if (chr == 'x' || chr == 'X')
		return (print_hex(num, chr));
	print_char('%');
	print_char('l');
	print_char(chr);
	return (0);
}

/**
 * print_binary - print binary code of a number
 * @num: num to convert
 * Return: count of chars printed
 */
int print_binary(unsigned int num)
{
	char *ptr;
	int count = 0;

	if (num == 0)
		return (print_char('0'));
	if (num == 1)
		return (print_char('1'));
	ptr = create_binary(num);
	count += print_string(ptr);
	free(ptr);
	return (count);
}

/**
 * print_octal - print octal numbers of num
 * @num: number to convert
 * Return: counter of chars printed
 */
int print_octal(unsigned int num)
{
	int count = 0;
	char *ptr;

	if (num == 0)
		return (print_char('0'));
	ptr = create_octal(num);
	count += print_string(ptr);
	free(ptr);
	return (count);
}

/**
 * print_hex - print a number in hexadecimal
 * @num: number to convert
 * @identifier: to decide between uppercase and lowercase
 * Return: count of chars printed
 */
int print_hex(unsigned int num, char identifier)
{
	int start, count;
	char *ptr;

	identifier == 'x' ? (start = 97) : (start = 65);
	if (num == 0)
		return (print_char('0'));
	ptr = create_hex(num, start);
	count = print_string(ptr);
	free(ptr);
	return (count);
}

/**
 * print_xstring - print a string
 * @str: string to print
 * Return: printed chars
 */
int print_xstring(char *str)
{
	char *ptr;
	int count;

	if (str == NULL || strlen(str) == 0)
		return (0);
	ptr = create_xstring(str);
	count = print_string(ptr);
	free(ptr);
	return (count);
}
