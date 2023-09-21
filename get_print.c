#include "main.h"

/**
 * get_print - selects the right printing function
 * @e: character that holds the conversion specifier
 * Return: pointer to the matching print function
 */
int (*get_print(char e))(va_list, flags_t *, wid_t *, pre_dot *, len_t *)
{
	print_h func_arr[] = {
		{'i', print_integer},
		{'s', print_str},
		{'c', print_char},
		{'d', print_integer},
		{'u', print_unsigned_int},
		{'x', print_small_hexa},
		{'X', print_big_hexa},
		{'b', print_bin},
		{'o', print_octa},
		{'%', print_percent_sign},
		{'p', print_mem_address},
		{'S', print_nonprint_char},
		{'r', print_rev},
		{'R', print_rot13}
	};
	int flags = 14;

	int x;

	for (x = 0 ; x < flags ; x++)
		if (func_arr[x].c == e)
			return (func_arr[x].a);
	return (NULL);
}
