#include "main.h"

/**
 * print_str - prints a string
 * @b: va_list arguments from _printf
 * @a: pointer to the struct flags
 * Return: number of characters printed
 */
int print_str(va_list b, flags_t *a)
{
	char *s = va_arg(b, char *);

	(void)a;

	if (!s)
		s = "(null)";

	return (_puts(s));
}

/**
 * print_char - prints a character
 * @b: va_list arguments from _printf
 * @a: pointer to the struct flags
 * Return: number of characters printed
 */
int print_char(va_list b, flags_t *a)
{
	(void)a;
	_putchar(va_arg(b, int));

	return (1);
}
