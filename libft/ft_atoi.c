/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:11:29 by jmartos-          #+#    #+#             */
/*   Updated: 2023/05/16 14:10:54 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h" /*LIBRERIA CUSTOM*/

/*
*/
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
