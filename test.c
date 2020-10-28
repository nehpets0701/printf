#include <limits.h>
#include <stdio.h>
#include "holberton.h"

int main(void)
{
	int test = 10;
	int neg =  -1;

	_printf("%X\n", test);
	_printf("%o\n", test);
	_printf("%x\n", test);
	_printf("%u\n", test);
	_printf("%u\n", neg);
	return (0);
}
