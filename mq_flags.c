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

	const char CHAR_F[] = {'-', '+', '0', '#', ' ', '\0'};
	const int ARR_FL[] = {MINUS_FL, PLUS_FL, ZERO_FL, HASH_FL, SPACE_FL, 0};

	for (mq_curr = *mq_par + 1; format[mq_curr] != '\0'; mq_curr++)
	{
		for (m = 0; CHAR_F[m] != '\0'; m++)
			if (format[mq_curr] == CHAR_F[m])
			{
				mq_flags |= ARR_F[m];

				break;
			}
		if (CHAR_F[m] == 0)
			break;
	}
	*mq_par = mq_curr - 1;

	return (mq_flags);
