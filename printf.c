#include "main.h"


/**
 * handle_decimal - handle  decimal d and i
 * @num: checks for positive or negative num
 * @characterCount: this a pointer
 * Return:  count on success
 */

int handle_decimal(int num, int *characterCount)
{
int digitCount = 0;

if (num < 0)
{
handle_char('-', characterCount);
num = -num;
digitCount++;
}

if (num == 0)
{
handle_char('0', characterCount);
digitCount++;
}
else
{
int reversedNum = 0;

while (num != 0)
{
reversedNum = reversedNum * 10 + num % 10;
num /= 10;
digitCount++;
}

while (reversedNum != 0)
{
int digit = reversedNum % 10;
handle_char('0' + digit, characterCount);
reversedNum /= 10;
}
}

return (*characterCount);
}

/**
 * _printf - handle format conversion
 * @format: this is a pointer
 * Return: the number of character on success
 */

int _printf(const char *format, ...)
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
handle_char('%', &characterCount);
}
else if (*format == 'c')
{
char c = (char)va_arg(args, int);
handle_char(c, &characterCount);
}
else if (*format == 's')
{
char *s = va_arg(args, char *);
handle_string(s, &characterCount);
}
else if (*format == 'd' || *format == 'i')
{
int num = va_arg(args, int);
handle_decimal(num, &characterCount);
}
}
else
{
handle_char(*format, &characterCount);
}
format++;
}

va_end(args);

return (characterCount);
}
