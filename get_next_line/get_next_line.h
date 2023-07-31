/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:32:15 by jmartos-          #+#    #+#             */
/*   Updated: 2023/07/31 17:12:59 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/* Libreria para usar "malloc" y "free". */
# include <stdlib.h>
/* Libreria para usar la palabra "null". */
# include <stdio.h>
/* Libreria para usar "O_RDONLY". */
# include <fcntl.h>
/* read??? */
# include <unistd.h>

char	*get_next_line(int fd);


#endif