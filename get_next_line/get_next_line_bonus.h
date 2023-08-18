/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:32:15 by jmartos-          #+#    #+#             */
/*   Updated: 2023/08/18 17:45:57 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

char	*get_next_line(int fd);
size_t	gnl_strlen(char *s);
char	*gnl_strchr(char *str, int chr);
char	*gnl_strjoin(char *str1, char *str2);
size_t	gnl_strlcpy(char *dst, const char *src, size_t dst_size);
char	*gnl_strdup(const char *s1);

#endif