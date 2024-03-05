NAME    		= push_swap
CFLAGS  		= -Wall -Wextra -Werror -g
SRC				= 	push_swap.c \
					error.c \
					
OBJ				= ${SRC:.c=.o}
LIBFT 			= libft/libft.a
INC 			= -I libft/includes
COLOUR_RED		=\033[0;31m
COLOUR_GREEN	=\033[0;32m
COLOUR_BLUE		=\033[0;34m
COLOUR_END		=\033[0m

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@gcc $(CFLAGS) $(OBJ) $(INC) -o $(NAME) $(LIBFT)
	@echo "$(COLOUR_GREEN)EVERYTHING COMPILED $(COLOUR_END)"

$(LIBFT):
	@make -C libft

clean:
	@rm -rf $(OBJ)
	@make -C libft/ clean
	@echo "$(COLOUR_RED)CLEAN PROTOCOL: DELETING .o FILES $(COLOUR_END)"
fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean
	@echo "$(COLOUR_RED)FCLEAN PROTOCOL: DELETING .a FILES $(COLOUR_END)"

re: fclean all
	@echo "$(COLOUR_BLUE)RECOMPILATION SUCCESSFULL $(COLOUR_END)"

.PHONY: all clean fclean re