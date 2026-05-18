# Compiler
CXX = g++

# Flags
CXXFLAGS = -Wall -std=c++17 -Iinclude

# Target
TARGET = app

# Source files
SRC = src/main.cpp src/Car.cpp src/Truck.cpp

# Object files
OBJ = $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)