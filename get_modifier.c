#include "main.h"

/**
 * get_flag - function flag for non-custom specifier
 * @e: character that holds the flag specifier
 * @a: pointer to the struct flags
 * @f: pointer to the struct width
 * @d: pointer to the struct precision
 * @c: pointer to the struct length
 * Return: 1 on code success
 */
int get_flag(char e, flags_t *a, wid_t *f, pre_dot *d, len_t *c)
{
	(void)f;
	(void)d;
	(void)c;

	switch (e)
	{
		case '+':
			a->plus = 1;
			break;
		case ' ':
			a->space = 1;
			break;
		case '#':
			a->hash = 1;
			break;
		case '-':
			a->minus = 1;
			break;
		case '0':
			a->zero = 1;
			break;
	}
	return (1);
}

/**
 * get_width - function width for non-custom specifiers
 * @e: character that hiolds the width modifier
 * @a: pointer to the struct flag
 * @f: pointer to the struct width
 * @d: pointer to the struct precision
 * @c: pointer to the struct length
 * Return: 1 on code success
 */
int get_width(char e, flags_t *a, wid_t *f, pre_dot *d, len_t *c)
{
	(void)a;
	(void)d;
	(void)c;

	switch (e)
	{
		case '^':
			f->nom = 1;
			break;
	}
	return (1);
}

/**
 * get_precision - function precision for non-custom specifiers
 * @e: character that holds the precision modifiers
 * @a: pointer to the struct flag
 * @f: pointer to the struct width
 * @d: pointer to the struct precision
 * @c: pointer to the struct length
 * Return: 1 on code success
 */
int get_precision(char e, flags_t *a, wid_t *f, pre_dot *d, len_t *c)
{
	(void)a;
	(void)f;
	(void)c;

	switch (e)
	{
		case '.':
			d->dot = 1;
			break;
	}
	return (1);
}

/**
 * get_length - function length for non-custom specifiers
 * @e: character that holds the length modifiers
 * @a: pointer to the struct flag
 * @f: pointer to the struct width
 * @d: pointer to the struct precision
 * @c: pointer to the struct length
 * Return: 1 on code success
 */
int get_length(char e, flags_t *a, wid_t *f, pre_dot *d, len_t *c)
{
	(void)a;
	(void)f;
	(void)d;

	switch (e)
	{
		case 'l':
			c->lon = 1;
			break;
		case 'h':
			c->sho = 1;
			break;
	}
	return (1);
}
