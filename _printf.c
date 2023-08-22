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
	int numbr;
	va_list ap;

	va_start(ap, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	for (i = 0; *format && format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] != 'c' && format[i] != 's' && format[i] != '%' && 
				format[i] != 'd' && format[i] != 'i')
			{
				write(2, "%", 1);
				write(1, &format[i], 1);
				printedchar++;
				i++;
			}
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
			if (format[i] == 'd' || format[i] == 'i')
			{
				numbr = va_arg(ap, int);
				{
					printedchar += printnumbr(numbr);
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
