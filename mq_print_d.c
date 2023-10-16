
#include "main.h"

/**
  * rec_print_int - Recursively print each digit of an integer
  * @integer: integer to print
  * @count: holds digits counted
  * Return: number of digit
  */
int rec_print_int(int integer, int count)
{
	int digit;

	if (integer == 0)
		return (0);

	digit = integer % 10;
	count += rec_print_int((integer / 10), 1);
	_mqputchar(digit + '0');
	return (count);
}

/**
  * print_decimal - Prints a decimal figure
  * @decimal: decimal to be printed
  * Return: number of digit printed
  */
int print_decimal(int decimal)
{
	int count = 0;

	if (decimal < 0)
	{
		_mqputchar('-');
		count++;
		print_decimal(-decimal);
	}
	else
	{
		if (decimal == 0)
		{
			_mqputchar('0');
			count++;
			return (count);
		}
		else
		{
			count += rec_print_int(decimal, 0);
		}
	}
	return (count);
}
