#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>
/**
 *find_length - finds how many characters a are printed out/length of binary #
 *@num: the number to be proccessed
 *Return: returns how many characters
 */
int find_length(unsigned int num)
{
	int char_count = 1;

	while (num > 1)
	{
		num = num / 2;
		char_count++;
	}
	return (char_count);
}
/**
*print_binary - this function takes a decimal number and print it in binary
*@num: The number to be converted
*Return: returns the amount of characters printed
*/
int print_binary(unsigned int num)
{
	int char_count = 0;
	int *binary;
	int i = 1;

	char_count = find_length(num);
	binary = malloc(sizeof(int) * char_count);

	if (binary == NULL)
		return (-1);

	if (num % 2 == 0)
		binary[0] = 0;
	else
		binary[0] = 1;

	while (num > 1)
	{
		num = num / 2;
		if (num % 2 == 0)
			binary[i] = 0;
		else
			binary[i] = 1;
		i++;
	}

	for (i = char_count - 1; i >= 0; i--)
		_putchar(binary[i] + '0');

	free(binary);
	return (char_count);
}
