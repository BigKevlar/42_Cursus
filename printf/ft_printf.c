/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:33:40 by jmartos-          #+#    #+#             */
/*   Updated: 2023/07/08 17:44:32 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h" /*funcion printf CUSTOM "jmartos-"*/

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
			len += ft_printf_char(*input, types);
		}
		else
		{
			ft_print_char(*input);
			len++;
		}
		input++;
	}
	va_end(types)
	return(len);
}
