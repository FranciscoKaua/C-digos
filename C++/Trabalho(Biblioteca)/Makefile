CXX = clang++
CXXFLAGS = -Wall -Wextra -std=c++17 -Iinclude

SRC = src/Pessoa.cpp \
      src/Usuario.cpp \
      src/Bibliotecario.cpp \
      src/Livro.cpp \
      src/Emprestimo.cpp \
      src/main.cpp

OBJ = $(SRC:.cpp=.o)

EXEC = biblioteca

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $(EXEC)

src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(EXEC)