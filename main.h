#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>

/* =========1- printf.c ============ */

int print_char(char);
int print_string(char *);
int _printf(const char *format, ...);
int continue_printf(char, char, char, va_list);
int continue_printf2(char, va_list);

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
bool isiden(char);
int print_address(void *);

/* ========= 4-printf.c =========== */

bool iscustom(char);
int print_unsigned_int(unsigned long int);
int print_width(char, char, va_list);
int print_num(long int);
void strjn(char **, char *);

/* ========== 5-printf.c =========== */

char *_strdup(char *);
char *create_binary(unsigned int);
char *create_octal(unsigned int);
char *create_number(unsigned long int);
char *create_hex(unsigned int, int);

/* ======== 6-printf.c ======= */

char *create_xstring(char *);
char *create_width(char, char, va_list);
char *create_width2(char, va_list);
char *str_char(char);

/* ======= 7-printf.c ======= */

int print_revstr(va_list types);
int print_rot13(va_list);
int print_custom(char, char, char, va_list);

/* ======= 8-printf.c ======= */

char *print_with_dot(char, char, va_list);
char *print_with_dash(char, char, va_list);
int print_with_zero(char, char, va_list);

#endif
