#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define _MINUS 1
#define _PLUS 2
#define _ZERO 4
#define _HASH 8
#define _SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct format
{
	char format;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct format fmt_t - Struct op
 *
 * @format: The format.
 * @fm_t: The function associated.
 */
typedef struct format fmt_t;

int _printf(const char *format, ...);
int _printer(const char *format, int *no, va_list arg, char buffer[],
             int flags, int width, int precision, int size);
void _print_buffer(char buffer[], int *buff_ind);
/****************** FUNCTIONS ******************/

/* Funtions to print chars and strings */
int _char(va_list arg, char buffer_array[], int flag, int width,
           int precision, int _size);
int _string(va_list arg, char buffer_array[],
            int flag, int width, int precision, int size);
int _percent(va_list types, char buffer[],
            int flags, int width, int precision, int size);

/* Functions to print numbers */
int _int(va_list types, char buffer[], int flags,
         int width, int precision, int size);
int _binary(va_list types, char buffer[], int flags, int width, int precision, int size);
int _unsigned(va_list types, char buffer[], int flags, int width, int precision, int size);
int _octal(va_list types, char buffer[], int flags, int width, int precision, int size);
int _hexadecimal(va_list types, char buffer[], int flags, int width, int precision, int size);
int _unsigned_hexa(va_list types, char buffer[], int flags, int width, int precision, int size);

int _hexa_printer(va_list types, char map_to[], char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function to print non printable characters */
int _hexa_np(va_list types, char buffer[], int flags, int width, int precision, int size);

/* Funcion to print memory address */
int _pointer_value(va_list types, char buffer[], int flags, int width, int precision, int size);

/* Funciotns to handle other specifiers */
int active_flags(const char *format, int *i);
int _width(const char *format, int *i, va_list list);
int _precision(const char *format, int *i, va_list list);
int _size(const char *format, int *i);

/*Function to print string in reverse*/
int _reverse(va_list types, char buffer[], int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int _rot13(va_list types, char buffer[], int flags, int width, int precision, int size);

/* width handler */
int _char_printer(char c, char buffer[], int flags, int width, int precision, int size);
int _number_printer(int is_positive, int ind, char buffer[], int flags, int width, int precision, int size);
int _printer_number(int ind, char bff[], int flags, int width, int precision, int length, char padd, char extra_c);
int _pointer_print(char buffer[], int ind, int length, int width, int flags, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind, char buffer[], int flags, int width, int precision, int size);

/****************** UTILS ******************/
int _print_check(char);
int _add_hexa(char, char[], int);
int _is_digit(char);

long int _number_size(long int num, int size);
long int _unsigned_converter(unsigned long int num, int size);

#endif /* MAIN_H */
