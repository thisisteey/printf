#include "main.h"

/**
 * print_nonprint_char - prints non printable characters
 * @b: va_list argumnets from _printf
 * @a: pointer to the struct flags
 * Return: number of characters
 */
int print_nonprint_char(va_list b, flags_t *a)
{
	int x, count = 0;
	char *r;
	char *s = va_arg(b, char *);

	(void)a;
	if (!s)
		return (_puts("(null)"));

	for (x = 0 ; s[x] ; x++)
	{
		if (s[x] > 0 && (s[x] < 32 || s[x] >= 127))
		{
			_puts("\\x");
			count += 2;
			r = convert(s[x], 16, 0);
			if (!r[1])
				count += _putchar('0');
			count += _puts(r);
		}
		else
			count += _putchar(s[x]);
	}
	return (count);
}

/**
 * print_rev - prints a string in reverse
 * @b: argument from _printf
 * @a: pointer to the struct flags
 * Return: length of the printed string
 */
int print_rev(va_list b, flags_t *a)
{
	int x = 0, y;
	char *s = va_arg(b, char *);

	(void)a;
	if (!s)
		s = "(null)";

	while (s[x])
		x++;

	for (y = x - 1 ; y >= 0 ; y--)
		_putchar(s[y]);

	return (x);
}

/**
 * print_rot13 - prints a string using rot13
 * @b: list of arguments from _printf
 * @a: pointer to the struct flags
 * Return: length of the printed string
 */
int print_rot13(va_list b, flags_t *a)
{
	int x, y;
	char rot13[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char ROT13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *s = va_arg(b, char *);

	(void)a;

	for (y = 0; s[y]; y++)
	{
		if (s[y] < 'A' || (s[y] > 'Z' && s[y] < 'a') || s[y] > 'z')
			_putchar(s[y]);
		else
		{
			for (x = 0 ; x <= 52 ; x++)
			{
				if (s[y] == rot13[x])
					_putchar(ROT13[x]);
			}
		}
	}
	return (y);

}

/**
 * print_percent_sign - prints the percent sign
 * @b: va_list arguments from _printf
 * @a: pointer to the struct flags
 * Return: number of char printed
 */
int print_percent_sign(va_list b, flags_t *a)
{
	(void)b;
	(void)a;

	return (_putchar('%'));
}
