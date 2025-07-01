#!/bin/bash

echo "< INICIO DE ARCHIVO DE CONFIGURACION DE WORDPRESS >"

sed -i "s/database_name_here/$MARIADB_NAME/g" /var/www/html/wp-config.php
sed -i "s/username_here/$MARIADB_USER/g" /var/www/html/wp-config.php
sed -i "s/password_here/$MARIADB_PASS/g" /var/www/html/wp-config.php
sed -i "s/localhost/$MARIADB_NAME/g" /var/www/html/wp-config.php

wp core install --allow-root --path=/var/www/html \
	--url=$DOMAIN_NAME --title=inception \
	--admin_user=$WP_ADMIN \
	--admin_password=$WP_ADMIN_PASS \
	--admin_email=$WP_ADMIN_MAIL

wp user create --allow-root $WP_USER $WP_USER_MAIL --user_pass=$WP_USER_PASS --path=/var/www/html

php-fpm7.4 -y /etc/php/7.4/fpm/php-fpm.conf -F

echo "< SI VES ESTE ECHO ES QUE NO SE HA INICIADO PHP... >"