#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <stdbool.h>

int print_char(char);
int _printf(const char *, ...);
int continue_printf(char *, va_list);
int print_string(char *);
bool isformat(char);
char *process_short(int, char);
char *process_long(long int, char);
char *process_lnum(long int);
char *process_int(int);
char *fill_width(char, char, char *);
char *allign_left(char, char *);
char *process_char(char);
char *proces_binary(unsigned int);
char *process_octal(unsigned int);
char *process_hex(unsigned int, char);
char *process_sign(char *, char);
char *process_xstring(char *);
char *process_binary(unsigned int);
char *continue_process(char *, char, va_list);
char *process_with_hash(char, char *);
char *process_strrev(char *);
char *process_rot13(char *);
#endif
