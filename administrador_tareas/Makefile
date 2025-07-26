# Nombre del ejecutable
TARGET = administrador_tareas

# Archivos fuente
SRCS = main.c #administrador_tareas.c

# Archivos objeto
OBJS = $(SRCS:.c=.o)

# Compilador
CC = gcc

# Banderas de compilación 
CFLAGS = -Wall

# Regla por defecto
all: $(TARGET)

# Instrucciones de construccion del ejecutable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -c $< -o $@

# Instrucciones de compilacion de archivos
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpiar archivos generados
clean:
	rm -f $(TARGET) *.o