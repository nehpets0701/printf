#include "holberton.h"

/**
 *print_hex-prints unsigned decimal value as hexadecimal
 *Return: the number of characters printed
 *@num:unsigned decimal input
 */
int print_hex(unsigned int num)
{
	int char_count = 0;
	int i = 0;
	char hexNum[100];
	int temp = 0;
	int j;

	while (num != 0)
	{
		temp = num % 16;

		if (temp < 10)
		{
			hexNum[i] = temp + 48;
			i++;
		}
		else
		{
			hexNum[i] = temp + 55;
			i++;
		}
		num = num / 16;
	}

	for (j = i - 1; j >= 0; j--)
	{
		_putchar(hexNum[j]);
		char_count++;
	}
	return (char_count);
}
