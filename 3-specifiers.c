#include "main.h"

/**
 * mq_print_unsign - Function to print unsigned
 * @mq_types: The variadic arguments
 * @mq_buf: The buffer to print from
 * @mq_flag: Formatting flags
 * @mq_width: minimum characters to be printed
 * @mq_prec: precision
 * @mq_size: Size of buffer
 *
 * Return: no of characters
 */
int mq_print_unsign(va_list mq_types, char mq_buf[],
		int mq_flag, int mq_width, int mq_prec, int mq_size)
{
	int index = BUFF_SIZE - 2;
	unsigned long int numb = va_arg(mq_types, unsigned long int);

	numb = mq_convert_size_unsign(numb, mq_size);

	if (numb == 0)
		mq_buf[index--] = '0';

	mq_buf[BUFF_SIZE - 1] = '\0';

	while (numb > 0)
	{
		mq_buf[index--] = (numb % 10) + '0';
		numb /= 10;
	}

	index++;

	return (mq_write_unsign(0, index,
				mq_buf, mq_flag, mq_width, mq_prec, mq_size));
}

/**
 * mq_print_octal - Function to print octal number
 * @mq_types: The variadic arguments
 * @mq_buf: The buffer to print from
 * @mq_flag: Formatting flag
 * @mq_width: The minimum characters to be printed
 * @mq_prec: To set preciscion
 * @mq_size: Size of buffer
 *
 * Return: The number of characters
 */
int mq_print_octal(va_list mq_types, char mq_buf[],
		int mq_flag, int mq_width, int mq_prec, int mq_size)
{
	int index = BUFF_SIZE - 2;
	unsigned long int mq_numb = va_arg(mq_types, unsigned long int);
	unsigned long int unint_numb = mq_numb;

	UNUSED(mq_width);

	mq_numb = mq_convert_size_unsign(mq_numb, mq_size);

	if (mq_numb == 0)
		mq_buf[index--] = '0';

	mq_buf[BUFF_SIZE - 1] = '\0';

	while (mq_numb > 0)
	{
		mq_buf[index--] = (mq_numb % 8) + '0';
		mq_numb /= 8;
	}

	if (mq_flag & HASH_FL && unint_numb != 0)
		mq_buf[index--] = '0';

	index++;

	return (mq_write_unsign(0, index, mq_buf,
				mq_flag, mq_width, mq_prec, mq_size));
}

/**
 * mq_print_hexadecimal - Function to print hex in lowercase
 * @mq_types: The variadic arguments
 * @mq_buf: The buffer to print from
 * @mq_flag: formatting flags
 * @mq_width: The minimum length
 * @mq_prec: To set precision
 * @mq_size: The size of buffer
 *
 * Return: The number of printed characters
 */
int mq_print_hexadecimal(va_list mq_types, char mq_buf[],
		int mq_flag, int mq_width, int mq_prec, int mq_size)
{
	return (mq_print_hexa(mq_types, "0123456789abcdef", mq_buf,
				mq_flag, 'x', mq_width, mq_prec, mq_size));
}

/**
 * mq_print_hexa_upper - Function to print hex in uppercase
 * @mq_types: The variadic arguments
 * @mq_buf: The buffer to print from
 * @mq_flag: formatting flags
 * @mq_width: The minimum length
 * @mq_prec: To set precision
 * @mq_size: The size of buffer
 *
 * Return: The number of printed characters
 */
int mq_print_hexa_upper(va_list mq_types, char mq_buf[],
		int mq_flag, int mq_width, int mq_prec, int mq_size)
{
	return (mq_print_hexa(mq_types, "0123456789ABCDEF", mq_buf,
				mq_flag, 'X', mq_width, mq_prec, mq_size));
}

/**
 * mq_print_hexa - Function to print a hex in either lowercase or uppercase
 * @mq_types: The varadic arguments
 * @mq_map_to: The value array
 * @mq_buf: The buffer to print from
 * @mq_flag: The format flags (int)
 * @mq_flag_ch: The format flags (char)
 * @mq_width: The minimum length
 * @mq_prec: To set precision
 * @mq_size: The buffer size
 *
 * Return: The number of characters
 */
int mq_print_hexa(va_list mq_types, char mq_map_to[], char mq_buf[],
		int mq_flag, char mq_flag_ch, int mq_width, int mq_prec, int mq_size)
{
	int index = BUFF_SIZE - 2;
	unsigned long int mq_numb = va_arg(mq_types, unsigned long int);
	unsigned long int unint_numb = mq_numb;

	UNUSED(mq_width);

	mq_numb = mq_convert_size_unsign(mq_numb, mq_size);

	if (mq_numb == 0)
		mq_buf[index--] = '0';

	mq_buf[BUFF_SIZE - 1] = '\0';

	while (mq_numb > 0)
	{
		mq_buf[index--] = mq_map_to[mq_numb % 16];
		mq_numb /= 16;
	}

	if (mq_flag & HASH_FL && unint_numb != 0)
	{
		mq_buf[index--] = mq_flag_ch;
		mq_buf[index--] = '0';
	}

	index++;

	return (mq_write_unsign(0, index,
				mq_buf, mq_flag, mq_width, mq_prec, mq_size));
}
