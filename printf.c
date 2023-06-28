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

while (*format != '\0') /*while not zero*/
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
char *s = va_arg(args, char *);
characterCount = handle_string(s, &characterCount);
}
else if (*format == 'd' || *format == 'i')
{
int num = va_arg(args, int);
int digitCount = 0;
if (num < 0)
{
characterCount = handle_char('-', &characterCount);
num = -num;
digitCount++;
}
if (num == 0)
{
characterCount = handle_char('0', &characterCount);
digitCount++;
}
while (num > 0)
{
int digit = num % 10;
characterCount = handle_char('0' + digit, &characterCount);
num /= 10;
digitCount++;
}
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

