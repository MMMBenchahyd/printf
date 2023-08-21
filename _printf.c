#include "main.h"

/**
 *_printf - print c, s, %.
 * @format: format.
 * Return: Printed chars.
 */


int _printf(const char *format, ...)
{
	int printedchar = 0, j, i;
	char *charr;
	va_list ap;

	va_start(ap, format);
	for (i = 0; *format && format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			if (format[i] == 'c')
			{
				charr = va_arg(ap, char *);
				write(1, &charr, 1);
				printedchar++;
				i++;
			}
			if (format[i] == 's')
			{
				charr = va_arg(ap, char *);
				for (j = 0; charr[j] != '\0'; j++)
				{
					write(1, &charr[j], 1);
					printedchar++;
				}
			i++;
			}
		}
		write(1, &format[i], 1);
		printedchar++;
		va_end(ap);
	}
	return (printedchar);
}
