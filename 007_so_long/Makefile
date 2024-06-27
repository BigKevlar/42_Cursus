# leaks --atExit -- ./so_long maps/subject_map.ber
# export MallocStackLogging=1
# unset MallocStackLogging

NAME			= so_long

CFLAGS			= -Wall -Wextra -Werror -g

INC				= -I include -I libft/include -I MLX42/include/MLX42

SRC				=	src/so_long.c \
					src/error.c \
					src/free.c \
					src/sintax.c \
					src/map.c \
					src/game.c \
					src/images.c \
					src/draw.c \
					src/flood_fill.c \
					src/movements.c \
					src/movements_utils.c

OBJS 			= ${SRC:.c=.o}

LIBFT			= ./libft/libft.a

MLX42			= ./MLX42/libmlx42.a

BOLD			=\033[1m
RED				=\033[31;1m
GREEN			=\033[32;1m
YELLOW			=\033[33;1m
BLUE			=\033[34;1m
END				=\033[0m

${NAME}: ${LIBFT} ${MLX42} ${OBJS}
	@echo "${GREEN}${BOLD} GAME SUCCESSFULLY COMPILED ${END}"
	@gcc $(CFLAGS) $(OBJS) $(MLX42) $(LIBFT) -Iinclude -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/" -o $(NAME)
	@echo "${BLUE}${BOLD} WELCOME TO "SO_LONG" 42_MALAGA PROYECT FROM JMARTOS- ${END}"

${LIBFT}:
	@echo "${YELLOW}${BOLD} BUILDING LIBFT FROM JMARTOS-, PLEASE BE PATIENT... ${END}"
	@make -C libft/ --silent
	@echo "${GREEN}${BOLD} LIBFT COMPILED ${END}"

${MLX42}:
	@echo "${YELLOW}${BOLD} BUILDING MINILIBX FROM CODAM-CODING-COLLEGE, PLEASE BE PATIENT... ${END}"
	@make -C MLX42/ --silent
	@echo "${GREEN}${BOLD} MINILIBX_42 COMPILED ${END}"

%.o: %.c
	@gcc ${CFLAGS} ${INC} -c $< -o src/$(@F)

all: ${NAME}

clean:
	@rm -rf ${OBJS}
	@make -C libft/ clean
	@make -C MLX42/ clean
	@echo "${RED}${BOLD} CLEAN PROTOCOL: DELETING .o FILES... ${END}"

fclean: clean
	@rm -f ${NAME}
	@make -C libft/ fclean
	@make -C MLX42/ fclean
	@echo "${RED}${BOLD} FCLEAN PROTOCOL: DELETING .a FILES... ${END}"

re: fclean all
	@echo "${GREEN}${BOLD} RE PROTOCOL: RECOMPILATION SUCCESSFULL ${END}"

.PHONY: all clean fclean re
