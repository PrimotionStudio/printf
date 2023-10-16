#include "main.h"

/**
 * print_string - The function to print a string
 * @string: The string to print
 * Return: The number of characters printed, which is the length of the string
 */
int print_string(char *string)
{
	int string_len;

	string_len = strlen(string);
	write(1, string, string_len);
	return (string_len);
}
