#include "main.h"

/**
 * print_str - prints a string
 * @b: va_list arguments from _printf
 * @a: pointer to the struct flags
 * @f: pointer to the struct width
 * @d: pointer to the struct precision
 * @c: pointer to the struct length
 * Return: number of characters printed
 */
int print_str(va_list b, flags_t *a, wid_t *f, pre_dot *d, len_t *c)
{
	char *s = va_arg(b, char *);
	int count = 0;

	(void)a;
	(void)f;
	(void)d;
	(void)c;

	if (!s)
		s = "(null)";
	count = _puts(s);

	return (count);
}

/**
 * print_char - prints a character
 * @b: va_list arguments from _printf
 * @a: pointer to the struct flags
 * @f: pointer to the struct width
 * @d: pointer to the struct precision
 * @c: pointer to the struct length
 * Return: number of characters printed
 */
int print_char(va_list b, flags_t *a, wid_t *f, pre_dot *d, len_t *c)
{
	char s = va_arg(b, int);
	(void)a;
	(void)f;
	(void)d;
	(void)c;

	_putchar(s);

	return (1);
}
