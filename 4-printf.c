#include "main.h"

/**
 * iscustom - checks whether a character is custom specifier
 * @chr: character to check
 * Return: true or false
 */
bool iscustom(char chr)
{
	if (chr == '-' || chr == '0' || chr == '.')
		return (true);
	return (false);
}
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
 * print_width - prints a string with th given width
 * @next_char: widyh size
 * @iden: char identifier
 * @lst: va_lst arguments
 * Return: count of characters printed
 */
int print_width(char next_char, char iden, va_list lst)
{
	char *str;
	int count;

	str = create_width(next_char, iden, lst);
	count = print_string(str);
	free(str);
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
