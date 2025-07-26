# Nombre del compilador
CXX = g++

# Flags del compilador
CXXFLAGS = -Wall -Iinclude -std=c++17

# Archivos fuente y objeto
SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

# Nombre del ejecutable
TARGET = agenda

# Regla por defecto
all: $(TARGET)

# Regla para compilar el ejecutable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regla para compilar cada archivo fuente
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Crear carpeta build si no existe
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Limpiar archivos objeto y ejecutable
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# Para no confundir Make con archivos reales
.PHONY: all clean
