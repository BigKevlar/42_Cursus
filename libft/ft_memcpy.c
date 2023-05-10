/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 13:51:56 by jmartos-          #+#    #+#             */
/*   Updated: 2023/05/10 10:29:48 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h" /*LIBRERIA CUSTOM*/

/*ESTA FUNCION COPIA EN "SRC" LOS "N" DIGITOS EN "DST", SIN SUPERPONERSE!!!*/
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst1;
	unsigned char	*src1;

	dst1 = (unsigned char *)src;
	src1 = (unsigned char *)dst;
	if (src == NULL && dst == NULL)
		return (0);
	while (n)
	{
		*src1 = *dst1;
		src1++;
		dst1++;
		n--;
	}
	return (dst);
}
/*EL "if" HACE QUE SI SON NULOS ALGUNO DE LOS DOS RETORNA 0.*/
/*LA PARTE DE "return (dst)" PERMITE DEVOLVER EL PUNTERO DESDE EL PRINCIPIO.*/
