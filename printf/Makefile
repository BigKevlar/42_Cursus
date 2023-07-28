# Nombre del programa.
NAME = libftprintf.a

# Ruta de "libft".
LIBFT_DIR = ./libft

# Libreria "libft" compilada.
LIBFT = $(LIBFT_DIR)/libft.a

# Variable: son los ficheros ".c" de nuestro "ft_printf" que queremos compilar para crear la nueva libreria.
FUNCTIONS = ft_printf.c \
				ft_printing_char.c \
				ft_printing_string.c \
				ft_printing_unsignum.c \
				ft_printing_signum.c \
				ft_printing_pointer.c \
				ft_printing_hexnum.c

# Variable: convierte todos los archivos ".c" de FUNCTIONS en ".o" (por optimizacion/velocidad).
OBJECTS = $(FUNCTIONS:.c=.o)

# Variable: compila.
CC = gcc

# Variable: flags para compilar.
FLAGS = -Wall -Werror -Wextra -c

# Variable: crea la libreria con la extension .h.
AR = ar rcs

# Regla: ejecuta el programa ("make"). Ojo: no hace falta compilar el bonus de nuestro libft.
# El flag "-C" permite no tener que andar pensando en que ruta estamos, salta automaticamente con "cd".
all: $(NAME)

$(NAME): $(OBJECTS)
	make -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJECTS)

$(OBJECTS): $(FUNCTIONS)
	$(CC) $(FLAGS) $(FUNCTIONS)

# Regla: borra los archivos temporales ".o" de ft_printf y de libft ("make clean").
clean:
	rm -f $(OBJECTS)
	make clean -C $(LIBFT_DIR)
	
# Regla: elimina absolutamente todos los archivos derivados del programa ("make clean").
fclean: clean
	rm -f $(NAME) $(LIBFT)
	
# Regla: elimina todo y vuelve a compilar automaticamente el programa ("make re").
re: fclean all

# ???¿¿¿
.PHONY: all clean fclean re bonus