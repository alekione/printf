#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
int continue_printf(char, va_list, int);
int print_char(char, int);
int print_string(char *, int);
int print_num(int, int);
int print_binary(unsigned int, int);
int print_octal(unsigned int, int);
int print_udecimal(unsigned int, int);
int print_hex(unsigned int, char, int);
int print_xstring(char *, int);
int printf_rot13(va_list, int);

#endif
