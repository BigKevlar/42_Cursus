/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:09:09 by jmartos-          #+#    #+#             */
/*   Updated: 2023/07/10 18:23:52 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h" /*funcion printf CUSTOM "jmartos-"*/

/* Imprime un solo caracter o simbolo (%c, %%). */
char	ft_print_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

/* DESARROLLO */
/* Usaremos esta subfuncion para imprimir un valor tipo char por
consola, y retornar un valor numerico 1 en return. Ojo, hay que tener en
cuenta que podemos entender como char una letra, numero o un simbolo. */