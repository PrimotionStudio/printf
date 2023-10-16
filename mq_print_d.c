#include "main.h"

/**
  * rec_print_int - Recursively print each digit of an integer
  * @integer: integer to print
  */
void rec_print_int(int integer)
{
	int digit;
	if (integer == 0)
		return;

	digit = integer % 10;
	rec_print_int(integer / 10);
	putchar(digit + '0');
	return;
}

/**
  * print_decimal - Prints a decimal figure
  * @decimal: decimal to be printed
  */
void print_decimal(int decimal)
{
	if (decimal < 0)
	{
		putchar('-');
		print_decimal(-decimal);
	}
	else
	{
		if (decimal == 0)
		{
			putchar('0');
			return;
		}
		else
		{
			rec_print_int(decimal);
		}
	}
}
