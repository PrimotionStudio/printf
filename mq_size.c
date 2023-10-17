#include "main.h"

/**
 * mq_get_size - gets the size of the argument
 * @mq_format: string to print arguments
 * @mq_i: no arguments
 * Return: size of argument
 */
int mq_get_size(const char *mq_format, int *mq_i)
{
	int curent_point = *mq_i + 1;
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
		*mq_i = curent_point - 1;
	}
	else
	{
		*mq_i = curent_point;
	}

	return (mq_size);
}
