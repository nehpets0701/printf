#include "holberton.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
/**
 *caseSlash - handles the character after '\'
 *Return:number of characters printed
 *@flag: the flag character used to format the output
 */
int caseSlash(char flag)
{
	int char_count = 0;

	switch (flag)
	{
	case '\\':
		_putchar('\\');
		char_count++;
		break;
	case 'n':
		_putchar('\n');
		char_count++;
		break;
	case 't':
		_putchar('\t');
		char_count++;
		break;
	case 'b':
		_putchar('\b');
		char_count++;
		break;
	default:
		exit(-1);
	}
	return (char_count);
}

int caseLong(char second, va_list cases)
{
	int char_count = 0;

	switch (second)
	{
	case 'd': case 'i':
		char_count += print_long_int(va_arg(cases, long int));
		break;
	case 'u':
		char_count += print_unsigned_long(va_arg(cases, unsigned long int));
		break;
	case 'o':
		char_count += print_long_octal(va_arg(cases, unsigned long int));
		break;
	case 'x':
		char_count += long_lower_hex(va_arg(cases, unsigned long int));
		break;
	case 'X':
		char_count += long_upper_hex(va_arg(cases, unsigned long int));
		break;
	}

	return (char_count);
}

int caseShort(char second, va_list cases)
{
	int char_count = 0;

	switch (second)
	{
	case 'd': case 'i':
		char_count += print_short_int(va_arg(cases, int));
		break;
	case 'u':
		char_count += print_unsigned_short(va_arg(cases, int));
		break;
	case 'o':
		char_count += print_short_octal(va_arg(cases, int));
		break;
	case 'x':
		char_count += short_lower_hex(va_arg(cases, int));
		break;
	case 'X':
		char_count += short_upper_hex(va_arg(cases, int));
		break;
	}

	return (char_count);
}

/**
 *casePercent-handles the character after a '%'
 *Return:number of characters printed
 *@flag: the flag character used to format the output
 *@cases: the va_list passed to the function where our variables are located
 */
int casePercent(char flag, char second, va_list cases)
{
	int char_count = 0;

	switch (flag)
	{
	case 'c':
		_putchar(va_arg(cases, int));
		char_count++;
		break;
	case 's':
		char_count += print_string(va_arg(cases, char*));
		break;
	case 'd': case 'i':
		char_count += print_int(va_arg(cases, int));
		break;
	case 'b':
		char_count += print_binary(va_arg(cases, unsigned int));
		break;
	case 'x':
		char_count += print_hexa(va_arg(cases, unsigned int));
		break;
	case 'X':
		char_count += print_hexa_upper(va_arg(cases, unsigned int));
		break;
	case 'o':
		char_count += print_octal(va_arg(cases, unsigned int));
		break;
	case 'u':
		char_count += print_unsign(va_arg(cases, unsigned int));
		break;
	case 'l':
		char_count += caseLong(second, cases);
		break;
	case 'h':
		char_count += caseShort(second, cases);
		break;
	case '%':
		_putchar('%');
		char_count++;
		break;
	default:
		exit(-1);
	}
	return (char_count);
}

/**
 *_printf - the function prints a formated string to the standard output
 *@format: the formated string to be output
 *Return: will return the amount of characters printed by the function
 *or a negative upon failure
 */
int _printf(const char *format, ...)
{
	int i = 0, char_count = 0;
	va_list cases;

	if (format == NULL || format[0] == '\0')
		return (-1);
	va_start(cases, format);
	while (format[i] != '\0')
	{
		switch (format[i])
		{
		case '%':
			char_count += casePercent(format[i + 1], format[i + 2], cases);
			i = i + 2;
			break;
		case '\\':
			char_count += caseSlash(format[i + 1]);
			i++;
			break;
		default:
			if (format[i] != '\0')
			{
				_putchar(format[i]);
				char_count++;
				i++;
			}
		}
	}
	va_end(cases);
	return (char_count);
}
