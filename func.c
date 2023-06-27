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

