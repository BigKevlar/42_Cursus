/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:33:40 by jmartos-          #+#    #+#             */
/*   Updated: 2024/03/21 18:26:21 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" /* Funcion printf CUSTOM "jmartos-". */

/*
Antes de la funcion principal vamos a hacer una subfuncion que nos
derivará a las demas subfunciones de fuera si encontrase los tipos
despues de aparecer el simbolo de %.
*/
int	checking_type(va_list args, char input)
{
	int	len;

	len = 0;
	if (input == '%')
		len = len + ft_printing_char('%');
	else if (input == 'c')
		len = len + ft_printing_char(va_arg(args, int));
	else if (input == 's')
		len = len + ft_printing_string(va_arg(args, char *));
	else if (input == 'p')
		len = len + ft_printing_pointer(va_arg(args, unsigned long));
	else if (input == 'd')
		len = len + ft_printing_signum(va_arg(args, int));
	else if (input == 'i')
		len = len + ft_printing_signum(va_arg(args, int));
	else if (input == 'u')
		len = len + ft_printing_unsignum(va_arg(args, unsigned int));
	else if (input == 'x')
		len = len + ft_printing_hexnum(va_arg(args, unsigned int), input);
	else if (input == 'X')
		len = len + ft_printing_hexnum(va_arg(args, unsigned int), input);
	return (len);
}

/* Esta es la funcion principal, donde usaremos todas nuestras subfunciones. */
int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		len;
	int		cont;

	va_start(args, input);
	len = 0;
	cont = 0;
	if (!input)
		return (0);
	while (input[cont])
	{
		if (input[cont] == '%')
		{
			cont++;
			len = len + checking_type(args, input[cont]);
		}
		else
			len = len + ft_printing_char(input[cont]);
		cont++;
	}
	va_end(args);
	return (len);
}

/* DESARROLLO */
/*
Funcion principal: lo primero es que crearemos dos variables:
una tipo int llamada "len" para contar nuestros pasos a traves de los
caracteres a retornar, y tambien una tipo lista (facilitada por la
libreria <stdarg.h>) llamada "va_list" que contendrá dos argumentos,
"args" y el propio "input", que nos permitira acceder a los parametros
siempre que se encuentre un simbolo % mediante la subfuncion, que navegara
en las funciones para devolver lo que necesitemos.
*/
/* MAIN DE PRUEBA, descomentar para usar. */
/*
int	main(void)
{
	ft_printf("%d", 0);
	return (0);
}
*/