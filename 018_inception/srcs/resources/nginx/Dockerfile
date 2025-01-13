# MONTAMOS IMAGEN.
FROM debian:bullseye

ARG DOMAIN_NAME

ENV DOMAIN_NAME=${DOMAIN_NAME}

# EJECUTAMOS LOS PRIMEROS COMANDOS.
RUN apt-get update -y && apt-get install -y && apt-get install nginx openssl -y

# COPIAMOS...
COPY ./nginx.conf /etc/nginx/conf.d/default.conf

# INSTALAMOS DEPENDENCIAS.
RUN mkdir -p /etc/nginx/ssl

RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/nginx/ssl/nginx.key -out /etc/nginx/ssl/nginx.crt -subj "/CN=${DOMAIN_NAME}/C=ES/L=Malaga"

# 
EXPOSE 443

RUN sed -i "s/PATATA/$DOMAIN_NAME/g" /etc/nginx/conf.d/default.conf

# SOLO PARA DEBUG.
RUN cat /etc/nginx/conf.d/default.conf

CMD ["nginx", "-g", "daemon off;"]