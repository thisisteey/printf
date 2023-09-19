#include "main.h"

/**
 * print_small_hexa - prints a number in hexadecimal base in lowercase
 * @b: variable arguments from _printf
 * @a: pointer to the struct flags
 * Return: the number of characters printed
 */
int print_small_hexa(va_list b, flags_t *a)
{
	unsigned int num = va_arg(b, unsigned int);
	char *str = convert(num, 16, 1, a);
	int count = 0;

	if (a->hash == 1 && str[0] != '0')
		count += _puts("0x");
	count += _puts(str);
	return (count);
}

/**
 * print_big_hexa - prints a number in hexadecimal base in uppercase
 * @b: variable arguments from _printf
 * @a: pointer to the struct flags
 * Return: the number of characters printed
 */
int print_big_hexa(va_list b, flags_t *a)
{
	unsigned int num = va_arg(b, unsigned int);
	char *str = convert(num, 16, 0, a);
	int count = 0;

	if (a->hash == 1 && str[0] != '0')
		count += _puts("0X");
	count += _puts(str);
	return (count);
}

/**
 * print_bin - prints a number in base 2, binary
 * @b: variable arguments from _printf
 * @a: pointer to the struct flags
 * Return: the number of characters printed
 */
int print_bin(va_list b, flags_t *a)
{
	unsigned int num = va_arg(b, unsigned int);
	char *str = convert(num, 2, 0, a);

	(void)a;

	return (_puts(str));
}

/**
 * print_octa - prints a number in base 8
 * @b: variable arguments from _printf
 * @a: pointer to the struct flag
 * Return: the number of characters printed
 */
int print_octa(va_list b, flags_t *a)
{
	unsigned int num = va_arg(b, unsigned int);
	char *str = convert(num, 8, 0, a);
	int count = 0;

	if (a->hash == 1 && str[0] != '0')
		count += _putchar('0');
	count += _puts(str);
	return (count);
}
