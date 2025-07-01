#!/bin/bash

echo "EOOOOOOOOOOOOOOO"
echo "MARIADB_NAME: $MARIADB_NAME"


# INICIAMOS MARIADB.


echo "LLEGAMOS PORAKA"

# ESPERAMOS A QUE INICIE MARIADB ANTES DE EJECUTAR LAS SIGUIENTES INSTRUCCIONES.
until mariadb -e "SELECT 1" > /dev/null 2>&1; do
    sleep 1
done

echo "LLEGAMOS PORAKI++"

# CREAMOS LA BASE DE DATOS Y LOS USUARIOS.
echo "CREATE DATABASE IF NOT EXISTS $MARIADB_NAME;" > msql_db.sql
echo "CREATE USER IF NOT EXISTS '$MARIADB_USER'@'%' IDENTIFIED BY '$MARIADB_PASS' ;" >> msql_db.sql
echo "GRANT ALL PRIVILEGES ON $MARIADB_NAME.* TO '$MARIADB_USER'@'%' ;" >> msql_db.sql
echo "FLUSH PRIVILEGES;" >> msql_db.sql
echo "ALTER USER 'root'@'localhost' IDENTIFIED BY '$MARIADB_ROOT_PASS' ;" >> msql_db.sql
echo "RUNNING MARIADB"
mariadb < msql_db.sql

if [ ! -d "/var/lib/mysql/mysql" ]; then
    echo "Initializing MariaDB data directory..."
    mysql_install_db --user=mysql --basedir=/usr --datadir=/var/lib/mysql
fi

mysqld

# PARAMOS MARIADB.
# service mariadb stop