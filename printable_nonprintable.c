#include "main.h"

/**
 * mq_print_pointer - prints a pointer's value
 * @mq_types: varadic arguments
 * @mq_buffer: buffer to print
 * @mq_flags: Formatting flags
 * @mq_width: minimum length
 * @mq_precision: precision
 * @mq_size: buffer size
 * Return: no of printed characters
 */
int mq_print_pointer(va_list mq_types, char mq_buffer[],
		int mq_flags, int mq_width, int mq_precision, int mq_size)
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

	mq_buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(mq_precision);

	mq_num_addrs = (unsigned long)mq_addrs;

	while (mq_num_addrs > 0)
	{
		mq_buffer[index--] = mq_map_to[mq_num_addrs % 16];
		mq_num_addrs /= 16;
		len++;
	}

	if ((mq_flags & F_ZERO) && !(mq_flags & F_MINUS))
		mq_padd = '0';
	if (mq_flags & F_PLUS)
		ext = '+', len++;
	else if (mq_flags & F_SPACE)
		ext = ' ', len++;

	index++;

	return (mq_write_pointer(mq_buffer, index, len, mq_width,
				mq_flags, mq_padd, ext, pad_start));
}

/**
 * mq_print_non_printable - converts ascii to hex (non printable)
 * @mq_types: varadic arguments
 * @mq_buffer: buffer to print
 * @mq_flags: Formatting flags
 * @mq_width: minimum length
 * @mq_precision: precision
 * @mq_size: buffer size
 * Return: no of printed characters
 */
int mq_print_non_printable(va_list mq_types, char mq_buffer[],
		int mq_flags, int mq_width, int mq_precision, int mq_size)
{
	int m = 0, offset = 0;
	char *mq_string = va_arg(mq_types, char *);

	UNUSED(mq_flags);
	UNUSED(mq_width);
	UNUSED(mq_precision);
	UNUSED(mq_size);

	if (mq_string == NULL)
		return (write(1, "(null)", 6));

	while (mq_string[m] != '\0')
	{
		if (mq_is_printable(mq_string[m]))
			mq_buffer[m + offset] = mq_string[m];
		else
			offset += mq_append_hexa_code(mq_string[m], mq_buffer, m + offset);

		m++;
	}

	mq_buffer[m + offset] = '\0';

	return (write(1, mq_buffer, m + offset));
}

/**
 * mq_print_reverse - Prints a reverse string
 * @mq_types: varadic arguments
 * @mq_buffer: buffer to print
 * @mq_flags: formatting flags
 * @mq_width: minimum length
 * @mq_precision: precision
 * @mq_size: buffer size
 * Return: no of printed characters
 */
int mq_print_reverse(va_list mq_types, char mq_buffer[],
		int mq_flags, int mq_width, int mq_precision, int mq_size)
{
	char *mq_string;
	char mq_character;
	int i, mq_count = 0;

	UNUSED(mq_buffer);
	UNUSED(mq_flags);
	UNUSED(mq_width);
	UNUSED(mq_size);

	mq_string = va_arg(mq_types, char *);

	if (mq_string == NULL)
	{
		UNUSED(mq_precision);
		mq_string = ")Null(";
	}
	for (i = 0; mq_string[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		mq_character = mq_string[i];

		write(1, &mq_character, 1);
		mq_count++;
	}
	return (mq_count);
}

/**
 * mq_print_rot13string - converts string to rot13
 * @mq_types: varadic arguments
 * @mq_buffer: buffer to print
 * @mq_flags: formatting flags
 * @mq_width: minimum length
 * @mq_precision: precision
 * @mq_size: buffer size
 * Return: no of printed characters
 */
int mq_print_rot13string(va_list mq_types, char mq_buffer[],
		int mq_flags, int mq_width, int mq_precision, int mq_size)
{
	char x;
	char *mq_string;
	unsigned int i, j;
	int mq_count = 0;
	char mq_in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char mq_out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	mq_string = va_arg(mq_types, char *);
	UNUSED(mq_buffer);
	UNUSED(mq_flags);
	UNUSED(mq_width);
	UNUSED(mq_precision);
	UNUSED(mq_size);

	if (mq_string == NULL)
		mq_string = "(AHYY)";
	for (i = 0; mq_string[i]; i++)
	{
		for (j = 0; mq_in[j]; j++)
		{
			if (mq_in[j] == mq_string[i])
			{
				x = mq_out[j];
				write(1, &x, 1);
				mq_count++;
				break;
			}
		}
		if (!mq_in[j])
		{
			x = mq_string[i];
			write(1, &x, 1);
			mq_count++;
		}
	}
	return (mq_count);
}
