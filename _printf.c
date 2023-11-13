#include "main.h"

/**
 * _printf - a function that produces output according to a format.
 * @format: format string parameter.
 * Description: a function that produces output according to a format,
 * it can handle format specifiers for strings,integers, characters etc.
 *
 * Return: the number of characters printed(count).
 */
int _printf(const char *format, ...);

int _printf(const char *format, ...)
{
	size_t itr;
	int count = 0;

	va_list arg_stor;

	va_start(arg_stor, format);
	for (itr = 0; itr < strlen(format); itr++)
	{
		while (*format)
		{
			if (format == NULL || *format == '\0')
			{
				va_end(arg_stor);
				return (count);
			}
			else if (*format == '%')
			{
				format++;
				if (*format == '%')
				{
					_putchar('%');
					count++;
				}
				else if (*format == 'c')
				{
					_putchar(va_arg(arg_stor, int));
					count++;
				}
				else if (*format == 's')
				{
					char *strg_cp = va_arg(arg_stor, char*);

					while (*strg_cp != '\0')
					{
						putchar(*strg_cp);
						count++;
						strg_cp++;
					}
				}
			}
			else
			{
				_putchar(*format);
				count++;
			}
			format++;
		}
	}

	va_end(arg_stor);

	return (count);
}
