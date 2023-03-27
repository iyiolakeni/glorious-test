#include "main.h"

/**
 * _char - Prints a char
 * @arg: List a of arguments
 * @buffer_array: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @_size: Size specifier
 * Return: Number of chars printed
 */
int _char(va_list arg, char buffer_array[],
	int flag, int width, int precision, int size)
{
	char c = va_arg(arg, int);

	return (_char_printer(c, buffer_array, flag, width, precision, size));
}

/**
 * _string - function to print string datatype
 * @arg: List a of arguments
 * @buffer_array: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @_size: Size specifier
 * Return: Number of strings printed
 */
int _string(va_list arg, char buffer_array[],
            int flag, int width, int precision, int size)
{
    int i;
    int length = 0;
    char *str_ptr = va_arg(arg, char *);

    UNUSED(buffer_array);
    UNUSED(flag);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);

    if (str_ptr == NULL)
    {
        str_ptr = "(null)";
        if (precision > 5)
            str_ptr = "      ";
    }

    while (str_ptr[length] != '\0') /*iterate to determine string length*/
        length++;

    if (precision >= 0 && precision < length)
        length = precision;

    if (width > length)
    {
        if (flag & _MINUS)
        {
            write(1, &str_ptr[0], length);

            i = width - length;
            while (i != 0)
            {
                write(1, " ", 1);
                i--;
            }
            return (width);
        }
        else
        {
            i = width - length;
            while (i != 0)
            {
                write(1, " ", 1);
                i--;
            }
            write(1, &str_ptr[0], length);
            return (width);
        }
    }

    return (write(1, str_ptr, length));
}

/**
 * _percent - Prints a percent sign
 * @arg: List of arguments
 * @buffer_array: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @_size: Size specifier
 * Return: Number of chars printed
 */
int _percent(va_list arg, char buffer_array[],
	int flag, int width, int precision, int size)
{
    UNUSED(arg);
    UNUSED(buffer_array);
    UNUSED(flag);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);
    return (write(1, "%%", 1));
}
