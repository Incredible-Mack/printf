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
if (*format == '%') /*checking for % conversion */
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
