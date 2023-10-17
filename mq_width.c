#include "main.h"

/**
 * mq_get_width - gets the width to print
 * @mq_format: string to print the arguments
 * @mq_i: no of varadic arguments
 * @mq_list: varadic arguments
 * Return: lenght to print.
 */
int mq_get_width(const char *mq_format, int *mq_i, va_list mq_list)
{
	int curr_i;
	int mq_width = 0;

	for (curr_i = *mq_i + 1; mq_format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(mq_format[curr_i]))
		{
			mq_width *= 10;
			mq_width += mq_format[curr_i] - '0';
		}
		else if (mq_format[curr_i] == '*')
		{
			curr_i++;
			mq_width = va_arg(mq_list, int);
			break;
		}
		else
		{
			break;
		}
	}

	*mq_i = curr_i - 1;

	return (mq_width);
}
