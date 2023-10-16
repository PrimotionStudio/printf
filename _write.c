#include "main.h"

/**
 * print_char - The function to print a character
 * @m: The character to print to stdout
 * Return: The number of characters printed (1)
 */
int print_char(char m)
{
	write(1, &m, 1);

	return (1);
}
