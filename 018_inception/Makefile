# LOS 'MKDIR' SON PARA CREAR LOS DIRECTORIOS DONDE SE GUARDARAN LA CACHE DE LOS SERVICIOS.
all:
	mkdir -p ~/data/mariadb
	mkdir -p ~/data/wordpress
	mkdir -p ~/data/nginx
	docker-compose -f ./srcs/docker-compose.yml up --build

up:
	docker-compose -f ./srcs/docker-compose.yml up -d

mariadb:
	docker exec -it mariadb_inception bash

down:
	docker-compose -f ./srcs/docker-compose.yml down

fclean:
	docker-compose -f ./srcs/docker-compose.yml down
	docker system prune --all --volumes --force
	chmod 777 ~/data
	rm -rf ~/data

re: fclean all

.PHONY: all up down fclean re