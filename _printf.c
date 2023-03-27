#include "main.h"
/**
 * _print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void _print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i = 0, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	while (format && format[i] != '\0')
	{
		if (format[i] == '%')
		{
		    _print_buffer(buffer, &buff_ind);
			flags = active_flags(format, &i);
			width = _width(format, &i, list);
			precision = _precision(format, &i, list);
			size = _size(format, &i);
			++i;
			printed = _printer(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;

		}
		else
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				_print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		i++;
	}

	_print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}
