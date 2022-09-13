#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stddef.h>

/* ========= printf.c ============ */

int print_char(char);
int print_string(char *);
int print_num(long int);
int _printf(const char *format, ...);
int continue_printf(char, va_list);

/* ========= 2-printf.c ========= */

int print_long(long int, char);
int print_binary(unsigned int);
int print_octal(unsigned int);
int print_hex(unsigned int, char);
int print_xstring(char *);

/* ======== 3-printf.c ========= */

int print_sign(va_list, char, char);
int print_with_hash(va_list, char);
int print_short(int, char);

/* ======= printf_revstr.c ======= */

int printf_revstr(va_list types);

/* ======= printf_rot12.c ====== */

int printf_rot13(va_list);

#endif
