/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:11:29 by jmartos-          #+#    #+#             */
/*   Updated: 2023/06/01 14:54:46 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h" /*LIBRERIA CUSTOM "jmartos-"*/

/*#Convierte la cadena "str", la analiza y la convierte en un valor entero
(atoi = ASCII to Integer) hasta que encuentre algun caracter no numerico.#*/
int	ft_atoi(const char *str)
{
	int	cont;
	int	num;
	int	aux;

	cont = 0;
	num = 0;
	aux = 1;
	while (str[cont] == ' ' || str[cont] == '\t'
		|| str[cont] == '\v' || str[cont] == '\f'
		|| str[cont] == '\n' || str[cont] == '\r')
		cont++;
	if (str[cont] == '+' || str[cont] == '-')
	{	
		if (str[cont] == '-')
			aux *= -1;
		cont++;
	}
	while (str[cont] >= '0' && str[cont] <= '9' && str[cont] != '\0')
	{
		num = num * 10 + ((int)str[cont] - '0');
		cont++;
	}
	return (num * aux);
}

/*
int main(void)
{
	const char	*str;
	int			result;

	str = "76874063-J";
	result = ft_atoi(str);
	printf("El resultado de atoi es: %d\n", result);
	return (0);
}
*/