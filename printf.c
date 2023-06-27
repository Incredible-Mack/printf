#include "main.h"

/**
 * _printf - handle format conversion
 * @format: this is a pointer
 * Return: the number of character on success
 */


int _printf(const char *format, ...)
{
int characterCount = 0;
int digitCount = 0;
va_list args;
va_start(args, format);


while (*format != '\0')
{
if (*format == '%')
{
format++;

if (*format == 'c')
{
char c = (char)va_arg(args, int);
putchar(c);
characterCount++;
}
else if (*format == 's')
{
char *s = va_arg(args, char *);
while (*s != '\0')
{
putchar(*s);
s++;
characterCount++;
}
}
else if (*format == 'd' || *format == 'i')
{
int num = va_arg(args, int);
printf("%d", num);

if (num < 0)
{
digitCount = 1; /* Account for the '-' sign*/
num = -num;
}
while (num != 0)
{
digitCount++;
num /= 10;
}
characterCount += digitCount;
}
}
else
{
putchar(*format);
characterCount++;
}

format++;
}

va_end(args);

return (characterCount);
}
