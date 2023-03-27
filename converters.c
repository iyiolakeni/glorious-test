#include "main.h"

/**
 * _number_size - Casts a number to the specified size
 * @num: Number to be casted.
 * @_size: Number indicating the type to be casted.
 *
 * Return: Casted value of num
 */
long int _number_size(long int num, int size)
{
    if (size == S_SHORT)
        return ((short)num);
    else if (size == S_LONG)
        return (num);

    return ((int)num);
}

/**
 * _unsigned_converter - Casts a number to the specified size
 * @num: Number to be casted
 * @_size: Number indicating the type to be casted
 *
 * Return: Casted value of num
 */
long int _unsigned_converter(unsigned long int num, int size)
{
    if (size == S_SHORT)
        return ((unsigned short)num);
    else if (size == S_LONG)
        return (num);

    return ((unsigned int)num);
}

/**
 * _hexa_printer - Prints a hexadecimal number in lower or upper
 * @arg: Lista of arguments
 * @map_tool: Array of values to map the number to
 * @buffer_array: Buffer array to handle print
 * @flag:  Calculates active flags
 * @flag_channel: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @_size: Size specifier
 * Return: Number of chars printed
 */
int _hexa_printer(va_list arg, char map_tool[], char buffer_array[],
	int flag, char flag_channel, int width, int precision, int size)
{
    int i = BUFFER_SIZE - 2;
    unsigned long int n = va_arg(arg, unsigned long int);
    unsigned long int num = n;

    UNUSED(width);

    n = _unsigned_converter(n, size);

    if (n == 0)
        buffer_array[i--] = '0';

    buffer_array[BUFFER_SIZE - 1] = '\0';

    while (n > 0)
    {
        buffer_array[i--] = map_tool[n % 16]; /* modulus by hexa */
        n /= 16;
    }

    if (flag & _HASH && num != 0)
    {
        buffer_array[i--] = flag_channel;
        buffer_array[i--] = '0';
    }

    i++;

    return (write_unsigned(0, i, buffer_array, flag, width, precision, size));
}
