/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:51:25 by jmartos-          #+#    #+#             */
/*   Updated: 2024/07/23 13:38:35 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "ft_printf.h" // Funcion "ft_printf" jmartos-.
# include "get_next_line.h"// Funcion "get_next_line" jmartos-.
# include <ctype.h> // Operar con caracteres.
# include <string.h> // Manipular strings.
# include <stdlib.h> // Gestion de memoria para cadenas/arrays.
# include <stdio.h> // printf
# include <unistd.h> // write
# include <stddef.h> // size_t
# include <limits.h> // INT_MIN - INT_MAX.

/*
	Estructura con contenido y puntero, para listas enlazadas.
*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/**************************/
/* FUNCIONES OBLIGATORIAS */
/**************************/
int		ft_isalpha(int x);
int		ft_isdigit(int x);
int		ft_isalnum(int x);
int		ft_isascii(int x);
int		ft_isprint(int x);
size_t	ft_strlen(const char *s);
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
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
/*************************/
/* FUNCIONES ADICIONALES */
/*************************/
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
/*********/
/* BONUS */
/*********/
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
/**********************************/
/* FUNCIONES Y ESTRUCTURAS NUEVAS */
/**********************************/
// Comprobamos que se ha introducido un array de caracteres numericos.
int		ft_isdigit_str(char *str);
// Cuenta las palabras de un string usando un delimitador.
int		ft_word_counter(char const *s, char c);
// (minishell) Duplica un array bidimensional, similar a "ft_strdup".
char	**ft_matrixdup(char **matrix);
// (minishell) Calcula la longuitud en "str", desde "start" hasta encontrar "c".
int		ft_substrlen(char *str, int start, char chr);
// (minishell) Calcula la longitud de un array bidimensional.
int		ft_strd_len(char **str);
// (minishell) Libera un array bidimensional con seguridad.
void	ft_strd_free(char **str);
// (minishell)
char	**ft_strd_new(char *str);
// (minishell)Añadimos un string a la ultima posicion del array bidimensional.
char	**ft_strd_add(char **str, char *add);
// (minishell) Borramos el ultimo array de un array bidimensional.
char	**ft_strd_lastdel(char **str);
// (minishell) Compara ambos string hasta que coincidan o alguno termine.
int		ft_strcmp(const char *s1, const char *s2);
// (minishell) Igual que strdup pero le especificamos los que queremos copiar.
char	*ft_strndup(const char *s1, int n);
// (minishell) Introducimos un string dentro de otro en la posicion indicada.
char	*ft_insert_str(char *main, char *piece, size_t pos);
// (minishell) Borramos de un string desde start hasta finish.
char	*ft_delete_str(char *main, size_t start, size_t finish);

#endif