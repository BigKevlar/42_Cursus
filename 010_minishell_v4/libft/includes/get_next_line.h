/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:32:15 by jmartos-          #+#    #+#             */
/*   Updated: 2023/08/18 22:00:36 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/* Definimos y damos valor predeterminado a BUFFER_SIZE. */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/* Libreria para usar "malloc" y "free". */
# include <stdlib.h>
/* Libreria para usar "printf" (solo en el main de prueba). */
# include <stdio.h>
/* Libreria para usar "open" y: 0 "O_RDONLY", 1 "O_WRONLY", 2 "O_RDWR". */
# include <fcntl.h>
/* Libreria para usar "read", "write", "close". */
# include <unistd.h>

char	*get_next_line(int fd);
size_t	gnl_strlen(char *str);
char	*gnl_strchr(char *str, int chr);
char	*gnl_strjoin(char *str1, char *str2);
size_t	gnl_strlcpy(char *dst, const char *src, size_t dst_size);
char	*gnl_strdup(const char *str);

#endif