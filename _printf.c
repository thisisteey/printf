#include "main.h"

/**
 * _printf - function to print formatted output
 * @format: string pointer containing characters
 * @...: variable arguments lists for more arguments
 * Return: total number of characters printed
 */
int _printf(const char *format, ...)
{
	int (*pfunc)(va_list, flags_t *, wid_t *, pre_dot *, len_t *);
	const char *s;
	va_list args;
	flags_t flags = {0, 0, 0, 0, 0}, wid_t width = {0};
	pre_dot precision = {0}, len_t length = {0, 0};
	int count = 0;

	va_start(args, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (s = format ; *s ; s++)
	{
		if (*s == '%')
		{
			s++;
			if (*s == '%')
			{
				count += _putchar('%');
				continue;
			}
			while (get_flag(*s, &flags, &width, &precision, &length))
				s++;
			while (get_width(*s, &flags, &width, &precision, &length))
				s++;
			while (get_precision(*s, &flags, &width, &precision, &length))
				s++;
			while (get_length(*s, &flags, &width, &precision, &length))
				s++;
			pfunc = get_print(*s);
			count += (pfunc)
				? pfunc(args, &flags, &width, &precision, &length) : _printf("%%%c", *s);
		}
		else
			count += _putchar(*s);
	}
	_putchar(-1);
	va_end(args);
	return (count);
}
