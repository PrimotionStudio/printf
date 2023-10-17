#include "main.h"

/**
 * mq_print_buffer - print the buffer
 * @mq_buffer: chars
 * @mq_buff_ind: length.
 */
void mq_print_buffer(char mq_buffer[], int *mq_buff_ind)
{
	if (*mq_buff_ind > 0)
	{
		write(1, &mq_buffer[0], *mq_buff_ind);
	}

	*mq_buff_ind = 0;
}

/**
 * mq_printf - replicates the printf function
 * @mq_format: string.
 * Return: Number of printed characters
 */
int mq_printf(const char *mq_format, ...)
{
	int mq_i, mq_printed = 0, mq_printed_chars = 0;
	int mq_flags, mq_width, mq_precision, mq_size, mq_buff_ind = 0;
	va_list mq_list;
	char mq_buffer[BUFF_SIZE];

	if (mq_format == NULL)
		return (-1);
	va_start(mq_list, mq_format);
	for (mq_i = 0; mq_format && mq_format[mq_i] != '\0'; mq_i++)
	{
		if (mq_format[mq_i] != '%')
		{
			mq_buffer[mq_buff_ind++] = mq_format[mq_i];
			if (mq_buff_ind == BUFF_SIZE)
			{
				mq_print_buffer(mq_buffer, &mq_buff_ind);
			}
			mq_printed_chars++;
		}
		else
		{
			mq_print_buffer(mq_buffer, &mq_buff_ind);
			mq_flags = mq_get_flags(mq_format, &mq_i);
			mq_width = mq_get_width(mq_format, &mq_i, mq_list);
			mq_precision = mq_get_precision(mq_format, &mq_i, mq_list);
			mq_size = mq_get_size(mq_format, &mq_i);
			++mq_i;
			mq_printed = mq_handle_print(mq_format, &mq_i, mq_list, mq_buffer,
					mq_flags, mq_width, mq_precision, mq_size);
			if (mq_printed == -1)
			{
				return (-1);
			}
			mq_printed_chars += mq_printed;
		}
	}
	mq_print_buffer(mq_buffer, &mq_buff_ind);
	va_end(mq_list);
	return (mq_printed_chars);
}
