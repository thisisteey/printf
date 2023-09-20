#include "main.h"

/**
 * print_mem_address - prints memory address of an input
 * in hexadecimal format
 * @b: va_list arguments from _printf
 * @a: pointer to the struct flags
 * @f: pointer to the struct width
 * @d: pointer to the struct precision
 * @c: pointer to the strcut length
 * Return: number of characters printed
 */
int print_mem_address(va_list b, flags_t *a, wid_t *f, pre_dot *d, len_t *c)
{
	char *s;
	unsigned long int p = va_arg(b, unsigned long int);

	int count = 0;

	if (!p)
		return (_puts("(nil)"));
	s = convert(p, 16, 1, a, f, d, c);
	count += _puts("0x");
	count += _puts(s);

	return (count);
}
