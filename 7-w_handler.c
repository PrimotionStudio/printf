#include "main.h"

/**
 * mq_handle_write_char - Prints a string
 * @mq_c: The characters
 * @mq_buffer: The buffer
 * @mq_flags: To calculate the active flags
 * @mq_width: For the width
 * @mq_precision: To set precision
 * @mq_size: To set the size
 *
 * Return: Number of chars printed.
 */
int mq_handle_write_char(char mq_c, char mq_buffer[],
		int mq_flags, int mq_width, int mq_precision, int mq_size)
{
	int index = 0;
	char mq_padd = ' ';

	UNUSED(mq_precision);
	UNUSED(mq_size);

	if (mq_flags & ZERO_FL)
		mq_padd = '0';
	mq_buffer[index++] = mq_c;
	mq_buffer[index] = '\0';
	if (mq_width > 1)
	{
		mq_buffer[BUFF_SIZE - 1] = '\0';
		for (index = 0; index < mq_width - 1; index++)
			mq_buffer[BUFF_SIZE - index - 2] = mq_padd;
		if (mq_flags & MINUS_FL)
			return (write(1, &mq_buffer[0], 1) +
					write(1, &mq_buffer[BUFF_SIZE - index - 1], mq_width - 1));
		else
			return (write(1, &mq_buffer[BUFF_SIZE - index - 1], mq_width - 1) +
					write(1, &mq_buffer[0], 1));
	}
	return (write(1, &mq_buffer[0], 1));
}
/**
 * mq_write_number - Function to print a string
 * @mq_is_negative: The arguments passed to the function
 * @index: For the index of characters
 * @mq_buffer: The buffer
 * @mq_flags: To calculate the active flags
 * @mq_width: for the width
 * @mq_precision: To set precision
 * @mq_size: To set size
 *
 * Return: printed characters
 */
int mq_write_number(int mq_is_negative, int index, char mq_buffer[],
		int mq_flags, int mq_width, int mq_precision, int mq_size)
{
	int mq_length = BUFF_SIZE - index - 1;
	char mq_padd = ' ', mq_extra_ch = 0;

	UNUSED(mq_size);
	if ((mq_flags & ZERO_FL) && !(mq_flags & MINUS_FL))
		mq_padd = '0';
	if (mq_is_negative)
		mq_extra_ch = '-';
	else if (mq_flags & PLUS_FL)
		mq_extra_ch = '+';
	else if (mq_flags & SPACE_FL)
		mq_extra_ch = ' ';
	return (mq_write_num(index, mq_buffer, mq_flags, mq_width, mq_precision,
				mq_length, mq_padd, mq_extra_ch));
}
/**
 * mq_write_num - Function to print a number with buffer
 * @mq_prec: To set the precision
 * @mq_buf: The charcter array
 * @inx: The index of the number
 * @mq_len: The number length
 * @mq_wid: For the width
 * @mq_flags: To set flags
 * @mq_padd: For the padding
 * @mq_extra_c: For extra character
 *
 * Return: The printed characters
 */
int mq_write_num(int inx, char mq_buf[], int mq_flags, int mq_prec,
		int mq_wid, int mq_len, char mq_padd, char mq_extra_c)
{
	int m, padd_start = 1;

	if (mq_prec == 0 && inx == BUFF_SIZE - 2 && mq_buf[inx] == '0' && mq_wid == 0)
		return (0);
	if (mq_prec == 0 && inx == BUFF_SIZE - 2 && mq_buf[inx] == '0')
		mq_buf[inx] = mq_padd = ' ';
	if (mq_prec > 0 && mq_prec < mq_len)
		mq_padd = ' ';
	while (mq_prec > mq_len)
		mq_buf[--inx] = '0', mq_len++;
	if (mq_extra_c != 0)
		mq_len++;
	if (mq_wid > mq_len)
	{
		for (m = 1; m < mq_wid - mq_len + 1; m++)
			mq_buf[i] = mq_padd;
		mq_buf[i] = '\0';
		if (mq_flags & MINUS_FL && mq_padd == ' ')
		{
			if (mq_extra_c)
				mq_buf[--inx] = mq_extra_c;
			return (write(1, &mq_buf[inx], mq_len) + write(1, &mq_buf[1], m - 1));
		}
		else if (!(mq_flags & MINUS_FL) && mq_padd == ' ')
		{
			if (mq_extra_c)
				mq_buf[--inx] = mq_extra_c;
			return (write(1, &mq_buf[1], m - 1) + write(1, &mq_buf[inx], mq_len));
		}
		else if (!(mq_flags & MINUS_FL) && mq_padd == '0')
		{
			if (mq_extra_c)
				mq_buf[--padd_start] = mq_extra_c;
			return (write(1, &mq_buf[padd_start], m - padd_start) +
					write(1, &mq_buf[inx], mq_len - (1 - padd_start)));
		}
	}
	if (mq_extra_c)
		mq_buf[--inx] = mq_extra_c;
	return (write(1, &mq_buf[inx], mq_len));
}
/**
 * mq_write_unsigned - Function to print unsigned number
 * @mq_is_negative: To show negative numbers
 * @mq_precision: set precision
 * @mq_size: set size
 * @mq_buffer: character array
 * @index: The index of the number in buffer
 * @mq_width: For the width
 * @mq_flags: To set flags
 *
 * Return: Printed digits
 */
