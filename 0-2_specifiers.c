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

/**
 * mq_print_int - print decimal
 * @mq_types: varadic argument
 * @mq_buffer: buffer to print
 * @mq_flags: flags
 * @mq_width: field width
 * @mq_precision: For Precision settings
 * @mq_size: to set size
 * Return: The number of printed characters
 */
int mq_print_int(va_list mq_types, char mq_buffer[],
		int mq_flags, int mq_width, int mq_precision, int mq_size)
{
	int mq_i = BUFF_SIZE - 2;
	int mq_is_negative = 0;
	long int mq_n = va_arg(mq_types, long int);
	unsigned long int mq_num;

	mq_n = mq_convert_size_number(mq_n, mq_size);

	if (mq_n == 0)
	{
		mq_buffer[mq_i--] = '0';
	}

	mq_buffer[BUFF_SIZE - 1] = '\0';
	mq_num = (unsigned long int)mq_n;

	if (mq_n < 0)
	{
		mq_num = (unsigned long int)((-1) * mq_n);
		mq_is_negative = 1;
	}

	while (mq_num > 0)
	{
		mq_buffer[mq_i--] = (mq_num % 10) + '0';
		mq_num /= 10;
	}

	mq_i++;

	return (mq_write_number(mq_is_negative,
				mq_i, mq_buffer, mq_flags, mq_width, mq_precision, mq_size));
}

/**
 * mq_print_binary - to print binary
 * @mq_types: varadic arguments
 * @mq_buffer: buffer to print
 * @mq_flags: flags
 * @mq_width: field width
 * @mq_precision: for precision settings
 * @mq_size: to set size
 * Return: The number of printed characters
 */
int mq_print_binary(va_list mq_types, char mq_buffer[],
		int mq_flags, int mq_width, int mq_precision, int mq_size)
{
	unsigned int mq_n, mq_m, mq_i, mq_sum;
	unsigned int mq_a[32];
	int mq_count;
	char mq_z;

	UNUSED(mq_buffer);
	UNUSED(mq_flags);
	UNUSED(mq_width);
	UNUSED(mq_precision);
	UNUSED(mq_size);

	mq_n = va_arg(mq_types, unsigned int);
	mq_m = 2147483648;
	mq_a[0] = mq_n / mq_m;
	for (mq_i = 1; mq_i < 32; mq_i++)
	{
		mq_m /= 2;
		mq_a[mq_i] = (mq_n / mq_m) % 2;
	}
	for (mq_i = 0, mq_sum = 0, mq_count = 0; mq_i < 32; mq_i++)
	{
		mq_sum += mq_a[mq_i];
		if (mq_sum || mq_i == 31)
		{
			mq_z = '0' + mq_a[mq_i];

			write(1, &mq_z, 1);
			mq_count++;
		}
	}
	return (mq_count);
}
