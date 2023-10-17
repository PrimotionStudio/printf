#include "main.h"
/**
 * mq_get_flags - Function to calculate the active flags
 * @format: The formatted string to be printed
 * @mq_par: The parameter representing the current position
 * Return: mq_flags
 */
int mq_get_flags(const char *format, int *mq_par)
{
	int m, mq_curr;

	int mq_flags = 0;

	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (mq_curr = *mq_par + 1; format[mq_curr] != '\0'; mq_curr++)
	{
		for (m = 0; FLAGS_CH[m] != '\0'; m++)
			if (format[mq_curr] == FLAGS_CH[m])
			{
				mq_flags |= FLAGS_ARR[m];

				break;
			}
		if (FLAGS_CH[m] == 0)
			break;
	}
	*mq_par = mq_curr - 1;

	return (mq_flags);
}

