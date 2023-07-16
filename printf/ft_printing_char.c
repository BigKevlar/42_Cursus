/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:09:09 by jmartos-          #+#    #+#             */
/*   Updated: 2023/07/16 20:11:23 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h" /*funcion printf CUSTOM "jmartos-"*/

/* Imprime un solo caracter o simbolo (%c, %%). */
int	ft_printing_char(char c)
{
	if (c == '\0')
	{
		ft_putstr_fd("ERROR", 1);
		return (5);
	}
	ft_putchar_fd(c, 1);
	return (1);
}

/* DESARROLLO */
/* Esta subfuncion imprime un solo char por consola con nuestra
funcion del libft "ft_putchar_fd". Pimero verifica que el valor
introducido existe, retornando la frase "ERROR" con nuestra funcion
"ft_putstr_fd" y retornando 5 porque tiene esos bits. Si existe
imprime el caracter y retorna un valor numerico 1. Ojo, hay que tener en
cuenta que podemos entender como char una letra, numero o un simbolo. */