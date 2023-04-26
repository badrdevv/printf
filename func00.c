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

