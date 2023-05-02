# Nombre del makefile
NAME = libft.a

# Variable, son los ficheros que queremos compilar
FUNCTIONS = ft_isalpha.c ft_toupper.c ft_isdigit.c ft_tolower.c ft_isalnum.c ft_strchr.c ft_isascii.c ft_isprint.c ft_strlen.c ft_bzero.c

# Variable, compilar
CC = gcc

# Variable, flags para compilar
FLAGS = -Wall -Werror -Wextra

# Variable, crea la libreria con la extension .h
AR = ar rcs

# Variable, convierte todos los archivos .c en .o (son archivos temporales, por temas de optimizacion)
OBJECTS = $(FUNCTIONS:.c=.o)

# Regla, ejecuta el programa si solo ponemos "make"
all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)
	
# Regla, borra los archivos temporales .o
clean:
	rm -f $(OBJECTS)
	
# Regla, elimina absolutamente todos los archivos derivados del programa
fclean: clean
	rm -f $(NAME)
	
# Regla, elimina todo y vuelve a compilar automaticamente el programa
re: fclean all

# ???¿¿¿
.PHONY: re all fclean clean