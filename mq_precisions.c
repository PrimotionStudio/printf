#include "main.h"

/**
 * mq_get_precision - gets the precision for formats
 * @mq_format: string to print
 * @mq_i: no arguments
 * @mq_list: varadic arguments
 * Return: int precision.
 */
int mq_get_precision(const char *mq_format, int *mq_i, va_list mq_list)
{
	int curr_i = *mq_i + 1;
	int mq_precision = -1;

	if (mq_format[curr_i] != '.')
	{
		return (mq_precision);
	}

	mq_precision = 0;

	for (curr_i += 1; mq_format[curr_i] != '\0'; curr_i++)
	{
		if (mq_is_digit(mq_format[curr_i]))
		{
			mq_precision *= 10;
			mq_precision += mq_format[curr_i] - '0';
		}
		else if (mq_format[curr_i] == '*')
		{
			curr_i++;
			mq_precision = va_arg(mq_list, int);
			break;
		}
		else
		{
			break;
		}
	}

	*mq_i = curr_i - 1;

	return (mq_precision);
}
