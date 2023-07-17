/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing_hexnum.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:15:50 by jmartos-          #+#    #+#             */
/*   Updated: 2023/07/17 18:36:30 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft/libft.h" /*LIBRERIA CUSTOM "jmartos-"*/

/* Imprime numeros en base hexadecimal en minusculas o mayusculas (%x %X). */
int	ft_printing_hexnum(unsigned int n)
{
	int				len;
	unsigned int	n_len;

	len = 0;
	n_len = n;
	while (n_len != 0)
	{
		len++;
		n_len = n_len / 16;
	}
	return (len);
}
