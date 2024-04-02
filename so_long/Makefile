NAME			= so_long
CFLAGS			= -Wall -Wextra -Werror -g
SRC				= so_long.c
OBJS			= ${SRC:.c=.o}
LIBFT_DIR		= ./libft
LIBFT			= ./libft/libft.a
MLX42_DIR		= ./MLX42
MLX42			= ./MLX42/./MLX42.a
C_YELLOW		=\033[0;33m
C_RED			=\033[0;31m
C_GREEN			=\033[0;32m
C_BLUE			=\033[0;34m
C_END			=\033[0m

$(NAME): $(OBJS)
	@echo "$(C_YELLOW)WELCOME TO "SO_LONG" PROYECT FROM JMARTOS- $(C_END)"
	@echo "$(C_YELLOW)CLONING MINILIBX_42 FROM CODAM-CODING-COLLEGE $(C_END)"
	@git clone https://github.com/codam-coding-college/MLX42.git MLX42
	@cd MLX42

	@echo "$(C_GREEN)EVERYTHING COMPILED $(C_END)"

all: $(NAME)

clean:
	@rm -rf $(OBJS)
	@make -C libft/ clean
	@echo "$(C_RED)CLEAN PROTOCOL: DELETING .o FILES... $(C_END)"

fclean: clean
	@rm -f $(NAME)
	@rm -rf MLX42
	@make -C libft/ fclean
	@echo "$(C_RED)FCLEAN PROTOCOL: DELETING .a FILES... $(C_END)"

re: fclean all
	@echo "$(C_BLUE)RE PROTOCOL: RECOMPILATION SUCCESSFULL $(C_END)"

.PHONY: all clean fclean re
