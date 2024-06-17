# 01:36:00

# leaks --atExit -- ./philo ******
# export MallocStackLogging=1
# unset MallocStackLogging

NAME			= philo

CFLAGS			= -Wall -Wextra -Werror -g

INC				= philo.h

SRC				=	philo.c \
					error.c \
					parse.c \
					init.c \
					libft_utils.c \
					syncro_utils.c \
					utils.c \
					table.c \
					mutex.c \
					threads.c \
					get_set_control.c

OBJ 			= ${SRC:.c=.o}

BOLD			=\033[1m
RED				=\033[31;1m
GREEN			=\033[32;1m
YELLOW			=\033[33;1m
BLUE			=\033[34;1m
END				=\033[0m

${NAME}: ${OBJ}
	@gcc $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "${YELLOW}${BOLD} PHILOSOPHERS, PROYECT FROM JMARTOS- IN 42_MÁLAGA, CAN "EAT-SLEEP-THINK" NOW!!! ${END}"

${OBJ}: ${SRC}
	@echo "${YELLOW}${BOLD} COMPILATING FUNCTIONS, PLEASE BE PATIENT... ${END}"
	@gcc ${CFLAGS} -c ${SRC}
	@echo "${GREEN}${BOLD} PROGRAM SUCCESSFULLY COMPILED ${END}"

all: ${NAME}

clean:
	@rm -rf ${OBJ}
	@echo "${RED}${BOLD} CLEAN PROTOCOL: DELETING FUNCTIONS FILES... ${END}"

fclean: clean
	@rm -rf ${NAME}
	@echo "${RED}${BOLD} FCLEAN PROTOCOL: DELETING PROGRAM FILES... ${END}"

re: fclean all
	@echo "${GREEN}${BOLD} RE PROTOCOL: RECOMPILATION SUCCESSFULL ${END}"

.PHONY: all clean fclean re
