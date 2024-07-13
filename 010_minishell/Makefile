

NAME		= minishell

CFLAGS		= -Wall -Wextra -Werror

INC			= -I.

SRC			=	src/main.c \
				parser/init.c \
				parser/command.c \
				parser/quotes.c \
				parser/pipes_redirections.c \
				parser/parse.c \
				parser/parse_utils_1.c \
				parser/parse_utils_2.c \
				parser/env_var.c \
				parser/env_var_utils.c \
				parser/signal.c \
				executor/builtins/cd.c executor/utils.c executor/builtins/echo.c executor/builtins/env.c executor/builtins/exit.c executor/builtins/export.c executor/builtins/pwd.c executor/builtins/unset.c executor/execute.c executor/exec_ins.c executor/builtins.c

LIBFT		= libft/libft.a

OBJ			= $(SRC:.c=.o)

NO_COLOR	=\033[0m
BOLD		=\033[1m
RED			=\033[31;1m
GREEN		=\033[32;1m
YELLOW		=\033[33;1m
BLUE		=\033[34;1m

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@echo "$(YELLOW)Compiling $(NAME)...$(NO_COLOR)"
	@gcc $(CFLAGS) $(INC) $(OBJ) $(LIBFT) -o $(NAME) -lreadline > /dev/null
	@echo "$(GREEN)Compilation of $(NAME) done!$(NO_COLOR)"

libft/libft.a:
	@echo "$(YELLOW)Compiling libft...$(NO_COLOR)"
	@make -s all -C libft > /dev/null
	@echo "$(GREEN)Compilation of libft done!$(NO_COLOR)"

%.o: %.c
	@echo "$(YELLOW)Compiling $<...$(NO_COLOR)"
	@gcc $(CFLAGS) $(INC) -c $< -o $@ > /dev/null

clean:
	@echo "$(YELLOW)Cleaning objects...$(NO_COLOR)"
	@rm -f $(OBJ) > /dev/null
	@make clean -C libft > /dev/null
	@echo "$(GREEN)Cleaning done.$(NO_COLOR)"

fclean: clean
	@echo "$(YELLOW)Cleaning executable...$(NO_COLOR)"
	@rm -f $(NAME) > /dev/null
	@make fclean -C libft > /dev/null
	@echo "$(GREEN)Cleaning done.$(NO_COLOR)"

re: fclean all

.PHONY: all clean fclean re