#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
int _printf(const char *format, ...);
int continue_printf(char, va_list, int);
int print_char(char, int);
int print_string(char *, int);
int print_num(int, int);
int print_binary(unsigned int, int count);
#endif
