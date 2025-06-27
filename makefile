# Compilador e flags
CXX = g++
CXXFLAGS = -Iinclude -std=c++11 -Wall

# Arquivos fonte e objetos
SRC = main/main.cpp crc/PalavraSecreta.cpp
OBJ = $(SRC:.cpp=.o)

# Nome do executável
EXEC = termo

# Regra principal
all: $(EXEC)

# Como gerar o executável
$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $(EXEC)

# Como compilar arquivos .cpp em .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpar arquivos gerados
clean:
	rm -f $(OBJ) $(EXEC)

