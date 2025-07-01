FROM debian:bullseye

ARG MARIADB_NAME
ARG MARIADB_USER
ARG MARIADB_PASS
ARG MARIADB_ROOT_PASS
ARG WP_DB_HOST
ARG WP_TITLE
ARG WP_GROUP
ARG WP_ADMIN
ARG WP_ADMIN_PASS
ARG WP_ADMIN_MAIL
ARG WP_USER
ARG WP_USER_PASS
ARG WP_USER_MAIL

ENV MARIADB_NAME=${MARIADB_NAME} \
    MARIADB_USER=${MARIADB_USER} \
    MARIADB_PASS=${MARIADB_PASS} \
    MARIADB_ROOT_PASS=$MARIADB_ROOT_PASS \
    WP_DB_HOST=${WP_DB_HOST} \
    WP_TITLE=${WP_TITLE} \
    WP_GROUP=${WP_GROUP} \
    WP_ADMIN=${WP_ADMIN} \
    WP_ADMIN_PASS=${WP_ADMIN_PASS} \
    WP_ADMIN_MAIL=${WP_ADMIN_MAIL} \
    WP_USER=${WP_USER} \
    WP_USER_PASS=${WP_USER_PASS} \
    WP_USER_MAIL=${WP_USER_MAIL}

RUN apt-get update -y && apt-get install -y \
    php7.4-fpm \
    php7.4-mysql \
    php7.4-curl \
    php7.4-gd \
    php7.4-mbstring \
    unzip \
    wget \
    curl \
    tar

RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    chmod +x wp-cli.phar && \
    mv wp-cli.phar /usr/local/bin/wp

RUN useradd "$WP_USER" && groupadd "$WP_GROUP" && usermod -aG "$WP_GROUP" "$WP_USER"
RUN useradd $WP_ADMIN && usermod -aG $WP_GROUP $WP_ADMIN && usermod -aG sudo $WP_ADMIN

RUN mkdir -p /var/www/html && chown -R $WP_USER:$WP_GROUP /var/www/html

COPY ./init_wp.sh /init_wp.sh
COPY ./php-fpm.conf /etc/php/7.4/fpm/php-fpm.conf
COPY ./wp-config.php /var/www/html/wp-config.php

RUN wget https://wordpress.org/latest.tar.gz -O /tmp/wordpress.tar.gz && \
    tar -xzf /tmp/wordpress.tar.gz -C /tmp && \
    mv /tmp/wordpress/* /var/www/html

RUN chmod +x init_wp.sh

EXPOSE 9000

CMD ["./init_wp.sh"]