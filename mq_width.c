#include "main.h"

/**
 * mq_get_width - gets the width to print
 * @mq_format: string to print the arguments
 * @m: no of varadic arguments
 * @mq_list: varadic arguments
 * Return: lenght to print.
 */
int mq_get_width(const char *mq_format, int *m, va_list mq_list)
{
	int curent_point;
	int mq_width = 0;

	for (curent_point = *m + 1; mq_format[curent_point] != '\0'; curent_point++)
	{
		if (mq_is_digit(mq_format[curent_point]))
		{
			mq_width *= 10;
			mq_width += mq_format[curent_point] - '0';
		}
		else if (mq_format[curent_point] == '*')
		{
			curent_point++;
			mq_width = va_arg(mq_list, int);
			break;
		}
		else
		{
			break;
		}
	}

	*m = curent_point - 1;

	return (mq_width);
}
