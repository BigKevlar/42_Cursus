/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:25:03 by jmartos-          #+#    #+#             */
/*   Updated: 2023/05/01 15:22:40 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h" /*LIBRERIA CUSTOM*/

/*ESTA FUNCION COPIA EN "STR" EL CARACTER "C" EN LAS PRIMERAS "N" POSICIONES.*/
void	*memset(void *b, int c, size_t len);
{
	unsigned char	*str;
	int				i;

	str = (unsigned char *)s;
	i = 0;
	if (n == 0)
		return ;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
	return ;
}

/*
int main ()
{
	unsigned char	*phrase;

	phrase = "FundacionTelefonica";
	printf(phrase);
	printf(ft_bzero(phrase, 7));
	return (0);
}
*/