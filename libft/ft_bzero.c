/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:49:31 by jmartos-          #+#    #+#             */
/*   Updated: 2023/05/01 15:07:53 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h" /*LIBRERIA CUSTOM*/

/*ESTA FUNCION COPIA EL CARACTER "0" EN LAS PRIMERAS "N" POSICIONES.*/
void	ft_bzero(void *s, size_t n)
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