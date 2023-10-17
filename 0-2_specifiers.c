#include "main.h"

/**
 * mq_print_char - Function to print a character
 * @mq_types: The list of arguments for the function
 * @mq_buffer: The buffer array that will handle character print
 * @mq_flags: Variable to calculate active flags
 * @mq_width: The field width
 * @mq_precision: For precision setting
 * @mq_size: The specifier of size
 *
 * Return: Number of printed characters
 */
int mq_print_char(va_list mq_types, char mq_buffer[],
		int mq_flags, int mq_width, int mq_precision, int mq_size)
{
	char c = va_arg(mq_types, int);

	return (mq_handle_write_char(c, mq_buffer,
			mq_flags, mq_width, mq_precision, mq_size));
}

/**
 * mq_print_string - Function to print a string
 * @mq_types: Arguments passed to the function
 * @mq_buffer: The buffer array to print the string
 * @mq_flags: Variable to calculate the active flags.
 * @mq_width: The width of the field
 * @mq_precision: For precision settings
 * @mq_size: The specifier of size
 *
 * Return: The number of printed string
 */
int mq_print_string(va_list mq_types, char mq_buffer[],
		int mq_flags, int mq_width, int mq_precision, int mq_size)
{
	int mq_len = 0, i;
	char *string = va_arg(mq_types, char *);

	UNUSED(mq_buffer);
	UNUSED(mq_flags);
	UNUSED(mq_width);
	UNUSED(mq_precision);
	UNUSED(mq_size);
	if (string == NULL)
	{
		string = "(null)";
		if (mq_precision >= 6)
			string = " ";
	}

	while (string[mq_len] != '\0')
		mq_len++;

	if (mq_precision >= 0 && mq_precision < mq_len)
		mq_len = mq_precision;

	if (mq_width > mq_len)
	{
		if (mq_flags & F_MINUS)
		{
			write(1, &string[0], mq_len);
			for (i = mq_width - mq_len; i > 0; i--)
				write(1, " ", 1);
			return (mq_width);
		}
		else
		{
			for (i = mq_width - mq_len; i > 0; i--)
				write(1, " ", 1);
			write(1, &string[0], mq_len);
			return (mq_width);
		}
	}

	return (write(1, string, mq_len));
}

/**
 * mq_print_percent - Function to print percentage sign
 * @mq_types: Arguments passed to the function
 * @mq_buffer: The buffer array for printing the percentage sign
 * @mq_flags: To calculate the flags that are active
 * @mq_width: The field width
 * @mq_precision: For precision settings
 * @mq_size: To set size
 *
 * Return: The number of printed characters
 */
int mq_print_percent(va_list mq_types, char mq_buffer[],
		int mq_flags, int mq_width, int mq_precision, int mq_size)
{
	UNUSED(mq_types);
	UNUSED(mq_buffer);
	UNUSED(mq_flags);
	UNUSED(mq_width);
	UNUSED(mq_precision);
	UNUSED(mq_size);
	return (write(1, "%%", 1));
}
