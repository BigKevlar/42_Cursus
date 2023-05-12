/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:51:25 by jmartos-          #+#    #+#             */
/*   Updated: 2023/05/12 14:12:28 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include	<ctype.h> /*LIBRERIA PARA PROCESAMIENTO DE CARACTERES.*/
# include	<string.h> /*LIBRERIA PARA OPERACIONES DE MEMORIA.*/
# include	<stdlib.h> /*LIBRERIA PARA GESTION DE MEMORIA.*/
# include	<stdio.h> /*LIBRERIA PARA EL PRINTF.*/

int		ft_isalpha(int x);
int		ft_isdigit(int x);
int		ft_isalnum(int x);
int		ft_isascii(int x);
int		ft_isprint(int x);
int		ft_strlen(const char *str);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dst_size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);

#endif