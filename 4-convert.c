#include "main.h"

/**
 * mq_is_printable - checks if the character is printable
 * @c: character.
 * Return: printable status
 */
int mq_is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * mq_append_hexa_code - convert ascii to hex
 * @buff: contains the characters
 * @index: posistion to append
 * @_ascii: ascii
 * Return: 3
 */
int mq_append_hexa_code(char _ascii, char buff[], int index)
{
	char _map[] = "0123456789ABCDEF";

	if (_ascii < 0)
		_ascii *= -1;

	buff[index++] = '\\';
	buff[index++] = 'x';

	buff[index++] = _map[_ascii / 16];
	buff[index] = _map[_ascii % 16];

	return (3);
}

/**
 * mq_is_digit - check if a char is a digit
 * @c: character
 * Return: digit status 1, 0
 */
int mq_is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/**
 * mq_convert_size_number - convert a number's size
 * @numb: number to be changed
 * @size: size to be changed to
 * Return: data type of size
 */
long int mq_convert_size_number(long int numb, int size)
{
	if (size == MQ_S_LONG)
		return (numb);
	else if (size == MQ_S_SHORT)
		return ((short)numb);
	return ((int)numb);
}

/**
 * mq_convert_size_unsign - convert a number's size
 * @numb: number to be changed
 * @size: size to be changed to
 * Return: data type of size
 */
long int mq_convert_size_unsign(unsigned long int numb, int size)
{
	if (size == MQ_S_LONG)
		return (numb);
	else if (size == MQ_S_SHORT)
		return ((unsigned short)numb);
	return ((unsigned int)numb);
}
