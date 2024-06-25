# leaks --atExit -- ./philo ******
# export MallocStackLogging=1
# unset MallocStackLogging
#
# PONER ESTA FUNCION ANTES DE LA FUNCION MAIN...
#
#	void leaks()
#	{
# 		system("leaks -q philo");
# 	}
#
# ... Y ESTA LLAMADA EN LA PRIMERA LINEA DEL MAIN.
#
# 	atexit(leaks);

NAME			= philo

CFLAGS			= -Wall -Wextra -Werror -g

INC				= philo.h

SRC				=	main.c \
					parse.c \
					init.c \
					utils_libft.c \
					utils_dead.c \
					utils_dinner.c \
					utils_getters.c \
					utils_setters.c \
					utils_time.c \
					utils_table.c \
					utils_write.c

OBJ 			= ${SRC:.c=.o}

BOLD			=\033[1m
RED				=\033[31;1m
GREEN			=\033[32;1m
YELLOW			=\033[33;1m
END				=\033[0m

${NAME}: ${OBJ}
	@gcc $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "${GREEN}${BOLD} PHILOSOPHERS, PROYECT FROM JMARTOS- IN 42_MÁLAGA, CAN "EAT-SLEEP-THINK" NOW!!! ${END}"

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
	@echo "${GREEN}${BOLD} (RE PROTOCOL: RECOMPILATION SUCCESSFULL) ${END}"

.PHONY: all clean fclean re
