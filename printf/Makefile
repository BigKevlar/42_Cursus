# Nombre del programa.
NAME = libftprintf.a

# Ruta de "libft".
LIBFT = ./libft

# Variable: son los ficheros .c que queremos compilar para crear la libreria.
FUNCTIONS = ft_printf.c \
				ft_printf_char.c \

# Variable: convierte todos los archivos .c de FUNCTIONS en .o (por optimizacion/velocidad).
OBJECTS = $(FUNCTIONS:.c=.o)

# Variable: compila.
CC = gcc

# Variable: flags para compilar.
FLAGS = -Wall -Werror -Wextra -c

# Variable: crea la libreria con la extension .h.
AR = ar rcs

# Regla: ejecuta el programa ("make").
all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)
	$(MAKE) -C $(LIBFT) all

$(OBJECTS): $(FUNCTIONS)
	$(CC) $(FLAGS) $(FUNCTIONS)
	
# Regla: borra los archivos temporales .o de las funciones y de libft ("make clean").
clean:
	rm -f $(OBJECTS)
	$(MAKE) -C $(LIBFT) clean
	
# Regla, elimina absolutamente todos los archivos derivados del programa ("make clean").
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT) fclean
	
# Regla, elimina todo y vuelve a compilar automaticamente el programa ("make re").
re: fclean all

# ???¿¿¿
.PHONY: all clean fclean re bonus