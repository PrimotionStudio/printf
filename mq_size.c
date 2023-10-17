#include "main.h"

/**
 * mq_get_size - gets the size of the argument
 * @mq_format: string to print arguments
 * @m: no arguments
 * Return: size of argument
 */
int mq_get_size(const char *mq_format, int *m)
{
	int curent_point = *m + 1;
	int mq_size = 0;

	if (mq_format[curent_point] == 'l')
	{
		mq_size = S_LONG;
	}
	else if (mq_format[curent_point] == 'h')
	{
		mq_size = S_SHORT;
	}

	if (mq_size == 0)
	{
		*m = curent_point - 1;
	}
	else
	{
		*m = curent_point;
	}

	return (mq_size);
}
