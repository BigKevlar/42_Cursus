/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:48:12 by jmartos-          #+#    #+#             */
/*   Updated: 2023/05/14 17:21:48 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h" /*LIBRERIA CUSTOM*/

/*
"dst" Y "src" TENDRAN SUS CONTADORES, PARA IR NAVEGANDO POR SUS POSICIONES.
EL PRIMER BUCLE MUEVE LA POSICION DE "dst" HASTA DONDE QUEREMOS EMPEZAR A
COPIAR LA CADENA "src".
(TENGO QUE SEGUIR DESARROLLANDO LA EXPLICACIOND E ESTA FUNCION...)
*/
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	pos_dst;
	size_t	pos_src;

	pos_dst = 0;
	pos_src = 0;
	while (dst[pos_dst] && pos_dst < size)
		pos_dst++;
	while (src[pos_src] && (pos_dst + pos_src + 1) < size)
	{
		dst[pos_dst + pos_src] = src[pos_src];
		pos_src++;
	}
	if (pos_dst < size)
		dst[pos_dst + pos_src] = '\0';
	return (pos_dst + ft_strlen(src));
}
/*
int main(void)
{
	char		dest[20];
	const char	*src = "Hola, mundo!";
	size_t		size = sizeof(dest);
	size_t		len = ft_strlcat(dest, src, size);

	printf("Cadena copiada: %s\n", dest);
	printf("Longitud de la cadena copiada: %zu\n", len);

	return (0);
}
*/
