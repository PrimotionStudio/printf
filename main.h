#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>


int _mqputchar(char m);
int print_char(char m);
int print_string(char *string);
int print_formatted_string(const char *format, va_list mq);
int _printf(const char *format, ...);
int print_decimal(int decimal);

#endif
