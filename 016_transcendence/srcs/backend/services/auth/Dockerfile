FROM node:20-alpine AS builder

WORKDIR /app

# Install production dependencies only
COPY package*.json ./
RUN npm install --omit=dev

COPY . .

# Production stage
FROM node:20-alpine

WORKDIR /app

# Copy only necessary files from builder stage
COPY --from=builder --chown=nodejs:nodejs /app/package*.json ./
COPY --from=builder --chown=nodejs:nodejs /app/node_modules ./node_modules
COPY --from=builder --chown=nodejs:nodejs /app/src ./src

EXPOSE 4000

CMD ["node", "src/app.js"]
