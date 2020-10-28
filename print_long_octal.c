#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>
/**
 *find_length_octal - finds how many characters a are printed out/length of
 *octal #
 *@num: the number to be proccessed
 *Return: returns how many characters
 */
int find_length_octal_long(unsigned int num)
{
	int char_count = 1;

	while (num > 1)
	{
		num = num / 8;
		char_count++;
	}
	return (char_count);
}
/**
 *print_octal - this function takes a decimal number and print it in octal
 *@num: The number to be converted
 *Return: returns the amount of characters printed
 */
int print_long_octal(unsigned long int num)
{
	int char_count = 0;
	int *octal;
	int i = 1;

	char_count = find_length_octal_long(num);
	octal = malloc(sizeof(int) * char_count);

	if (octal == NULL)
		return (-1);

	octal[0] = num % 8;
	while (num > 1)
	{
		num = num / 8;
		octal[i] = num % 8;
		i++;
	}

	for (i = char_count - 1; i >= 0; i--)
		_putchar(octal[i] + '0');

	free(octal);
	return (char_count);
}
