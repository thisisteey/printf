#include "main.h"

/**
 * print_integer - prints an integer
 * @b: va_list arguments
 * @a: pointer to the struct flags
 * @f: pointer to the struct width
 * @d: pointer to the struct precision
 * @c: pointer to the struct length
 * Return: number of characters printed
 */
int print_integer(va_list b, flags_t *a, wid_t *f, pre_dot *d, len_t *c)
{
	int x = va_arg(b, int);
	int res = count_digit(x);

	if (c->lon == 1 && c->sho == 0 && x >= 0)
		res += _putchar('l');

	if (c->sho == 1 && x >= 0)
		res += _putchar('h');

	if (d->dot && x >= 0)
		res += _putchar('.');

	if (f->nom && x >= 0)
		res += _putchar('^');

	if (a->space == 1 && a->plus == 0 && a->minus == 0 && a->zero == 0 && x >= 0)
		res += _putchar(' ');
	if (a->plus == 1 && a->minus == 0 && a->zero == 0 && x >= 0)
		res += _putchar('+');
	if (a->minus == 1 && a->zero == 0 && x >= 0)
		res += _putchar('-');
	if (a->zero == 1 && x >= 0)
		res += _putchar('0');
	if (x <= 0)
		res++;
	print_num(x);
	return (res);
}

/**
 * print_unsigned_int - prints an unsigned integer
 * @b: variable list of arguments
 * @a: pointer to the struct flags
 * @f: pointer to the struct width
 * @d: pointer to the struct precision
 * @c: pointer to the struct length
 * Return: number of characters printed
 */
int print_unsigned_int(va_list b, flags_t *a, wid_t *f, pre_dot *d, len_t *c)
{
	unsigned int u = va_arg(b, unsigned int);
	int res = 0;

	if (c->lon == 1 && c->sho == 0 && u > 0)
		res += _putchar('l');
	if (c->sho == 1 && u > 0)
		res += _putchar('h');

	if (d->dot == 1 && u > 0)
		res += _putchar('.');

	if (f->nom == 1 && u > 0)
		res += _putchar('^');

	if (a->minus == 1 && a->zero == 0 && u > 0)
		res += _putchar('-');

	if (a->zero == 1 && u > 0)
		res += _putchar('0');

	res += _putchar('u');

	return (res);
}

/**
 * print_num - loops through an integer and prints all its digits
 * @x: integer to be printed
 * Return: void
 */
void print_num(int x)
{
	unsigned int x1;

	if (x < 0)
	{
		_putchar('-');
		x1 = -x;
	}
	else
		x1 = x;
	if (x1 / 10)
		print_num(x1 / 10);
	_putchar((x1 % 10) + '0');
}

/**
 * count_digit - returns the number of digits in an integer for _printf
 * @c: integer to evalute
 * Return: number of digits
 */
int count_digit(int c)
{
	unsigned int d = 0;
	unsigned int u;

	if (c < 0)
		u = c * -1;
	else
		u = c;

	while (u != 0)
	{
		u /= 10;
		d++;
	}
	return (d);
}
