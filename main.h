#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

#define BUFF_SIZE 1024
#define UNUSED(x) (void)(x)

#define MINUS_FL 1
#define PLUS_FL 2
#define ZERO_FL 4
#define HASH_FL 8
#define SPACE_FL 16

#define MQ_S_LONG 2
#define MQ_S_SHORT 1

/**
 * struct fmt - The format structure
 * @mq_fmt: format
 * @mq_fn: format function
 */
struct mq_fmt
{
	char mq_fmt;
	int (*mq_fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - The format structure
 * @mq_fmt: format
 * @mq_fn_t: format function
 */
typedef struct mq_fmt mq_fmt_t;

int _printf(const char*, ...);
int mq_handle_print(const char*, int*, va_list, char[], int, int, int, int);

int mq_print_char(va_list, char[], int, int, int, int);
int mq_print_string(va_list, char[], int, int, int, int);
int mq_print_percent(va_list, char[], int, int, int, int);

int mq_print_int(va_list, char[], int, int, int, int);
int mq_print_binary(va_list, char[], int, int, int, int);
int mq_print_unsign(va_list, char[], int, int, int, int);
int mq_print_octal(va_list, char[], int, int, int, int);
int mq_print_hexadecimal(va_list, char[], int, int, int, int);
int mq_print_hexa_upper(va_list, char[], int, int, int, int);

int mq_print_hexa(va_list, char[], char[], int, char, int, int, int);

int mq_print_non_printable(va_list, char[], int, int, int, int);

int mq_print_pointer(va_list, char[], int, int, int, int);

int mq_get_flags(const char *, int *);
int mq_get_width(const char *, int *, va_list list);
int mq_get_precision(const char *, int *, va_list);
int mq_get_size(const char *, int *);

int mq_print_reverse(va_list, char [], int, int, int, int);

int mq_print_rot13string(va_list, char [], int, int, int, int);

int mq_handle_write_char(char, char [], int, int, int, int);
int mq_write_number(int, int, char[], int, int, int, int);
int mq_write_num(int, char [], int, int, int, int, char, char);
int mq_write_pointer(char [], int, int, int, int, char, char, int);

int mq_write_unsign(int, int, char [], int, int, int, int);

int mq_is_printable(char);
int mq_append_hexa_code(char, char[], int);
int mq_is_digit(char);

long int mq_convert_size_number(long int, int);
long int mq_convert_size_unsign(unsigned long int, int);

#endif

