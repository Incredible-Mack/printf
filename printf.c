#include "main.h"

/**
 * _printf - handle format conversion
 * @format: this is a pointer
 * Return: the number of character on success
 */


int _printf(const char *format, ...) /*handling format*/
{
int characterCount = 0;
va_list args;
va_start(args, format);

while (*format != '\0')
{
if (*format == '%')
{
format++;
if (*format == '%')
{
characterCount = handle_char('%', &characterCount);
}
else if (*format == 'c')
{
char c = va_arg(args, int);
characterCount = handle_char(c, &characterCount);
}
else if (*format == 's')
{
char *s = va_arg(args, char *); /*check for s*/
characterCount = handle_string(s, &characterCount);
}
else if (*format == 'd' || *format == 'i')
{
int num = va_arg(args, int);
int digitCount = handle_decimal(num, &characterCount);
characterCount += digitCount;
}
}
else
{
characterCount = handle_char(*format, &characterCount);
}
format++;
}

va_end(args);

return (characterCount);
}
