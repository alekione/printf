#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
int continue_printf(char, va_list);
int print_char(char);
int print_string(char *);
int print_num(int);
int print_binary(unsigned int);
int print_octal(unsigned int);
int print_udecimal(unsigned int);
int print_hex(unsigned int, char);
int print_xstring(char *);
int print_sign(va_list, char, char);
int print_with_hash(va_list, char);
int printf_rot13(va_list);

#endif
