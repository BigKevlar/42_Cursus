/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:32:15 by jmartos-          #+#    #+#             */
/*   Updated: 2023/08/03 17:02:05 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* if (fd > 0 && BUFFER_SIZE > 0 && read(fd, NULL, 0) >= 0) */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/* Valor predeterminado de buffer. */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4242
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

#endif