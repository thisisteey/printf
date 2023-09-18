#include "main.h"

/**
 * print_mem_address - prints memory address of an input
 * in hexadecimal format
 * @b: va_list arguments from _printf
 * @a: pointer to the struct flags
 * Return: number of characters printed
 */
int print_mem_address(va_list b, flags_t *a)
{
	char *s;
	unsigned long int p = va_arg(b, unsigned long int);

	int count = 0;

	(void)a;

	if (!p)
		return (_puts("(nil)"));
	s = convert(p, 16, 1);
	count += _puts("0x");
	count += _puts(s);

	return (count);
}
