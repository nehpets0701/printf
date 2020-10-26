#include "holberton.h"
/**
 *print_string - this function prints a string to the standard output
 *@str: The string to be output
 *Return: returns the amount of characters printed from the function
 */
int print_string(char *str)
{
	int num_char = 0;
	int i = 0;

	if (str != NULL)
	{
		for (i = 0; str[i] != '\0'; i++)
		{
			_putchar(str[i]);
			num_char++;
		}
	}
	return (num_char);
}
