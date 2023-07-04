/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:53:18 by jmartos-          #+#    #+#             */
/*   Updated: 2023/05/30 11:50:19 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h" /*LIBRERIA CUSTOM "jmartos-"*/

/*#Convierte un caracer alfabetico de mayuscula a minuscula.#*/
int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
	{
		c += 32;
	}
	return (c);
}

/*
int main(void)
{
	char	word = 'A';
	char	result = ft_tolower(word);

	printf("Carácter original: %c\n", word);
	printf("Carácter convertido: %c\n", result);
	return 0;
}
*/