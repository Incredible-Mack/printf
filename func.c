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
 * _decimal - handle  decimal d and i
 * @num: checks for positive or negative num
 * @characterCount: this a pointer
 * Return:  count on success
 */
int _decimal(int num, int *characterCount)
{
int count = 0; /*counting */
if (num < 0)
{
count = handle_char('-', characterCount);
num = -num;
}
if (num >= 10)
{
count += _decimal(num / 10, characterCount);
}
count += handle_char('0' + num % 10, characterCount);
return (count);
}
