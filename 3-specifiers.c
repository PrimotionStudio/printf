#include "main.h"

/**
 * mq_print_unsign - Print unsigned
 * @mq_types: Varadic arguments
 * @mq_buffer: Buffer to print
 * @mq_flags: Formatting flags
 * @mq_width: minimum characters to be printed
 * @mq_precision: precision
 * @mq_size: Size of buffer
 * Return: no of characters
 */
int mq_print_unsign(va_list mq_types,
		char mq_buffer[], int mq_flags, int mq_width, int mq_precision, int mq_size)
{
	int index = BUFF_SIZE - 2;
	unsigned long int numb = va_arg(mq_types, unsigned long int);

	numb = mq_convert_size_unsign(numb, mq_size);

	if (numb == 0)
		mq_buffer[index--] = '0';

	mq_buffer[BUFF_SIZE - 1] = '\0';

	while (numb > 0)
	{
		mq_buffer[index--] = (numb % 10) + '0';
		numb /= 10;
	}

	index++;

	return (mq_write_unsign(0, index,
				mq_buffer, mq_flags, mq_width, mq_precision, mq_size));
}

/**
 * mq_print_octal - Print octal number
 * @mq_types: variadic arg
 * @mq_buffer: Buffer to print
 * @mq_flags: Formatting flag
 * @mq_width: minimum characters to be printed
 * @mq_precision: Preciscion
 * @mq_size: Size of buffer
 * Return: no of characters
 */
int mq_print_octal(va_list mq_types, char mq_buffer[],
		int mq_flags, int mq_width, int mq_precision, int mq_size)
{
	int index = BUFF_SIZE - 2;
	unsigned long int numb = va_arg(mq_types, unsigned long int);
	unsigned long int init_numb = numb;

	UNUSED(mq_width);

	numb = mq_convert_size_unsign(numb, mq_size);

	if (numb == 0)
		mq_buffer[index--] = '0';

	mq_buffer[BUFF_SIZE - 1] = '\0';

	while (numb > 0)
	{
		mq_buffer[index--] = (numb % 8) + '0';
		numb /= 8;
	}

	if (mq_flags & F_HASH && init_numb != 0)
		mq_buffer[index--] = '0';

	index++;

	return (mq_write_unsign(0, index,
				mq_buffer, mq_flags, mq_width, mq_precision, mq_size));
}

/**
 * mq_print_hexadecimal - print hex in lowercase
 * @mq_types: varadic arguments
 * @mq_buffer: buffer to print
 * @mq_flags: formatting flags
 * @mq_width: minimum length
 * @mq_precision: precision
 * @mq_size: size of buffer
 * Return: no of characters printed
 */
int mq_print_hexadecimal(va_list mq_types, char mq_buffer[],
		int mq_flags, int mq_width, int mq_precision, int mq_size)
{
	return (mq_print_hexa(mq_types, "0123456789abcdef", mq_buffer,
				mq_flags, 'x', mq_width, mq_precision, mq_size));
}

/**
 * mq_print_hexa_upper - Print hex in uppercase
 * @mq_types: varadic arguments
 * @mq_buffer: buffer to print
 * @mq_flags: formatting flags
 * @mq_width: minimum length
 * @mq_precision: precision
 * @mq_size: size of buffer
 * Return: no of characters printed
 */
int mq_print_hexa_upper(va_list mq_types, char mq_buffer[],
		int mq_flags, int mq_width, int mq_precision, int mq_size)
{
	return (mq_print_hexa(mq_types, "0123456789ABCDEF", mq_buffer,
				mq_flags, 'X', mq_width, mq_precision, mq_size));
}

/**
 * mq_print_hexa - Prints a hex in either lower or upper.
 * @mq_types: varadic.
 * @map_to: value array.
 * @mq_buffer: buffer to print.
 * @mq_flags: format flags (int)
 * @flag_ch: format flags (char)
 * @mq_width: minimum length
 * @mq_precision: precision
 * @mq_size: buffer size
 * Return: no of characters
 */
int mq_print_hexa(va_list mq_types, char map_to[], char mq_buffer[],
		int mq_flags, char flag_ch, int mq_width, int mq_precision, int mq_size)
{
	int index = BUFF_SIZE - 2;
	unsigned long int numb = va_arg(mq_types, unsigned long int);
	unsigned long int init_numb = numb;

	UNUSED(mq_width);

	numb = mq_convert_size_unsign(numb, mq_size);

	if (numb == 0)
		mq_buffer[index--] = '0';

	mq_buffer[BUFF_SIZE - 1] = '\0';

	while (numb > 0)
	{
		mq_buffer[index--] = map_to[numb % 16];
		numb /= 16;
	}

	if (mq_flags & F_HASH && init_numb != 0)
	{
		mq_buffer[index--] = flag_ch;
		mq_buffer[index--] = '0';
	}

	index++;

	return (mq_write_unsign(0, index,
				mq_buffer, mq_flags, mq_width, mq_precision, mq_size));
}
