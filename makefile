# Compilador e flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Isrc -Iinclude

# Diretórios
SRC_DIR = src
MAIN_DIR = main
BUILD_DIR = build

# Arquivos fonte
SRC = $(wildcard $(SRC_DIR)/*.cpp)
MAIN = $(MAIN_DIR)/main.cpp

# Objetos
OBJ = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC)) \
      $(patsubst $(MAIN_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(MAIN))

# Executável na raiz
EXEC = termo

# Cria a pasta build se não existir
$(shell mkdir -p $(BUILD_DIR))

# Regra principal
all: $(EXEC)

# Como gerar o executável
$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $(EXEC)

# Como compilar arquivos .cpp da pasta src
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Como compilar o main.cpp
$(BUILD_DIR)/%.o: $(MAIN_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpar arquivos gerados
clean:
	rm -rf $(BUILD_DIR) $(EXEC)

.PHONY: all clean