int mq_write_unsign(int mq_is_negative, int index,
		char mq_buffer[], int mq_flags, int mq_width, int mq_precision, int mq_size)
{
	int mq_length = BUFF_SIZE - index - 1, i = 0;
	char mq_padd = ' ';

	UNUSED(mq_is_negative);
	UNUSED(mq_size);

	if (mq_precision == 0 && index == BUFF_SIZE - 2 && mq_buffer[index] == '0')
		return (0);
	if (mq_precision > 0 && mq_precision < mq_length)
		mq_padd = ' ';
	while (mq_precision > mq_length)
	{
		mq_buffer[--index] = '0';
		mq_length++;
	}
	if (mq_flags & ZERO_FL && !(mq_flags & MINUS_FL))
		mq_padd = '0';
	if (mq_width > mq_length)
	{
		for (i = 0; i < mq_width - mq_length; i++)
			mq_buffer[i] = mq_padd;
		mq_buffer[i] = '\0';
		if (mq_flags & MINUS_FL)
		{
			return (write(1, &mq_buffer[index], mq_length) + write(1,
						&mq_buffer[0], i));
		}
		else
		{
			return (write(1, &mq_buffer[0], i) + write(1,
						&mq_buffer[index], mq_length));
		}
	}
	return (write(1, &mq_buffer[index], mq_length));
}
/**
 * mq_write_pointer - Function to print memory address
 * @mq_buffer: character array
 * @index: The index of the number in buffer
 * @mq_length: The length of the numbers
 * @mq_width: For the width
 * @mq_flags: To set flags
 * @mq_padd: For padding
 * @mq_extra_c: The extra character
 * @padd_start: Padding index
 *
 * Return: characters written
 */
int mq_write_pointer(char mq_buffer[], int index, int mq_length,
		int mq_width, int mq_flags, char mq_padd, char mq_extra_c, int padd_start)
{
	int i;

	if (mq_width > mq_length)
	{
		for (i = 3; i < mq_width - mq_length + 3; i++)
			mq_buffer[i] = mq_padd;
		mq_buffer[i] = '\0';
		if (mq_flags & MINUS_FL && mq_padd == ' ')
		{
			mq_buffer[--index] = 'x';
			mq_buffer[--index] = '0';
			if (mq_extra_c)
				mq_buffer[--index] = mq_extra_c;
			return (write(1, &mq_buffer[index], mq_length) + write(1,
						&mq_buffer[3], i - 3));
		}
		else if (!(mq_flags & MINUS_FL) && mq_padd == ' ')
		{
			mq_buffer[--index] = 'x';
			mq_buffer[--index] = '0';
			if (mq_extra_c)
				mq_buffer[--index] = mq_extra_c;
			return (write(1, &mq_buffer[3], i - 3) + write(1,
						&mq_buffer[index], mq_length));
		}
		else if (!(mq_flags & MINUS_FL) && mq_padd == '0')
		{
			if (mq_extra_c)
				mq_buffer[--padd_start] = mq_extra_c;
			mq_buffer[1] = '0';
			mq_buffer[2] = 'x';
			return (write(1, &mq_buffer[padd_start], i - padd_start) +
					write(1, &mq_buffer[index], mq_length - (1 - padd_start) - 2));
		}
	}
	mq_buffer[--index] = 'x';
	mq_buffer[--index] = '0';
	if (mq_extra_c)
		mq_buffer[--index] = mq_extra_c;
	return (write(1, &mq_buffer[index], BUFF_SIZE - index - 1));
}
