#include "main.h"

/**
 * convert - converts number and base to string
 * @num: input number
 * @base: input base
 * @lowercase: flag if hexa values need to be lowercase
 * @a: pointer to the struct flags
 * @f: pointer to the struct width
 * @d: pointer to the struct precision
 * @c: pointer to the struct length
 * Return: return pointer to the string
 */
char *convert(unsigned long int num, int base, int lowercase,
		flags_t *a, wid_t *f, pre_dot *d, len_t *c)
{
	static char *rep;
	static char buffer[1024];
	char *ptr;

	(void)a;
	(void)f;
	(void)d;
	(void)c;

	rep = (lowercase)
		? "0123456789abcdef"
		: "0123456789ABCDEF";

	ptr = &buffer[1023];

	*ptr = '\0';

	do {
		*--ptr = rep[num % base];
		num /= base;
	} while (num != 0);

	return (ptr);
}
