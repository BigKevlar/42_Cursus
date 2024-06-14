# 01:23:34

# leaks --atExit -- ./philo ******
# export MallocStackLogging=1
# unset MallocStackLogging

NAME			= philo

CFLAGS			= -Wall -Wextra -Werror -g

INC				= philo.h

SRC				= 

OBJS 			= ${SRC:.c=.o}

BOLD			=\033[1m
RED				=\033[31;1m
GREEN			=\033[32;1m
YELLOW			=\033[33;1m
BLUE			=\033[34;1m
END				=\033[0m

${NAME}: ${OBJS}
	@echo "${YELLOW}${BOLD} "PHILOSOPHERS" 42_MALAGA, PROYECT FROM JMARTOS- ${END}"
	@gcc $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "${YELLOW}${BOLD} PHILOSOPHERS CAN "EAT-SLEEP-THINK" NOW!!! ${END}"

${OBJS}: 
	@echo "${BLUE}${BOLD} COMPILATING FUNCTIONS, PLEASE BE PATIENT... ${END}"
	@gcc ${CFLAGS} -c ${INC} src/$(@F)
	@echo "${GREEN}${BOLD} PROGRAM SUCCESSFULLY COMPILED ${END}"

all: ${NAME}

clean:
	@rm -rf ${OBJS}
	@echo "${RED}${BOLD} CLEAN PROTOCOL: DELETING .o FILES... ${END}"

fclean: clean
	@rm -f ${NAME}
	@make -C libft/ fclean
	@make -C MLX42/ fclean
	@echo "${RED}${BOLD} FCLEAN PROTOCOL: DELETING .a FILES... ${END}"

re: fclean all
	@echo "${GREEN}${BOLD} RE PROTOCOL: RECOMPILATION SUCCESSFULL ${END}"

.PHONY: all clean fclean re
