#include "holberton.h"

/**
 *caseSlash-handles the character after a '\'
 *Return:number of characters printed
 *@c:character after '\'
 */
int caseSlash(char c)
{
	int char_count = 0;

	switch (c)
	{
	case '\\':
		_putchar('\\');
		i++;
		char_count++;
		break;
	case 'n':
		_putchar('\n');
		i++;
		char_count++;
		break;
	case 't':
		_putchar('\t');
		i++;
		char_count++;
		break;
	}
	return (char_count);
}

/**
 *casePercent-handles the character after a '%'
 *Return:number of characters printed
 *@c:character after '%'
 */
int casePercent(char c)
{
	int char_count = 0;

	switch (c)
	{
	case 'c':
		_putchar(va_arg(cases, char));
		i++;
		char_count++;
		break;
	case 's':
		char_count += print_string(va_arg(cases, char*));
		i++;
		break;
	case 'd': case 'i':
		char_count += print_int(va_arg(cases, int));
		i++;
		break;
	case '%':
		_putchar('%');
		i++;
		char_count++;
		break;
	}
	return (char_count);
}

/**
 *_printf - the function prints a formated string to the standard output
 *@format: the formated string to be output
 *Return: will return the amount of characters printed by the function
 */
int _printf(const char *format, ...)
{
	int i = 0;
	int char_count = 0;
	va_list cases;

	va_start(cases, format);
	while (format[i] != '\0')
	{
		switch (format[i])
		{
		case '%':
			char_count += casePercent(format[i + 1]);
		case '\\':
			char_count += caseSlash(format[i + 1]);
		}
		_putchar(format[i]);
		char_count++;
	}
	return (char_count);
}
