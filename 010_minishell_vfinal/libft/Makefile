# (Variable) Nombre de nuestra libreria precompilada.
NAME = libft.a

# (Variable) Funciones que queremos compilar en nuestra libreria.
FUNCTIONS = src/ft_isalpha.c src/ft_isdigit.c src/ft_isalnum.c src/ft_isascii.c src/ft_isprint.c src/ft_strlen.c \
			src/ft_memset.c src/ft_bzero.c src/ft_memcpy.c src/ft_memmove.c src/ft_strlcpy.c src/ft_strlcat.c \
			src/ft_toupper.c src/ft_tolower.c src/ft_strchr.c src/ft_strrchr.c src/ft_strncmp.c src/ft_memchr.c \
			src/ft_memcmp.c src/ft_strnstr.c src/ft_atoi.c src/ft_calloc.c src/ft_strdup.c src/ft_substr.c \
			src/ft_strjoin.c src/ft_strtrim.c src/ft_split.c src/ft_itoa.c src/ft_strmapi.c src/ft_striteri.c \
			src/ft_putchar_fd.c src/ft_putstr_fd.c src/ft_putendl_fd.c src/ft_putnbr_fd.c src/ft_lstnew_bonus.c \
			src/ft_lstadd_front_bonus.c src/ft_lstsize_bonus.c src/ft_lstlast_bonus.c src/ft_lstadd_back_bonus.c \
            src/ft_lstdelone_bonus.c src/ft_lstclear_bonus.c src/ft_lstiter_bonus.c src/ft_lstmap_bonus.c \
			src/ft_printf.c \
			src/ft_printing_char.c \
			src/ft_printing_string.c \
			src/ft_printing_unsignum.c \
			src/ft_printing_signum.c \
            src/ft_printing_pointer.c \
			src/ft_printing_hexnum.c \
			src/get_next_line.c \
			src/get_next_line_utils.c \
			src/ft_isdigit_str.c \
			src/ft_word_counter.c \
			src/ft_matrixdup.c \
			src/ft_substrlen.c \
			src/ft_strd_len.c \
			src/ft_strd_free.c \
			src/ft_strd_new.c \
			src/ft_strd_add.c \
			src/ft_strd_lastdel.c \
			src/ft_strcmp.c \
			src/ft_strndup.c \
			src/ft_insert_str.c \
			src/ft_delete_str.c 
			
# (Variable) Convierte todos los archivos ".c" de FUNCTIONS en ".o", por motivos de optimizacion.
OBJECTS = $(FUNCTIONS:.c=.o)

# (Variable) Flags para compilar.
FLAGS = -Wall -Werror -Wextra -c

# (Reglas) 
# Importante: las reglas se ejecutan de abajo hacia arriba y de derecha a izquierda.
all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS)

%.o: %.c
	@gcc $(FLAGS) -I includes -o $@ -c $<

clean:
	@rm -f $(OBJECTS)
	
fclean: clean
	@rm -f $(NAME)
	
re: fclean all

# Importante: las "reglas fónicas" sirven para decirle al programa que la prioridad
# en las ejecuciones con nombre x van antes que cualquier otra cosa con mismo nombre.
.PHONY: all clean fclean re
