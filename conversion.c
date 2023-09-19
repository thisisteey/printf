#include "main.h"

/**
 * convert - converts number and base into string
 * @num: input number
 * @base: input base
 * @lowercase: flag if hexa values need to be lowercase
 * @a: pointer to flag_t structure containing formatting flags
 * Return: return pointer to the string
 */
char *convert(unsigned long int num, int base, int lowercase, flags_t *a)
{
	static char *rep;
	static char buffer[50];
	char *ptr;

	rep = (lowercase)
		? "0123456789abcdef"
		: "0123456789ABCDEF";

	ptr = &buffer[49];

	*ptr = '\0';

	do {
		*--ptr = rep[num % base];
		num /= base;
	} while (num != 0);

	if (a->precision > 0)
	{
		int padding = a->precision - (int)(strlen(ptr));

		while (padding > 0)
		{
			*--ptr = '0';
			padding--;
		}
	}

	return (ptr);
}
