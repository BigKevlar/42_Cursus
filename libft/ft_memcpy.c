/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 13:51:56 by jmartos-          #+#    #+#             */
/*   Updated: 2023/05/06 15:58:37 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h" /*LIBRERIA CUSTOM*/

/*ESTA FUNCION COPIA EN "SRC" LOS "N" DIGITOS EN "DST", SIN SUPERPONERSE!!!*/
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*from;
	unsigned char	*to;

	from = (unsigned char *)src;
	to = (unsigned char *)dst;
	if (src == NULL && dst == NULL)
		return (0);
	while (n)
	{
		*to = *from;
		to++;
		from++;
		n--;
	}
	return (dst);
}
/*EL "if" HACE QUE SI SON NULOS ALGUNO DE LOS DOS RETORNA 0.*/
/*LA PARTE DE "return (dst)" PERMITE DEVOLVER EL PUNTERO DESDE EL PRINCIPIO.*/
