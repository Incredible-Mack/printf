#include "main.h"

/**
 * handle_char - handle  printing of a single character
 * @c: the character
 * @characterCount: this a pointer
 * Return: the character count on success
 */

int handle_char(char c, int *characterCount)
{
putchar(c);
(*characterCount)++;
return (*characterCount);
}

/**
 * handle_string - handle  printing of string
 * @s: the string
 * @characterCount: this a pointer
 * Return: the character count on success
 */
int handle_string(char *s, int *characterCount)
{
while (*s != '\0')
{
putchar(*s);
s++;
(*characterCount)++;
}
return (*characterCount);
}

/**
 * handle_decimal - handle  decimal d and i
 * @num: checks for positive or negative num
 * @characterCount: this a pointer
 * Return:  count on success
 */

int handle_decimal(int num, int *characterCount)
{
int digitCount = 0;
int digit;
if (num < 0)
{
*characterCount = handle_char('-', characterCount);
num = -num;
}

if (num == 0)
{
digitCount++;
*characterCount = handle_char('0', characterCount);
}
else
{
while (num > 0)
{
digitCount++;
digit = num % 10;
*characterCount = handle_char('0' + digit, characterCount);
num /= 10;
}
}
return (digitCount);
}
