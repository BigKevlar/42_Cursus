/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:51:25 by jmartos-          #+#    #+#             */
/*   Updated: 2023/05/01 18:58:32 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include	<ctype.h> /*LIBRERIA PARA PROCESAMIENTO DE CARACTERES.*/
# include	<string.h> /*LIBRERIA PARA OPERACIONES DE MEMORIA (ft_strlen)*/
# include	<stdlib.h> /*LIBRERIA PARA GESTION DE MEMORIA (ft_bzero)*/

int		ft_isalpha(int x);
char	ft_toupper(char c);
int		ft_isdigit(int x);
char	ft_tolower(char c);
int		ft_isalnum(int x);
int		ft_isascii(int x);
int		ft_isprint(int x);
int		ft_strlen(const char *str);
void	ft_bzero(void *s, size_t n);

#endif