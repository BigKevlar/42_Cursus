# Nombre del makefile
NAME = libftprintf.a

# Variable, son los ficheros que queremos compilar
FUNCTIONS = 

# Variable, convierte todos los archivos .c de FUNCTIONS en .o (por optimizacion)
OBJECTS = $(FUNCTIONS:.c=.o)

# Variable, compilar
CC = gcc

# Variable, flags para compilar
FLAGS = -Wall -Werror -Wextra -c

# Variable, crea la libreria con la extension .h
AR = ar rcs

# Regla, ejecuta el programa si solo ponemos "make"
all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)

$(OBJECTS): $(FUNCTIONS)
	$(CC) $(FLAGS) $(FUNCTIONS)
	
# Regla, borra los archivos temporales .o de las funciones y las bonus
clean:
	rm -f $(OBJECTS)
	
# Regla, elimina absolutamente todos los archivos derivados del programa
fclean: clean
	rm -f $(NAME)
	
# Regla, elimina todo y vuelve a compilar automaticamente el programa
re: fclean all

# ???¿¿¿
.PHONY: all clean fclean re bonus