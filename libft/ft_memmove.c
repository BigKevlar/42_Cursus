/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:35:50 by jmartos-          #+#    #+#             */
/*   Updated: 2023/05/06 15:53:09 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h" /*LIBRERIA CUSTOM*/

/*ESTA FUNCION COPIA EN "SRC" LOS "N" DIGITOS EN "DST".*/
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*from;
	unsigned char	*to;

	from = (unsigned char *)src;
	to = (unsigned char *)dst;
	while (len)
	{
		*to = *from;
		to++;
		from++;
		len--;
	}
	return (dst);
}
/*EL "if" HACE QUE SI SON NULOS ALGUNO DE LOS DOS RETORNA 0.*/
/*LA PARTE DE "return (dst)" PERMITE DEVOLVER EL PUNTERO DESDE EL PRINCIPIO.*/