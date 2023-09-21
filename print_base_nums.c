#include "main.h"

/**
 * print_small_hexa - prints a number in hexadecimal base in lowercase
 * @b: variable arguments from _printf
 * @a: pointer to the struct flags
 * @f: pointer to the struct width
 * @d: pointer to the struct precision
 * @c: pointer to the struct length
 * Return: the number of characters printed
 */
int print_small_hexa(va_list b, flags_t *a, wid_t *f, pre_dot *d, len_t *c)
{
	unsigned int num = va_arg(b, unsigned int);
	char *str = convert(num, 16, 0, a, f, d, c);
	int count = 0;

	if (c->lon == 1 && c->sho == 0 && str[0] != '0')
		count += _putchar('l');
	if (c->sho == 1 && str[0] != '0')
		count += _putchar('h');

	if (d->dot && str[0] != '0')
		count += _putchar('.');

	if (f->nom && str[0] != '0')
		count += _putchar('^');

	if (a->minus == 1 && a->zero == 0 && a->hash == 0 && str[0] != '0')
		count += _putchar('-');
	if (a->zero == 1 && a->hash == 0 && str[0] != '0')
		count += _putchar('0');
	if (a->hash == 1 && str[0] != '0')
		count += _putchar('#');
	if (str[0] != '0')
		count += _puts(str);

	return (count);
}

/**
 * print_big_hexa - prints a number in hexadecimal base in uppercase
 * @b: variable arguments from _printf
 * @a: pointer to the struct flags
 * @f: pointer to the struct width
 * @d: pointer to the struct precision
 * @c: pointer to the struct length
 * Return: the number of characters printed
 */
int print_big_hexa(va_list b, flags_t *a, wid_t *f, pre_dot *d, len_t *c)
{
	unsigned int num = va_arg(b, unsigned int);
	char *str = convert(num, 16, 0, a, f, d, c);
	int count = 0;

	if (c->lon == 1 && c->sho == 0 && str[0] != '0')
		count += _putchar('l');

	if (c->sho == 1 && str[0] != '0')
		count += _putchar('h');

	if (d->dot && str[0] != '0')
		count += _putchar('.');

	if (f->nom && str[0] != '0')
		count += _putchar('^');

	if (a->minus == 1 && a->zero == 0 && a->hash == 0 && str[0] != '0')
		count += _putchar('-');
	if (a->zero == 1 && a->hash == 0 && str[0] != '0')
		count += _putchar('0');
	if (a->hash == 1 && str[0] != '0')
		count += _putchar('#');
	if (str[0] != '0')
		count += _puts(str);

	return (count);
}

/**
 * print_bin - prints a number in base 2, binary
 * @b: variable arguments from _printf
 * @a: pointer to the struct flags
 * @f: pointer to the struct width
 * @d: pointer to the struct precision
 * @c: pointer to the struct length
 * Return: the number of characters printed
 */
int print_bin(va_list b, flags_t *a, wid_t *f, pre_dot *d, len_t *c)
{
	unsigned int num = va_arg(b, unsigned int);
	char *str = convert(num, 2, 0, a, f, d, c);

	(void)a;
	(void)c;
	(void)f;

	return (_puts(str));
}

/**
 * print_octa - prints a number in base 8
 * @b: variable arguments from _printf
 * @a: pointer to the struct flag
 * @f: pointer to the struct width
 * @d: pointer to the struct precision
 * @c: pointer to the struct length
 * Return: the number of characters printed
 */
int print_octa(va_list b, flags_t *a, wid_t *f, pre_dot *d, len_t *c)
{
	unsigned int num = va_arg(b, unsigned int);
	char *str = convert(num, 8, 0, a, f, d, c);
	int count = 0;

	if (c->lon == 1 && c->sho == 0 && str[0] != '0')
		count += _putchar('l');
	if (c->sho == 1 && str[0] != '0')
		count += _putchar('h');
	if (d->dot && str[0] != '0')
		count += _putchar('.');

	if (f->nom && str[0] != '0')
		count += _putchar('^');

	if (a->minus == 1 && a->zero == 0 && a->hash == 0 && str[0] != '0')
		count += _putchar('-');
	if (a->zero == 1 && a->hash == 0 && str[0] != '0')
		count += _putchar('0');
	if (a->hash == 1 && str[0] != '0')
		count += _putchar('#');
	if (str[0] != '0')
	count += _puts(str);

	return (count);
}
