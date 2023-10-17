#include "main.h"

/**
 * mq_print_pointer - Function to print a pointer's value
 * @mq_types: The variadic arguments
 * @mq_buf: The buffer to print from
 * @mq_flag: Formatting flags
 * @mq_width: The minimum length
 * @mq_prec: To set precision
 * @mq_size: The buffer size
 *
 * Return: The number of printed characters
 */
int mq_print_pointer(va_list mq_types, char mq_buf[],
		int mq_flag, int mq_width, int mq_prec, int mq_size)
{
	char ext = 0, mq_padd = ' ';
	int index = BUFF_SIZE - 2, len = 2, pad_start = 1;
	unsigned long mq_num_addrs;
	char mq_map_to[] = "0123456789abcdef";
	void *mq_addrs = va_arg(mq_types, void *);

	UNUSED(mq_width);
	UNUSED(mq_size);

	if (mq_addrs == NULL)
		return (write(1, "(nil)", 5));

	mq_buf[BUFF_SIZE - 1] = '\0';
	UNUSED(mq_prec);

	mq_num_addrs = (unsigned long)mq_addrs;

	while (mq_num_addrs > 0)
	{
		mq_buf[index--] = mq_map_to[mq_num_addrs % 16];
		mq_num_addrs /= 16;
		len++;
	}

	if ((mq_flag & ZERO_FL) && !(mq_flag & MINUS_FL))
		mq_padd = '0';
	if (mq_flag & PLUS_FL)
		ext = '+', len++;
	else if (mq_flag & SPACE_FL)
		ext = ' ', len++;

	index++;

	return (mq_write_pointer(mq_buf, index, len, mq_width,
				mq_flag, mq_padd, ext, pad_start));
}

/**
 * mq_print_non_printable - Function to convert ascii to hex (non printable)
 * @mq_types: The variadic arguments
 * @mq_buf: The buffer to print from
 * @mq_flag: Formatting flags
 * @mq_width: The minimum length
 * @mq_prec: To set precision
 * @mq_size: The buffer size
 *
 * Return: no of printed characters
 */
int mq_print_non_printable(va_list mq_types, char mq_buf[],
		int mq_flag, int mq_width, int mq_prec, int mq_size)
{
	int m = 0, offset = 0;
	char *mq_string = va_arg(mq_types, char *);

	UNUSED(mq_flag);
	UNUSED(mq_width);
	UNUSED(mq_prec);
	UNUSED(mq_size);

	if (mq_string == NULL)
		return (write(1, "(null)", 6));

	while (mq_string[m] != '\0')
	{
		if (mq_is_printable(mq_string[m]))
			mq_buf[m + offset] = mq_string[m];
		else
			offset += mq_append_hexa_code(mq_string[m], mq_buf, m + offset);

		m++;
	}

	mq_buf[m + offset] = '\0';

	return (write(1, mq_buffer, m + offset));
}

/**
 * mq_print_reverse - Function to prints a reverse string
 * @mq_types: The varadic arguments
 * @mq_buf: The buffer to print from
 * @mq_flag: formatting flags
 * @mq_width: The minimum length
 * @mq_prec: To set precision
 * @mq_size: The buffer size
 *
 * Return: Number of printed characters
 */
int mq_print_reverse(va_list mq_types, char mq_buf[],
		int mq_flag, int mq_width, int mq_prec, int mq_size)
{
	char *mq_string;
	int i, mq_count = 0;

	UNUSED(mq_buf);
	UNUSED(mq_flag);
	UNUSED(mq_width);
	UNUSED(mq_size);

	mq_string = va_arg(mq_types, char *);

	if (mq_string == NULL)
	{
		UNUSED(mq_prec);
		mq_string = ")Null(";
	}
	for (i = 0; mq_string[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char mq_char = mq_string[i];

		write(1, &mq_char, 1);
		mq_count++;
	}
	return (mq_count);
}

/**
 * mq_print_rot13string - Function to convert string to rot13
 * @mq_types: The variadic arguments
 * @mq_buf: The buffer to print from
 * @mq_flag: formatting flags
 * @mq_width: The minimum length
 * @mq_prec: To set precision
 * @mq_size: The buffer size
 *
 * Return: The number printed characters
 */
int mq_print_rot13string(va_list mq_types, char mq_buf[],
		int mq_flag, int mq_width, int mq_prec, int mq_size)
{
	char ab;
	char *mq_string;
	unsigned int index, j;
	int mq_count = 0;
	char mq_in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char mq_out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	mq_string = va_arg(mq_types, char *);
	UNUSED(mq_buf);
	UNUSED(mq_flag);
	UNUSED(mq_width);
	UNUSED(mq_prec);
	UNUSED(mq_size);

	if (mq_string == NULL)
		mq_string = "(AHYY)";
	for (index = 0; mq_string[index]; i++)
	{
		for (j = 0; mq_in[j]; j++)
		{
			if (mq_in[j] == mq_string[index])
			{
				ab = mq_out[j];
				write(1, &ab, 1);
				mq_count++;
				break;
			}
		}
		if (!mq_in[j])
		{
			ab = mq_string[index];
			write(1, &ab, 1);
			mq_count++;
		}
	}
	return (mq_count);
}
