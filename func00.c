#include "main.h"
/**
 *get_printf_fun - a function that takes format and returns
 *a function pointer.
 *@format: the format passed to the struct.
 *Return: function pointer.
 */
int (*get_printf_fun(const char *format))(va_list)
{
	unsigned int i;

	spec_t  fspec[] = {
		{"c", print_char},
		{"s", print_string},
		{"d", print_decimal},
		{"i", print_decimal},
		{NULL, NULL}
	};

	for (i = 0; fspec[i].specifier != NULL; i++)
	{
		if (*(fspec[i].specifier) == *format)
		break;
	}
	return (fspec[i].f);
}

#include "main.h"
/**
 * print_char - prints the character 'c' to stdout
 * @c: the character to be printed.
 * Return: 1 in succes and 0 in failure.
 */
int print_char(va_list c)
{
	int count = 0;

	if (c == NULL)
		return (-1);
	_putchar((char)va_arg(c, int));
	count++;

	return (count);
}
/**
 * print_string - prints a string.
 * @s: the string to be printed.
 * Return: the number of characters printed.
 */
int print_string(va_list s)
{
	char *str;
	int len;

	str = va_arg(s, char*);
	if (str == NULL)
	{
		str = "(null)";
		for (len = 0; str[len] != '\0'; len++)
			_putchar(str[len]);
		return (6);
	}
	for (len = 0; str[len] != '\0'; len++)
		_putchar(str[len]);
	return (len);
}

/**
 *print_decimal - it prints a decimal number.
 *@de: a list of stored decimal numbers to be printed.
 *Return:number of char printed.
 */
int print_decimal(va_list de)
{
	unsigned int count = 0;
	int num, num1;
	int units, digit = 0, j, dec;
	int len = 0;
	int num, num1, i;
	int units, digit = 0, j, dec;
	char intmin[11] = {"-2147483648"};

	num = va_arg(de, int);
	if (num == INT_MIN)
	{
		for (i = 0; i <= 10; i++)
		{
			_putchar(intmin[i]);
			len++;
		}
		return (len);
	}
	if (num < 0)
	{
		_putchar('-');
		num = -num;
		len++;
	}
	num1 = num;
	dec = 1;
	for (units = 1; num1 > 9; units++)
	{
		num1 /= 10;
		dec *= 10;
	}
	for (j = 1; j <= units; j++)
	{
		digit = num / dec;
		num %= dec;
		dec /= 10;
		_putchar(digit + '0');
		len++;
	}
	return (len);
}

/**
 * _putchar - writes the character c to stdout.
 * @c: The character to print.
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
