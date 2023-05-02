/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:51:25 by jmartos-          #+#    #+#             */
/*   Updated: 2023/05/02 12:39:54 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include	<ctype.h> /*LIBRERIA PARA PROCESAMIENTO DE CARACTERES.*/
# include	<string.h> /*LIBRERIA PARA OPERACIONES DE MEMORIA.*/
# include	<stdlib.h> /*LIBRERIA PARA GESTION DE MEMORIA.*/
# include	<stdio.h> /*LIBRERIA PARA EL PRINTF.*/

int		ft_isalpha(int x);
int		ft_toupper(int c);
int		ft_isdigit(int x);
int		ft_tolower(int c);
int		ft_isalnum(int x);
char	*ft_strchr(const char *s, int c);
int		ft_isascii(int x);
int		ft_isprint(int x);
int		ft_strlen(const char *str);
void	ft_bzero(void *s, size_t n);

#endif