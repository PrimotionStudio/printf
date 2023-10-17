#include "main.h"

/**
 * mq_print_buffer - Function to print from the buffer
 * @mq_buf: The character array
 * @mq_buf_len: The character length
 */
void mq_print_buffer(char mq_buf[], int *mq_buf_len)
{
	if (*mq_buf_len > 0)
	{
		write(1, &mq_buf[0], *mq_buf_len);
	}

	*mq_buf_len = 0;
}

/**
 * _printf - Function to replicate the printf function
 * @format: The formatted string
 * Return: The number of printed characters
 */
int _printf(const char *format, ...)
{
	int mq_i, mq_print = 0, mq_print_chars = 0;
	int mq_flag, mq_width, mq_prec, mq_size, mq_buf_ind = 0;
	va_list mq_list;
	char mq_buf[BUFF_SIZE];

	if (format == NULL)
		return (-1);
	va_start(mq_list, format);
	for (mq_i = 0; format && format[mq_i] != '\0'; mq_i++)
	{
		if (format[mq_i] != '%')
		{
			mq_buffer[mq_buff_ind++] = format[mq_i];
			if (mq_buff_ind == BUFF_SIZE)
				mq_print_buffer(mq_buffer, &mq_buff_ind);
			mq_printed_chars++;
		}
		else
		{
			mq_print_buffer(mq_buf, &mq_buf_ind);
			mq_flag = mq_get_flags(format, &mq_i);
			mq_width = mq_get_width(format, &mq_i, mq_list);
			mq_prec = mq_get_precision(format, &mq_i, mq_list);
			mq_size = mq_get_size(format, &mq_i);
			++mq_i;
			mq_printed = mq_handle_print(format, &mq_i, mq_list, mq_buffer,
					mq_flags, mq_width, mq_precision, mq_size);
			if (mq_printed == -1)
				return (-1);
			mq_printed_chars += mq_printed;
		}
	}
	mq_print_buffer(mq_buf, &mq_buf_ind);
	va_end(mq_list);
	return (mq_print_chars);
}
