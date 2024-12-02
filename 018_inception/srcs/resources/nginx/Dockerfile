# MONTAMOS IMAGEN.
FROM debian:bullseye

# EJECUTAMOS LOS PRIMEROS COMANDOS.
RUN apt update -y && apt upgrade -y && apt install nginx openssl

# COPIAMOS...
COPY config/nginx.conf /etc/nginx/conf.d/default.conf

# INSTALAMOS DEPENDENCIAS.
RUN mkdir -p /etc/nginx/ssl

RUN openssl 


# 
EXPOSE

#
CMD ["nginx", "-g", "daemon off";]
