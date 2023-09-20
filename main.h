#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * struct flags - struct conatining  formatting flags
 * @plus: flag for the '+' character
 * @space: flag for the ' ' character
 * @hash: flag for the '#' character
 * @minus: flag for the '-' character
 * @zero: flag for the '0' character
 */
typedef struct flags
{
	int plus;
	int space;
	int hash;
	int minus;
	int zero;
} flags_t;

/**
 * struct width - struct width containing width modifier
 * @nom: width modifier for '^'
 */
typedef struct width
{
	int nom;
} wid_t;

/**
 * struct precision - struct containing precision modifier
 @dot: precision modifier for '.'
 */
typedef struct precision
{
	int dot;
} pre_dot;

/**
 * struct length - struct containing length modifiers
 * @lon: length modifier for 'l' modifier
 * @sho: length modifier for 'h' modifier
 */
typedef struct length
{
        int lon;
        int sho;
} len_t;

/**
 * struct printhandler - struct to map format specifiers
 * @c: format specificer passed to _print()
 * @a: pointer to the corresponding print function
 */
typedef struct printhandler
{
	char c;
	int (*a)(va_list ap, flags_t *a, wid_t *f, pre_dot *d, len_t *c);
} print_h;


int print_integer(va_list b, flags_t *a, wid_t *f, pre_dot *d,len_t *c);
void print_num(int x);
int print_unsigned_int(va_list b, flags_t *a, wid_t *f, pre_dot *d, len_t *c);
int count_digit(int c);

int print_small_hexa(va_list b, flags_t *a, wid_t *f, pre_dot *d, len_t *c);
int print_big_hexa(va_list b, flags_t *a, wid_t *f, pre_dot *d, len_t *c);
int print_bin(va_list b, flags_t *a, wid_t *f, pre_dot *d, len_t *c);
int print_octa(va_list b, flags_t *a, wid_t *f, pre_dot *d, len_t *c);

char *convert(unsigned long int num, int base, int lowercase, flags_t *a, wid_t *f, pre_dot *d, len_t *c);

int _printf(const char *format, ...);
int (*get_print(char e))(va_list, flags_t *, wid_t *f, pre_dot *d, len_t *c);
int get_flag(char e, flags_t *a, wid_t *f, pre_dot *d, len_t *c);
int get_width(char e, flags_t *a, wid_t *f, pre_dot *d, len_t *c);
int get_precision(char e, flags_t *a, wid_t *f, pre_dot *d, len_t *c);
int get_length(char e, flags_t *a, wid_t *f, pre_dot *d, len_t *c);

int print_str(va_list b, flags_t *a, wid_t *f, pre_dot *d, len_t *c);
int print_char(va_list b, flags_t *a, wid_t *f, pre_dot *d, len_t *c);

int _putchar(char c);
int _puts(char *str);

int print_rot13(va_list b, flags_t *a, wid_t *f, pre_dot *d, len_t *c);
int print_rev(va_list b, flags_t *a, wid_t *f, pre_dot *d, len_t *c);
int print_nonprint_char(va_list b, flags_t *a, wid_t *f, pre_dot *d, len_t *c);

int print_mem_address(va_list b, flags_t *a, wid_t *f, pre_dot *d, len_t *c);
int print_percent_sign(va_list b, flags_t *a, wid_t *f, pre_dot *d, len_t *c);

#endif
