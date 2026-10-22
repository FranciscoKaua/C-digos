CC = gcc

CFLAGS = -Wall -Wextra -Iinclude

TARGET = programa

OBJ = main.o \
      src/Matriz.o \
      src/Lista.o \
      src/bfs.o


$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)


main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o


src/Matriz.o: src/Matriz.c include/Matriz.h
	$(CC) $(CFLAGS) -c src/Matriz.c -o src/Matriz.o


src/Lista.o: src/Lista.c include/Lista.h
	$(CC) $(CFLAGS) -c src/Lista.c -o src/Lista.o


src/bfs.o: src/bfs.c include/bfs.h
	$(CC) $(CFLAGS) -c src/bfs.c -o src/bfs.o


clean:
	rm -f $(OBJ) $(TARGET)