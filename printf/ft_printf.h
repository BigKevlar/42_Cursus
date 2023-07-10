/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:51:25 by jmartos-          #+#    #+#             */
/*   Updated: 2023/07/10 18:23:49 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* Libreria custom42 "jmartos-". */
#include	"libft/libft.h"
/*
Esta libreria ofrece macros y funciones utilizadas cuando no se sabe la
cantidad ni tipos de argumentos que se van a recibir por parametros,
representandose mediante "..." y se declara y usa con:
"va_list" =>
"va_start"=> 
"va_arg" =>
"va_copy" =>
"va_end" =>
*/
#include    <stdarg.h>

/* Vamos a incluir los prototipos de nuestras funciones. */
int	ft_printf(const char *input, ...);
int	ft_printf_char(char c);

#endif