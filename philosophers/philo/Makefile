# 01:33:40

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
					syncro_utils.c \
					utils.c \
					table.c \
					mutex.c \
					threads.c \
					get_set_controls.c

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
	@echo "${YELLOW}${BOLD} COMPILATING FUNCTIONS, PLEASE BE PATIENT... ${END}"
	@gcc ${CFLAGS} -c ${INC} src/$(@F)
	@echo "${GREEN}${BOLD} PROGRAM SUCCESSFULLY COMPILED ${END}"

all: ${NAME}

clean:
	@rm -rf ${OBJS}
	@echo "${RED}${BOLD} CLEAN PROTOCOL: DELETING .o FILES... ${END}"

fclean: clean
	@rm -rf ${NAME}
	@echo "${RED}${BOLD} FCLEAN PROTOCOL: DELETING .a FILES... ${END}"

re: fclean all
	@echo "${GREEN}${BOLD} RE PROTOCOL: RECOMPILATION SUCCESSFULL ${END}"

.PHONY: all clean fclean re
