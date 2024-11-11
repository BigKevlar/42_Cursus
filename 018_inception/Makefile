all:
	mkdir ./srcs/system/nginx
	mkdir ./srcs/system/wordpress
	mkdir ./srcs/system/mariadb
	sudo docker-compose -f ./srcs/docker-compose.yml up --build

up:
	docker-compose -f ./srcs/docker-compose.yml up

down:
	docker-compose -f ./srcs/docker-compose.yml down

fclean:
	docker-compose -f ./srcs/docker-compose.yml down
	docker system prune --all --volumes
	rm -rf ./srcs/system

re: fclean all

.PHONY: all up down fclean re