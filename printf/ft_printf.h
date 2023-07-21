/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:51:25 by jmartos-          #+#    #+#             */
/*   Updated: 2023/07/21 17:43:01 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* Libreria custom42 "jmartos-". */
# include	"./libft/libft.h"
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
# include    <stdarg.h>
/* Esta libreria contiene entre otras cosas un tipado para variables
llamado "uintptr_t", que lo usaremos cuando se necesite tratar una
dirección de memoria como un valor entero sin signo o cuando necesitemos
guardar direcciones de memoria en variables. */
# include    <stdint.h>

/* Vamos a incluir los prototipos de nuestras funciones. */
int	ft_printf(const char *input, ...);
int	ft_printing_char(char c);
int	ft_printing_string(char *s);
int	ft_printing_unsignum(unsigned int n);
int	ft_printing_signum(int n);
int	ft_printing_pointer(unsigned long p);
int	ft_printing_hexnum(unsigned int n, char type);

#endif