# LOS 'MKDIR' SON PARA CREAR LOS DIRECTORIOS DONDE SE GUARDARAN LA CACHE DE LOS SERVICIOS.
all:
	mkdir -p ~/data/mariadb
	mkdir -p ~/data/wordpress
	mkdir -p ~/data/nginx
	docker-compose -f ./srcs/docker-compose.yml up --build

up:
	docker-compose -f ./srcs/docker-compose.yml up -d

down:
	docker-compose -f ./srcs/docker-compose.yml down

stop:
	docker-compose -f ./srcs/docker-compose.yml stop

mariadb:
	docker exec -it mariadb_inception bash

wordpress:	
	docker exec -it wordpress_inception bash

nginx:	
	docker exec -it nginx_inception bash

fclean:
	docker-compose -f ./srcs/docker-compose.yml down
	docker system prune --all --volumes --force
	chmod 777 ~/data
	rm -rf ~/data

re: fclean all

.PHONY: all up down fclean re