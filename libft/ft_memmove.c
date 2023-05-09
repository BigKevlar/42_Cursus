/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:35:50 by jmartos-          #+#    #+#             */
/*   Updated: 2023/05/09 15:57:53 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "libft.h" /*LIBRERIA CUSTOM*/

/*ESTA FUNCION COPIA "len" BYTES DE "src" EN "dst".*/
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*src1;
	char	*dst1;
	size_t	cont;

	src1 = (char *)src;
	dst1 = (char *)dst;
	cont = 0;
	if (dst1 > src1)
	{
		while (len > 0)
		{
			len--;
			dst1[len] = src1[len];
		}
	}
	else
	{
		while (cont < len)
		{
			dst1[cont] = src1[cont];
			cont++;
		}
	}
	return (dst1);
}
/*LA PARTE DE "return (dst)" PERMITE DEVOLVER EL PUNTERO/ARRAY AL PRINCIPIO.*/
/*
int main(void)
{
    char dst[] = "Caracola";
    char src[] = "Hola";

    printf("%s", ft_memmove(dst, src, 3));
    return (0);
}
*/
