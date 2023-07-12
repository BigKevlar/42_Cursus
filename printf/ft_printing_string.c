/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:08:59 by jmartos-          #+#    #+#             */
/*   Updated: 2023/07/12 18:31:04 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft/libft.h" /*LIBRERIA CUSTOM "jmartos-"*/

/* Imprime una cadena de caracteres (%s). */
int	printing_string(char *s)
{
	int	len;

	len = 0;
	if (!s)
	{
		ft_putstr_fd("ERROR", 1);
		return (5);
	}
	while (s[len])
		len++;
	ft_putstr_fd(s, 1);
	return (len);
}

/* DESARROLLO */
/* Esta subfuncion imprime un string por consola con nuestra
funcion del libft "ft_putstr_fd". Pimero verifica que el valor
introducido existe, retornando la frase "ERROR" con nuestra funcion
"ft_putstr_fd" y retornando 5 porque tiene esos bits. Si existe
se realizan dos acciones: se recorre el string y guardamos el numero
de caracteres en "len" para devolverlos al final en return; y luego
si ya imprimimos el string. */