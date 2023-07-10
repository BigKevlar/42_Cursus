/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:33:40 by jmartos-          #+#    #+#             */
/*   Updated: 2023/07/10 19:07:57 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h" /*funcion printf CUSTOM "jmartos-"*/

/* Antes de la funcion principal vamos a hacer una subfuncion que nos
derivará a las demas subfunciones de fuera si encontrase los tipos
despues de aparecer el simbolo de %. */
int	checking_type()
{
	
}

/* Esta es la funcion principal, donde usaremos todas nuestras subfunciones. */
int ft_printf(const char *input, ...)
{
	va_list	types;
	int		len;

	va_start(types, input);
	len = 0;
	if(!input)
		return (0);
	while(*input != '\0')
	{
		if(*input == '%')
		{
			input++;
			if (ft_strchr("cspdiuxX", *input))
				len = len + checking_type()
			else if (*input == '%')
				len = len + ft_print_char(*input);
		}
		else
			len = len + ft_print_char(*input);
		input++;
	}
	va_end(types)
	return(len);
}
