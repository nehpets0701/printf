#include "holberton.h"
/**
 *print_rec - is called by print_int function to print out numbers to the SO
 *@num: The number to be output
 */
void print_rec(int num)
{
	if (num > 10)
	{
		print_rec(num / 10);
	}
	_putchar((num % 10) + '0');
}
/**
 *print_int - this function prints a number to the standard output
 *@num: The number to be output
 *Return: returns the amount of characters printed from the function
 */
int print_int(int num)
{
	int count = 1;

	if (num < 0)
		_putchar('-');

	print_rec(num);
	while (num > 10)
	{
		num /= 10;
		count++;
	}
	return (count);
}
