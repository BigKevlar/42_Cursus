# Nombre del makefile
NAME = libft.a

# Variable, son los ficheros que queremos compilar
FUNCTIONS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

# Variable, compilar
CC = gcc

# Variable, flags para compilar
FLAGS = -Wall -Werror -Wextra

# Variable, crea la libreria con la extension .h
AR = ar rcs

# Variable, convierte todos los archivos .c en .o (son archivos temporales, por temas de optimizacion)
OBJECTS = $(FUNCTIONS:.c=.o)

# Regla, ejecuta el programa si solo ponemos "make" (debe de haber otro make y object aqui dentro para los bonus???)
all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)

$(OBJECTS): $(FUNCTIONS)
	$(CC) $(FLAGS) -c $(FUNCTIONS)
	
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