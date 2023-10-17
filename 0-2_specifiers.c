#include "main.h"

/**
 * mq_print_char - Function to print a character
 * @mq_types: The list of arguments for the function
 * @mq_flag: Variable to calculate active flags
 * @mq_buf: The buffer array that will handle character print
 * @mq_width: The field width
 * @mq_size: The specifier of size
 * @mq_prec: For precision setting
 *
 * Return: Number of printed characters
 */
int mq_print_char(va_list mq_types, char mq_buf[],
		int mq_flag, int mq_width, int mq_prec, int mq_size)
{
	char c = va_arg(mq_types, int);

	return (mq_handle_write_char(c, mq_buf, mq_flag, mq_width, mq_prec, mq_size));
}

/**
 * mq_print_string - Function to print a string
 * @mq_types: Arguments passed to the function
 * @mq_buf: The buffer array to print the string
 * @mq_flag: Variable to calculate the active flags.
 * @mq_width: The width of the field
 * @mq_prec: For precision settings
 * @mq_size: The specifier of size
 *
 * Return: The number of printed string
 */
int mq_print_string(va_list mq_types, char mq_buf[],
		int mq_flag, int mq_width, int mq_prec, int mq_size)
{
	int mq_len = 0, index;
	char *string = va_arg(mq_types, char *);

	UNUSED(mq_buf);
	UNUSED(mq_flag);
	UNUSED(mq_width);
	UNUSED(mq_prec);
	UNUSED(mq_size);
	if (string == NULL)
	{
		string = "(null)";
		if (mq_prec >= 6)
			string = " ";
	}

	while (string[mq_len] != '\0')
		mq_len++;

	if (mq_prec >= 0 && mq_prec < mq_len)
		mq_len = mq_prec;

	if (mq_width > mq_len)
	{
		if (mq_flag & MINUS_FL)
		{
			write(1, &string[0], mq_len);
			for (index = mq_width - mq_len; index > 0; index--)
				write(1, " ", 1);
			return (mq_width);
		}
		else
		{
			for (index = mq_width - mq_len; index > 0; index--)
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
 * @mq_buf: The buffer array for printing the percentage sign
 * @mq_flag: To calculate the flags that are active
 * @mq_width: The field width
 * @mq_prec: For precision settings
 * @mq_size: To set size
 *
 * Return: The number of printed characters
 */
int mq_print_percent(va_list mq_types, char mq_buf[],
		int mq_flag, int mq_width, int mq_prec, int mq_size)
{
	UNUSED(mq_types);
	UNUSED(mq_buf);
	UNUSED(mq_flag);
	UNUSED(mq_width);
	UNUSED(mq_prec);
	UNUSED(mq_size);
	return (write(1, "%%", 1));
}

/**
 * mq_print_int - Function for printing integer
 * @mq_types: The variadic argument
 * @mq_buf: The buffer to print integers from
 * @mq_flag: To know the active flags
 * @mq_width: The field width
 * @mq_prec: For Precision settings
 * @mq_size: To set size
 * Return: The number of printed characters
 */
int mq_print_int(va_list mq_types, char mq_buf[],
		int mq_flag, int mq_width, int mq_prec, int mq_size)
{
	int mq_is_neg = 0;
	int mq_i = BUFF_SIZE - 2;
	unsigned long int mq_num;
	long int mq_n = va_arg(mq_types, long int);

	mq_n = mq_convert_size_number(mq_n, mq_size);

	if (mq_n == 0)
	{
		mq_buf[mq_i--] = '0';
	}

	mq_buf[BUFF_SIZE - 1] = '\0';
	mq_num = (unsigned long int)mq_n;

	if (mq_n < 0)
	{
		mq_num = (unsigned long int)((-1) * mq_n);
		mq_is_neg = 1;
	}

	while (mq_num > 0)
	{
		mq_buf[mq_i--] = (mq_num % 10) + '0';
		mq_num /= 10;
	}

	mq_i++;

	return (mq_write_number(mq_is_neg, mq_i, mq_buf, mq_flag,
				mq_width, mq_prec, mq_size));
}

/**
 * mq_print_binary - Function to print binary number
 * @mq_types: The variadic arguments
 * @mq_buf: The buffer to print from
 * @mq_flag: To know active flags
 * @mq_width: The field width
 * @mq_prec: For precision settings
 * @mq_size: To set size
 *
 * Return: The number of printed numbers
 */
int mq_print_binary(va_list mq_types, char mq_buf[],
		int mq_flag, int mq_width, int mq_prec, int mq_size)
{
	unsigned int mq_n, mq_m, mq_i, mq_sum;
	int mq_count;
	unsigned int mq_a[32];

	UNUSED(mq_buf);
	UNUSED(mq_flag);
	UNUSED(mq_width);
	UNUSED(mq_prec);
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
			char mq_z = '0' + mq_a[mq_i];

			write(1, &mq_z, 1);
			mq_count++;
		}
	}
	return (mq_count);
}
