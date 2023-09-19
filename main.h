#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <stdarg.h>
#include <String.h>

/**
 * struct flags - struct conatining  formatting flags
 * @plus: flag for the '+' character
 * @space: flag for the ' ' character
 * @hash: flag for the '#' character
 * @zero: flag for the '0' character
 * @minus: flag for the '-' character
 * @width: filed width
 * @precision: precision
 * @length: length modifier (l or h)
 */
typedef struct flags
{
	int plus;
	int space;
	int hash;
	int zero;
	int minus;
	int width;
	int precision;
	char length;
} flags_t;

/**
 * struct printhandler - struct to map format specifiers
 * @c: format specificer passed to _print()
 * @a: pointer to the corresponding print function
 */
typedef struct printhandler
{
	char c;
	int (*a)(va_list ap, flags_t *a);
} print_h;

int print_integer(va_list b, flags_t *a);
void print_num(int x);
int print_unsigned_int(va_list b, flags_t *a);
int count_digit(int c);
int print_small_hexa(va_list b, flags_t *a);
int print_big_hexa(va_list b, flags_t *a);
int print_bin(va_list b, flags_t *a);
int print_octa(va_list b, flags_t *a);
char *convert(unsigned long int num, int base, int lowercase, flags_t *a);
int _printf(const char *format, ...);
int (*get_print(char e))(va_list, flags_t *);
int get_flag(char e, flags_t *a);
int print_str(va_list b, flags_t *a);
int print_char(va_list b, flags_t *a);
int _putchar(char c);
int _puts(char *str);
int print_rot13(va_list b, flags_t *a);
int print_rev(va_list b, flags_t *a);
int print_nonprint_char(va_list b, flags_t *a);
int print_mem_address(va_list b, flags_t *a);
int print_percent_sign(va_list b, flags_t *a);

#endif
