#include "holberton.h"
/**
 *print_rec_unsign - is called by print_int function to print out
 *numbers to the SO
 *@num: The number to be output
 */
void print_rec_unsign(unsigned int num)
{
	if (num > 10)
	{
		print_rec_unsign(num / 10);
	}
	_putchar((num % 10) + '0');
}
/**
 *print_unsign - this function prints a number to the standard output
 *@num: The number to be output
 *Return: returns the amount of characters printed from the function
 */
int print_unsign(unsigned int num)
{
	int count = 1;

	if (num == 10)
	{
		_putchar('1');
		_putchar('0');
	}
	else
		print_rec_unsign(num);
	while (num > 10)
	{
		num /= 10;
		count++;
	}
	return (count);
}
