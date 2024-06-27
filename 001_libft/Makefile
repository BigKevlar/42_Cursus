# (Variable) Nombre del programa de este Makefile.
NAME = libft.a

# (Variable) Funciones que queremos compilar en nuestro programa.
FUNCTIONS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
			ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
			ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
			ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
			ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

# (Variable) Lo mismo que la anterior, pero para el bonus.
FUNCTIONS_BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
					ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

# (Variable) Convierte todos los archivos ".c" de FUNCTIONS en ".o", por motivos de optimizacion.
OBJECTS = $(FUNCTIONS:.c=.o)

# (Variable) Lo mismo que la anterior pero para el bonus.
OBJECTS_BONUS = $(FUNCTIONS_BONUS:.c=.o)

# (Variable) Comando para compilar.
CC = gcc

# (Variable) Flags para compilar.
FLAGS = -Wall -Werror -Wextra -c

# (Variable) Comando para crear la libreria con la extension ".h" a partir de un ".a".
AR = ar rcs

# (Regla) Ejecuta el programa si escribimos "make" en la consola.
# Importante: las reglas se ejecutan de abajo hacia arriba y de derecha a izquierda.
all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)

$(OBJECTS): $(FUNCTIONS)
	$(CC) $(FLAGS) $(FUNCTIONS)
	
# (Regla) Borra los archivos temporales ".o" de las funciones y los del bonus.
clean:
	rm -f $(OBJECTS) $(OBJECTS_BONUS)
	
# (Regla) Elimina absolutamente todos los archivos derivados del programa.
fclean: clean
	rm -f $(NAME)
	
# (Regla) Igual que la anterior regla, pero ademas vuelve a compilar automaticamente el programa.
re: fclean all

# (Regla) Ejecuta el programa y la parte bonus.
bonus: $(OBJECTS) $(OBJECTS_BONUS)
	$(AR) $(NAME) $(OBJECTS) $(OBJECTS_BONUS)

# ???¿¿¿
.PHONY: all clean fclean re bonus