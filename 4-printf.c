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
	else if (iden == 'u')
		ptr = create_number(va_arg(lst, unsigned int));
	else if (iden == 'o')
		ptr = create_octal(va_arg(lst, unsigned int));
	else
		ptr = print_width2(iden, lst);
	len = strlen(ptr);
	if (num2 < 0)
		strjn(&ptr2, ptr);
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
	if (iden != 's')
		free(ptr);
	if (num2 < 0)
		free(ptr2);
	return (count);
}

/**
 * print_width2 - continues print_width
 * @iden: character identifier
 * @lst: va_list arguments
 * Return: string
 */
char *print_width2(char iden, va_list lst)
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

/**
 * strjn - join two pointer strings from the main
 * Works like strcat function
 * @str1: first string
 * @str2: second string
 */
void strjn(char **str1, char *str2)
{
	char *str, *ptr = *str1;
	int len1, len2 = strlen(str2);
	int i;

	if (str2 == NULL || len2 == 0)
		return;
	len1 = strlen(ptr);
	str = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	for (i = 0; i < len1; i++)
		str[i] = ptr[i];
	for (i = 0; i < len2; i++)
		str[i + len1] = str2[i];
	str[len1 + len2] = '\0';
	*str1 = str;
}
