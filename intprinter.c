#include "main.h"

/**
 * _int - Print int
 * @arg: List of arguments
 * @buffer_array: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @_size: Size specifier
 * Return: Number of chars printed
 */
int _int(va_list arg, char buffer_array[],
	int flag, int width, int precision, int size)
{
    int i = BUFFER_SIZE - 2;
    int negative = 0;
    long int num = va_arg(arg, long int);
    unsigned long int _num;

    num = _number_size(num, size);

    if (num == 0)
        buffer_array[i--] = '0';

    buffer_array[BUFFER_SIZE -1] = '\0';
    _num = (unsigned long int)num;

    if (num < 0)
    {
        _num = (unsigned long int)((-1) * num);
        negative = 1;
    }

    while (_num > 0)
    {
        buffer_array[i--] = (num % 10) + '0';
        num /=10;
    }

    i++;

    return (_number_printer(negative, i, buffer_array, flag, width, precision, size));
}

/**
 * _binary - Prints an unsigned number
 * @arg: Lista of arguments
 * @buffer_array: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @_size: Size specifier
 * Return: Numbers of char printed.
 */
int _binary(va_list arg, char buffer_array[],
	int flag, int width, int precision, int size)
{
    unsigned int i = 0;
    unsigned int arg_holder;
    unsigned int binary;
    unsigned int sum;
    unsigned int arr[32];
    int counter;

    UNUSED(buffer_array);
    UNUSED(flag);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);

    arg_holder = va_arg(arg, unsigned int);
    binary = 2147483648; /* (2 ^ 31) */
    arr[0] = arg_holder / binary;

    while (i < 32)
    {
        binary /= 2;
        arr[i] = (arg_holder / binary) % 2;
        i++;
    }

    for (i = 0, sum = 0, counter = 0; i < 32; i++)
    {
        sum += arr[i];
        if (sum || i == 32)
        {
            char new_char = '0' + arr[i];

            write(1, &new_char, 1);
            counter++;
        }
    }
    return (counter);
}

/**
 * _unsigned - Prints an unsigned number
 * @arg: List a of arguments
 * @buffer_array: An array buffer to print unsigned number
 * @flag:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @_size: Size specifier
 * Return: Number of chars printed.
 */
int _unsigned(va_list arg, char buffer_array[],
	int flag, int width, int precision, int size)
{
    int i = BUFFER_SIZE - 2;
    unsigned long int num = va_arg(arg, unsigned long int);

    num = _unsigned_converter(num, size);

    if (num == 0)
        buffer_array[i--] = '\0';

    buffer_array[BUFFER_SIZE - 1] = '\0';

    while (num > 0)
    {
        buffer_array[i--] = (num % 10) + '0';
        num /= 10;
    }

    i++;

    return(write_unsigned(0, i, buffer_array, flag, width, precision, size));
}

/**
 * _octal - Prints an unsigned number in octal notation
 * @arg: List  of arguments
 * @buffer_array: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @_size: Size specifier
 * Return: Number of chars printed
 */
int _octal(va_list arg, char buffer_array[],
	int flag, int width, int precision, int size)
{
    int i = BUFFER_SIZE - 2;
    unsigned long int num = va_arg(arg, unsigned long int);
    unsigned long int num_holder = num;

    UNUSED(width);

    num = _unsigned_converter(num, size);

    if (num == 0)
        buffer_array[i--] = '0';

    buffer_array[BUFFER_SIZE - 1] = '\0';

    while (num > 0)
    {
        buffer_array[i--] = (num % 8) + '0';
        num /= 8; /* Divide the number by 8 which is octal base */
    }

    if (flag & _HASH && num_holder != 0)
        buffer_array[i--] = '0';

    i++;

    return(write_unsigned(0, i, buffer_array, flag, width, precision, size));
}

/**
 * _hexadecimal - Prints an unsigned number in hexadecimal notation
 * @arg: Lista of arguments
 * @buffer_array: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @_size: Size specifier
 * Return: Number of chars printed
 */
int _hexadecimal(va_list arg, char buffer_array[],
	int flag, int width, int precision, int size)
{
	return (_hexa_printer(arg, "0123456789abcdef", buffer_array,
		flag, 'x', width, precision, size));
}

/**
 * _unsigned_hexa - Prints an unsigned number in upper hexadecimal notation
 * @arg: Lista of arguments
 * @buffer_array: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @_size: Size specifier
 * Return: Number of chars printed
 */
int _unsigned_hexa(va_list arg, char buffer_array[],
	int flag, int width, int precision, int size)
{
     return (_hexa_printer(arg, "0123456789ABCDEF", buffer_array, flag, 'X', width, precision, size));
}
