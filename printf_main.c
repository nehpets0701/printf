#include <limits.h>
#include <stdio.h>
#include "holberton.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
        char *test = "cool";
        int len;
        int len2;
        unsigned int decimal = 34620;
        unsigned int hexa = /*7562*/ 2147484671;
        int binleng;
        int binhex;
        int nullCount = 0;
        int mitch = 0;

        binleng = _printf("%b\n", decimal);
        binhex = _printf("%x\n", hexa);
        len = _printf("Let's try to printf a simple sentence.\n");
        len2 = printf("let's try to printf a simple sentence.\n");

        _printf("Length:[%d, %i]\n", len, len);
        printf("Length:[%d, %i]\n", len2, len2);
        _printf("Negative:[%d]\n", -762534);
        printf("Negative:[%d]\n", -762534);

        _printf("decimal number %d in binary is %b\n", decimal, decimal);
        _printf("prints how many characters printed by %%b: %d\n", binleng);

        _printf("decimal number %d in hexa is %x\n", hexa, hexa);
        _printf("prints how mant characters printed by %%x: %d\n", binhex);

        /*mitch tests*/
        _printf("%s\n", "sentence");
        nullCount = _printf("%s\n", (char *)0);
        _printf("%d\n", nullCount);

        _printf("%%\n");
        mitch = _printf("why%c", '\n');
        _printf("This is the count for new line check %d\n", mitch);

        _printf(test);
        return (0);
}
