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
