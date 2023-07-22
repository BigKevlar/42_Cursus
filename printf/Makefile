# Nombre del programa.
NAME = libftprintf.a

# Ruta de "libft".
LIBFT_DIR = ./libft

# Libft compilado.
LIBFT = $(LIBFT_DIR)/libft.a

# Variable: son los ficheros .c que queremos compilar para crear la libreria.
FUNCTIONS = ft_printf.c \
				ft_printing_char.c \
				ft_printing_string.c \
				ft_printing_unsignum.c \
				ft_printing_signum.c \
				ft_printing_pointer.c \
				ft_printing_hexnum.c

# Variable: convierte todos los archivos .c de FUNCTIONS en .o (por optimizacion/velocidad).
OBJECTS = $(FUNCTIONS:.c=.o)

# Variable: compila.
CC = gcc

# Variable: flags para compilar.
FLAGS = -Wall -Werror -Wextra -c

# Variable: crea la libreria con la extension .h.
AR = ar rcs

# Regla: ejecuta el programa ("make"). (NO HACE EL BONUS DE LIBFT???)
# El flag -C permite no tener que andar pensando en que ruta estamos, se salta con "cd".
# NOTA: -I includes -c $< -o $@
all: $(NAME)

$(NAME): $(OBJECTS)
	make -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJECTS)

$(OBJECTS): $(FUNCTIONS)
	$(CC) $(FLAGS) -I includes -c $< -o $@

# Regla: borra los archivos temporales .o de las funciones y de libft ("make clean").
clean:
	rm -f $(OBJECTS)
	make clean -C $(LIBFT_DIR)
	
# Regla, elimina absolutamente todos los archivos derivados del programa ("make clean").
fclean: clean
	rm -f $(NAME) $(LIBFT)
	
# Regla, elimina todo y vuelve a compilar automaticamente el programa ("make re").
re: fclean all

# ???¿¿¿
.PHONY: all clean fclean re bonus