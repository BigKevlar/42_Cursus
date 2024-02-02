# Nombre del programa.
NAME = push_swap.a

# Ruta de nuestra "libft".
LIBFT_DIR = ./libft

# Programa "libft.a" compilado.
LIBFT = ./libft/libft.a

# Variable: son las funciones exclusivas de nuestro programa "push_swap" para compilar su nueva libreria.
FUNCTIONS = stack_functions_1.c /
			

# Variable: convierte todos los archivos ".c" de FUNCTIONS en ".o" (por optimizacion/velocidad).
OBJECTS = $(FUNCTIONS:.c=.o)

# Regla ("make"): ejecuta el programa.
all: $(NAME)

$(NAME): $(OBJECTS)
	make -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJECTS)

$(OBJECTS): $(FUNCTIONS)
	gcc -Wall -Werror -Wextra -c $(FUNCTIONS) 

# Regla ("make clean"): borra los archivos temporales ".o" de push_swap, y hace "make clean" de libft.
clean:
	rm -f $(OBJECTS)
	make clean -C $(LIBFT)
	
# Regla ("make fclean"): elimina absolutamente todos los archivos derivados del programa.
fclean: clean
	rm -f $(NAME) $(LIBFT_DIR)
	
# Regla ("make re"): elimina todo y vuelve a compilar automaticamente el programa.
re: fclean all

# ???¿¿¿
.PHONY: all clean fclean re bonus