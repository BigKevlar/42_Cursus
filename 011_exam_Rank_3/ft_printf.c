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

#include <stdio.h>
#include <unistd.h> // write, malloc, free
#include <stdarg.h> // va_list, va_start, va_arg, va_copy, va_end

void	put_str(char *str, int *len)
{
	if (!str)
		str = "(null)";
	while (*str)
	{
		write(1, str, 1);
		str++;
		(*len++);
	}
}

void	put_num(long long int num, int base, int *len)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (num < 0)
	{
		num *= -1;
		write(1, "-", 1);
		(*len)++;
	}
	if (num >= base)
		put_num((num / base), base, len);
	write(1, &hex[num % base], 1);
	(*len)++;
}

int	ft_printf(const char *format, ...)
{
	va_list		pointer;
	int			len;

	va_start(pointer, format);
	len = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			if (*format == 's')
				put_str((char *)va_arg(pointer, char *), &len);
			else if (*format == 'd')
				put_num((long long int)va_arg(pointer, int), 10, &len);
			else if (*format == 'x')
				put_num((long long int)va_arg(pointer, unsigned int), 16, &len);
		}
		else
		{
			write(1, format, 1);
			len++;
		}
		format++;
	}
	return (va_end(pointer), len);
}

int	main(void)
{
	printf("ORIGINAL: %s\n", "toto");
	ft_printf("EXAM: %s\n", "toto");
	printf("ORIGINAL: Magic %s is %d\n", "number", 42);
	ft_printf("EXAM: Magic %s is %d\n", "number", 42);
	printf("ORIGINAL: Hexadecimal for %d is %x\n", 42, 42);
	ft_printf("ORIGINAL: Hexadecimal for %d is %x\n", 42, 42);
}
