## Name: _printf

## Description: Used to print a format string with given conversion characters to input variables and escape characters tomake other changes to the string.

## Usage: _printf("format", arguments);

Conversion Characters:
%c-character
%s-string
%d-integer
%i-integer
%b-binary
%x-lowercase hexidecimal
%X-uppercase hexidecimal
%o-octal
%u-unsigned int
%%-prints a single '%'

Escape Characters:
\\-prints a single '\'
\n-prints a new line
\t-prints a horizontal tab
\b-puts a backspace

## Examples:
_printf("Hello"); -> Hello
_printf("Number: %d", 5); -> Number: 5
_printf("%s", "string"); -> string
_printf("Hello\n"); -> Hello

_printf("Character: %c", 'f'); -> Character: f
