#ifndef MAIN_H
#define MAIN_H

#include <limits.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
/**
 * struct spec - struct for specifiers
 * @specifier: the specifier's character
 * @f: pointer to  associated function
 */

typedef struct spec
{
	char *specifier;
	int (*f)(va_list);
} spec_t;

int (*get_printf_fun(const char *format))(va_list);
int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list c);
int print_string(va_list s);
int print_decimal(va_list de);

#endif
