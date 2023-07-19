/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:33:40 by jmartos-          #+#    #+#             */
/*   Updated: 2023/07/19 14:47:58 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h" /*funcion printf CUSTOM "jmartos-"*/

/* Antes de la funcion principal vamos a hacer una subfuncion que nos
derivará a las demas subfunciones de fuera si encontrase los tipos
despues de aparecer el simbolo de %. */
/* (... => void *arg) */
int	checking_type(va_list args, char *input)
{
	int	len;

	len = 0;
	if (*input == 'c')
		len = len + ft_printing_char(va_arg(args, char));
	else if (*input == 's')
		len = len + ft_printing_string(va_arg(args, char *));
	else if (*input == 'p')
		len = len + ft_printing_pointer();
	else if (*input == 'd')
		len = len + ft_printing_signum(va_arg(args, int));
	else if (*input == 'i')
		len = len + ft_printing_signum(va_arg(args, int));
	else if (*input == 'u')
		len = len + ft_printing_unsignum(va_arg(args, unsigned int));
	else if (*input == 'x')
		len = len + ft_printing_hexnum();
	else if (*input == 'X')
		len = len + ft_printing_hexnum();
	else if (*input == '%')
		len = len + ft_printing_char('%');
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
			if (ft_strchr("cspdiuxX", input[cont]))
				len = len + checking_type(va_arg(args, void *), *input);
		}
		else
			len = len + ft_printing_char(input[cont]);
		cont++;
	}
	va_end(args);
	return (len);
}

/*MAIN DE PRUEBA (cuidadin!, hay que descomentarlo para probar la funcion)*/
/* . */
/* DESARROLLO */
/* Funcion principal. lo primero es que crearemos dos variables:
una tipo int llamada "len" para contar nuestros pasos a traves de los
caracteres a imprimir, y tambien una tipo lista (facilitada por la
libreria <stdarg.h>) llamada "va_list" que contendrá dos argumentos,
"args" y el propio "input", y nos servira mas adelante para */