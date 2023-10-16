#include "main.h"

/**
 * _printf - Function to print formatted string to the stdout
 * @format: The character string that has the formatting directives
 * Return: The number of characters printed to stdout minus null byte
 */
int _printf(const char *format, ...)
{
	int mq_count = 0;
	va_list mq;

	if (format == NULL)
		return (-1);

	va_start(mq, format);
	mq_count = print_formatted_string(format, mq);

	va_end(mq);
	return (mq_count);
}

/**
 * print_formatted_string - The Helper function to handle the main formatting
 * @format: The character string that has the formatting directives
 * @mq: The name of the va_list of arguments
 * Return: The number of characters printed to stdout minus null byte
 */
int print_formatted_string(const char *format, va_list mq)
{
	int mq_count = 0;

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			mq_count++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			else if (*format == 'c')
			{
				mq_count += print_char(va_arg(mq, int));
			}
			else if (*format == 's')
			{
				mq_count += print_string(va_arg(mq, char*));
			}
			else if (*format == '%')
			{
				write(1, format, 1);
				mq_count++;
			}
			else if (*format == 'd')
			{
				print_decimal(va_arg(mq, int));
			}
			else if (*format == 'i')
			{
				print_decimal(va_arg(mq, int));
			}
		}
		format++;
	}

	return (mq_count);
}

/**
 * print_string - The function to print a string
 * @string: The string to print
 * Return: The number of characters printed (length of the string)
 */
int print_string(char *string)
{
	int string_len;

	string_len = strlen(string);
	write(1, string, string_len);
	return (string_len);
}
