#include "main.h"

/**
 * _printf - handle format conversion
 * @format: this is a pointer
 * Return: the number of character on success
 */


int _printf(const char *format, ...) /*handles format*/
{
int characterCount;
va_list args; /*agument*/
va_start(args, format);

characterCount = 0;
while (*format != '\0')
{
if (*format == '%')
{
format++;
if (*format == 'c')
{
char c = va_arg(args, int); /*getting c and int */
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
characterCount++;
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
