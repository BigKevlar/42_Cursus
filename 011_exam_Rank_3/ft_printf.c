/*
    Assignment name  : ft_printf
    Expected files   : ft_printf.c
    Allowed functions: malloc, free, write, va_start, va_arg, va_copy, va_end
    --------------------------------------------------------------------------------

    Write a function named `ft_printf` that will mimic the real printf but
    it will manage only the following conversions: s,d and x.

    Your function must be declared as follows:

    int ft_printf(const char *, ... );

    Before you start we advise you to read the `man 3 printf` and the `man va_arg`.
    To test your program compare your results with the true printf.

    Exemples of the function output:

    call: ft_printf("%s\n", "toto");
    out: toto$

    call: ft_printf("Magic %s is %d", "number", 42);
    out: Magic number is 42%

    call: ft_printf("Hexadecimal for %d is %x\n", 42, 42);
    out: Hexadecimal for 42 is 2a$
*/

#include <unistd.h> // write, malloc, free
#include <stdarg.h> // va_list, va_start, va_arg, va_copy, va_end

void	put_str(char *string, int *lenght)
{
	if (!string)
		string = "(null)";
	while (*string)
		*lenght += write(1, string++, 1);
}

void	put_digit(long long int number, int base, int *lenght)
{
	char	*hex = "0123456789abcdef";

	if (number < 0)
	{
		number *= -1;
		*lenght += write(1, "-", 1);
	}
	if (number >= base)
		put_digit((number / base), base, lenght);
	*lenght += write(1, &hex[number % base], 1);
}

int	ft_printf(const char *format, ...)
{
	va_list		pointer;
	int			lenght;

	va_start(pointer, format);
	lenght = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			if (*format == 's')
				put_str(va_arg(pointer, char *), &lenght);
			else if (*format == 'd')
				put_digit((long long int)va_arg(pointer, int), 10, &lenght);
			else if (*format == 'x')
				put_digit((long long int)va_arg(pointer, unsigned int), 16, &lenght);
		}
		else
			lenght += write(1, format, 1);
		format++;
	}
	return (va_end(pointer), lenght);
}
