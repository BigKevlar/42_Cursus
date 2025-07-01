# Usamos imagen oficial de Node.js
FROM node:latest

# Copia solo los archivos necesarios para instalar dependencias
COPY package.json .

# Instala las dependencias
RUN npm install

# Copia el resto de los archivos del proyecto
COPY src .

# Expone el puerto en el que tu aplicación escucha
EXPOSE 4006

# Ejecuta la aplicación
CMD ["node", "app.js"]