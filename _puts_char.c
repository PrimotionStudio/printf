#include "main.h"

/**
 * _mqputchar - Function to print characters to the stdout
 * @m: The character to print
 *
 * Return: 1 on success, -1 on error
 */

int _mqputchar(char m)
{
	return (write(1, &m, 1));
}

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
