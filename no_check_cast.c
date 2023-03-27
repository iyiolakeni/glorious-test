#include "main.h"

/**
 * _print_check - Evaluates if a char is printable
 * @c: Char to be evaluated.
 *
 * Return: 1 if c is printable, 0 as fail
 */
int _print_check(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * _add_hex - Append ascci in hexadecimal code to buffer
 * @ascii: ASSCI CODE.
 * @buffer_array: Array of chars.
 * @index: Index at which to start appending.
 * Return: Always 3
 */
int _add_hex(char ascii, char buffer_array[], int i)
{
    char map_tool[] = "0123456789ABCDEF";
    /* The lenght of the hexa number is 2 */
    if (ascii < 0)
        ascii *= -1;

    buffer_array[i++] = '\\';
    buffer_array[i++] = 'x';

    buffer_array[i++] = map_tool[ascii / 16];
    buffer_array[i] = map_tool[ascii % 16];

    return (3);
}

/**
 * _is_digit - Verifies if a char is a digit
 * @c: Char to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int _is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}
