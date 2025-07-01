"use strict";

const fp = require("fastify-plugin");               // Importa fastify-plugin para extender funcionalidades de Fastify
const SQLite = require("better-sqlite3");           // Importa SQLite para manejo de base de datos
const path = require("path");                       // Módulo para manejo de rutas de archivos
const bcrypt = require("bcrypt");                 // Importa bcrypt para encriptar contraseñas

async function dbPlugin(fastify, options) {
  // Crear conexión a la base de datos SQLite
  const dbPath = path.resolve(options.database.path || './database.sqlite');  // Resuelve la ruta de la base de datos
  const db = new SQLite(dbPath);                    // Crea una nueva conexión SQLite

  // Crear tabla de usuarios de ejemplo si no existe
  db.exec(`
    CREATE TABLE IF NOT EXISTS users (
      id INTEGER PRIMARY KEY AUTOINCREMENT,
      email TEXT NOT NULL,
      username TEXT UNIQUE NOT NULL,
      password TEXT NOT NULL,
      oauth BOOLEAN DEFAULT 0,
      created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
    )
  `);
  



  // Decorar Fastify con métodos de base de datos
  fastify.decorate("userDB", {
    // Crear un nuevo usuario
    async createUser(email, username, password, oauth = 0) {
      try {
        if (!username || !password) {
          throw new Error('Username and password are required');  // Verifica que username y password no estén vacíos
        }
        const hashedPassword = await bcrypt.hash(password, 10);  // Encripta la contraseña
        const stmt = db.prepare('INSERT INTO users (email, username, password, oauth) VALUES (?, ?, ?, ?)');  // Prepara statement de inserción
        const result = stmt.run(email, username, hashedPassword, oauth);   // Ejecuta la inserción
        return { 
          id: result.lastInsertRowid,               // Devuelve el ID generado
          email,
          username,
          hashedPassword,
          oauth
        };
      } catch (error) {
        if (error.message.includes('UNIQUE constraint failed')) {
          throw new Error('Username already exists');  // Maneja error de duplicado
        }
        throw error;
      }
    },

    // Obtener usuario por ID
    async getUserById(id) {
      const stmt = db.prepare('SELECT * FROM users WHERE id = ?');  // Prepara consulta por ID
      return stmt.get(id);                          // Devuelve el usuario encontrado
    },

    // Obtener usuario por username
    async getUserByUsername(username) {
      const stmt = db.prepare('SELECT * FROM users WHERE username = ?');  // Prepara consulta por username
      return stmt.get(username);                    // Devuelve el usuario encontrado
    },

    // Comprobar contraseña
    async checkPassword(username, password) {
      const user = await this.getUserByUsername(username);  // Busca el usuario por username
      if (!user) {
        throw new Error('User not found');                  // Maneja error si no se encuentra el usuario
      }
      const isValid = await bcrypt.compare(password, user.password);  // Compara la contraseña
      return isValid;                                      // Devuelve true o false
    },

    // Listar usuarios con paginación
    async listUsers(limit = 10, offset = 0) {
      const stmt = db.prepare(`
        SELECT * FROM users 
        ORDER BY created_at DESC 
        LIMIT ? OFFSET ?
      `);                                           // Consulta con límite y desplazamiento
      return stmt.all(limit, offset);               // Devuelve lista de usuarios
    },

    // Actualizar usuario
    async updateUser(id, updates) {
      const updateFields = Object.keys(updates)
        .map(key => `${key} = ?`)
        .join(', ');                                // Genera cadena de campos a actualizar
      
      const values = [...Object.values(updates), id];  // Prepara valores para actualización
      
      const stmt = db.prepare(`
        UPDATE users 
        SET ${updateFields} 
        WHERE id = ?
      `);                                           // Prepara statement de actualización
      
      stmt.run(values);                             // Ejecuta actualización
      
      return this.getUserById(id);                  // Devuelve usuario actualizado
    },

    // Eliminar usuario
    async deleteUser(id) {
      const stmt = db.prepare('DELETE FROM users WHERE id = ?');  // Prepara statement de eliminación
      const result = stmt.run(id);                  // Ejecuta eliminación
      return result.changes > 0;                    // Devuelve true si se eliminó
    },

    async create2fa(email) {
      const code = Math.floor(100000 + Math.random() * 900000).toString();  // Genera código de 6 dígitos
      const stmt = db.prepare('INSERT INTO twofactor (email, code) VALUES (?, ?)');  // Prepara statement de inserción
      const result = stmt.run(email, code);               // Ejecuta la inserción
      return { 
        email,
        code
      };

      
    }

  });


  // Cerrar conexión cuando el servidor se apague
  fastify.addHook("onClose", (instance, done) => {
    if (db) {
      db.close();                                   // Cierra la conexión de base de datos
    }
    done();
  });
}

module.exports = fp(dbPlugin, { name: "db" });      // Exporta el plugin con nombre "db"