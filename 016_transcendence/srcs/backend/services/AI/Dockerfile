# Usamos imagen oficial de Node.js
FROM node:latest

# Copia solo los archivos necesarios para instalar dependencias
COPY package.json .

# Instala las dependencias
RUN npm install

# Copia el resto de los archivos del proyecto
COPY src/app.js .

# Copia el archivo de configuración de la base de datos
COPY src/worker.js .

# Expone el puerto en el que tu aplicación escucha
EXPOSE 4003

# Ejecuta la aplicación
CMD ["node", "app.js"]