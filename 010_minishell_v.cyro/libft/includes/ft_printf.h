/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:51:25 by jmartos-          #+#    #+#             */
/*   Updated: 2024/03/21 18:22:47 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* Libreria custom42 "jmartos-". */
# include "libft.h"
/*
Esta libreria ofrece macros y funciones utilizadas cuando no se sabe ni la
cantidad ni los tipos de argumento que se van a recibir por parametros,
representandose mediante "..." en los argumentos, y se y usa así:
"..." => argumentos de longitud variable pasado por parametros.
"va_list args" => es el tipado de la variable.
"va_start(args, input)" => inicializamos la variable con argumento e input.
"va_arg(args, input)" => se pone cuando vamos a usar esta variable.
"va_copy" =>
"va_end(args)" => se usa para cerrar la variable (libera memoria?).
*/
# include <stdarg.h>
/*
Esta libreria contiene, entre otras cosas, un tipado para variables
llamado "uintptr_t", que lo usaremos cuando se necesite tratar una
dirección de memoria como un valor entero sin signo o cuando necesitemos
guardar direcciones de memoria en variables.
"uintptr_t" => tipado para direcciones de memoria (entre otros).
*/
# include <stdint.h>

/* Vamos a incluir los prototipos de nuestras funciones. */
int	ft_printf(const char *input, ...);
int	ft_printing_char(int c);
int	ft_printing_string(char *s);
int	ft_printing_unsignum(unsigned int n);
int	ft_printing_signum(int n);
int	ft_printing_pointer(unsigned long p);
int	ft_printing_hexnum(unsigned int n, char type);

#endif