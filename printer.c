#include "main.h"
/**
 * _printer - Prints an argument based on its type
 * @fmt: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @no: integer
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: 1 or 2;
 */
int _printer(const char *format, int *no, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknow_length = 0, _chars = -1;
	fmt_t fmt_types[] = {
		{'c', _char}, {'s', _string}, {'%', _percent},
		{'i', _int}, {'d', _int}, {'b', _binary},
		{'u', _unsigned}, {'o', _octal}, {'x', _hexadecimal},
		{'X', _unsigned_hexa}, {'p', _pointer_value}, {'S', _hexa_np},
		{'r', _reverse}, {'R', _rot13}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].format != '\0'; i++)
		if (format[*no] == fmt_types[i].format)
			return (fmt_types[i].fn(list, buffer, flags, width, precision, size));

	if (fmt_types[i].format == '\0')
	{
		if (format[*no] == '\0')
			return (-1);
		unknow_length += write(1, "%%", 1);
		if (format[*no - 1] == ' ')
			unknow_length += write(1, " ", 1);
		else if (width)
		{
			--(*no);
			while (format[*no] != ' ' && format[*no] != '%')
				--(*no);
			if (format[*no] == ' ')
				--(*no);
			return (1);
		}
		unknow_length += write(1, &format[*no], 1);
		return (unknow_length);
	}
	return (_chars);
}
