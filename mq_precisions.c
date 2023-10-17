#include "main.h"

/**
 * mq_get_precision - gets the precision for formats
 * @mq_format: string to print
 * @m: no arguments
 * @mq_list: varadic arguments
 * Return: int precision.
 */
int mq_get_precision(const char *mq_format, int *m, va_list mq_list)
{
	int curent_point = *m + 1;
	int mq_precision = -1;

	if (mq_format[curent_point] != '.')
	{
		return (mq_precision);
	}

	mq_precision = 0;

	for (curent_point += 1; mq_format[curr_i] != '\0'; curr_i++)
	{
		if (mq_is_digit(mq_format[curent_point]))
		{
			mq_precision *= 10;
			mq_precision += mq_format[curent_point] - '0';
		}
		else if (mq_format[curent_point] == '*')
		{
			curent_point++;
			mq_precision = va_arg(mq_list, int);
			break;
		}
		else
		{
			break;
		}
	}

	*m = curent_point - 1;

	return (mq_precision);
}
