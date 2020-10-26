#include "holberton.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 *caseSlash-handles the character after '\'
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
	}
	return (char_count);
}

/**
 *casePercent-handles the character after a '%'
 *Return:number of characters printed
 *@flag: the flag character used to format the output
 *@cases: the va_list passed to the function where our variables are located
 */
int casePercent(char flag, va_list cases)
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
	case '%':
		_putchar('%');
		char_count++;
		break;
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

	va_start(cases, format);
	while (format[i] != '\0')
	{
		switch (format[i])
		{
		case '%':
			char_count += casePercent(format[i + 1], cases);
			i = i + 2;
			break;
		case '\\':
			char_count += caseSlash(format[i + 1]);
			i++;
			break;
		}
		_putchar(format[i]);
		char_count++;
		i++;
	}
	va_end(cases);
	return (char_count - 1);
}
