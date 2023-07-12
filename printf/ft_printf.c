/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:33:40 by jmartos-          #+#    #+#             */
/*   Updated: 2023/07/12 17:18:20 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h" /*funcion printf CUSTOM "jmartos-"*/

/* Antes de la funcion principal vamos a hacer una subfuncion que nos
derivará a las demas subfunciones de fuera si encontrase los tipos
despues de aparecer el simbolo de %. */
int	checking_type() /*!!!!!!!!!!!!!!!!*/
{
	int	len;

	len = 0;
	if (*input == 'c')
		len = len + ft_printing_char();
	else if (*input == 's')
		len = len + ft_printing_string();
	else if (*input == 'p')
		len = len + ft_printing_pointer();
	else if (*input == 'd')
		len = len + ft_printing_signum();
	else if (*input == 'i')
		len = len + ft_printing_signum();
	else if (*input == 'u')
		len = len + ft_printing_unsignum();
	else if (*input == 'x')
		len = len + ft_printing_hexnum();
	else if (*input == 'X')
		len = len + ft_printing_hexnum();
	return(len);
}

/* Esta es la funcion principal, donde usaremos todas nuestras subfunciones. */
int ft_printf(const char *input, ...)
{
	va_list	args;
	int		len;

	va_start(args, input);
	len = 0;
	if(!input)
		return (0);
	while(*input != '\0')
	{
		if(*input == '%')
		{
			input++;
			if (ft_strchr("cspdiuxX", *input))
				len = len + checking_type() /*!!!!!!!!!!!!!!!!*/
			else if (*input == '%')
				len = len + ft_printing_char('%');
		}
		else
			len = len + ft_printing_char(*input);
		input++;
	}
	va_end(args)
	return(len);
}

/* DESARROLLO */
/* Funcion principal. lo primero es que crearemos dos variables:
una tipo int llamada "len" para contar nuestros pasos a traves de los
caracteres a imprimir, y tambien una tipo lista (facilitada por la
libreria <stdarg.h>) llamada "va_list" que contendrá dos argumentos,
"args" y el propio "input", y nos servira mas adelante para */