#include "main.h"

/**
 * get_flag - function flag for non-custom specifiers
 * @e: character that holds the flag specifier
 * @a: pointer to the struct flags
 * Return: 1 on code success
 */
int get_flag(char e, flags_t *a)
{
	int i = 0;

	switch (e)
	{
		case '+':
			a->plus = 1;
			i = 1;
			break;
		case ' ':
			a->space = 1;
			i = 1;
			break;
		case '#':
			a->hash = 1;
			i = 1;
			break;
	}
	return (i);
}
