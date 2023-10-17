#include "main.h"
/**
 * mq_handle_print - Function to print the type of an argument
 * @fmt: The formatted string to be printed
 * @mq_ind: The index
 * @mq_list: The arguments
 * @mq_buffer: The buffer
 * @mq_flags: To calculate the active flags
 * @mq_width: For width
 * @mq_precision: To set precision
 * @mq_size: To set size
 * Return: Printed characters or -1
 */
int mq_handle_print(const char *fmt, int *mq_ind,
		va_list mq_list, char mq_buffer[],
		int mq_flags, int mq_width, int mq_precision, int mq_size)
{
	int iter, mq_unknown_len = 0, printed_chars = -1;
	fmt_t fmt_types[] = {
		{'c', mq_print_char}, {'s', mq_print_string}, {'%', mq_print_percent},
		{'i', mq_print_int}, {'d', mq_print_int}, {'b', mq_print_binary},
		{'u', mq_print_unsign}, {'o', mq_print_octal}, {'x', mq_print_hexadecimal},
		{'X', mq_print_hexa_upper},
		{'p', mq_print_pointer}, {'S', mq_print_non_printable},
		{'r', mq_print_reverse}, {'R', mq_print_rot13string}, {'\0', NULL}
	};
	for (iter = 0; fmt_types[iter].fmt != '\0'; iter++)
	{
		if (fmt[(*mq_ind)] == fmt_types[iter].fmt)
		{
			return (fmt_types[iter].fn(mq_list, mq_buffer,
					mq_flags, mq_width, mq_precision, mq_size));
		}
	}
	if (fmt_types[iter].fmt == '\0')
	{
		if (fmt[(*mq_ind)] == '\0')
			return (-1);
		mq_unknown_len += write(1, "%", 1);
		if (fmt[(*mq_ind) - 1] == ' ')
			mq_unknown_len += write(1, " ", 1);
		else if (mq_width)
		{
			(*mq_ind)--;
			while (fmt[(*mq_ind)] != ' ' && fmt[(*mq_ind)] != '%')
				(*mq_ind)--;
			if (fmt[(*mq_ind)] == ' ')
				(*mq_ind)--;
			return (1);
		}
		mq_unknown_len += write(1, &fmt[(*mq_ind)], 1);
		return (mq_unknown_len);
	}
	return (printed_chars);
}
