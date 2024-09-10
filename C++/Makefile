# Nazwa pliku wynikowego
TARGET = snake_game

# Kompilator
CC = g++

# Flagi kompilacji
CFLAGS = -Wall -Wextra -std=c++11

# Flagi dla ncurses
LDFLAGS = -lncurses

# Pliki źródłowe
SRCS = main.cpp game.cpp snake.cpp food.cpp

# Pliki obiektowe
OBJS = $(SRCS:.cpp=.o)

# Komenda do budowania projektu
all: $(TARGET)

# Komenda do tworzenia pliku wykonywalnego
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

# Komenda do kompilowania plików źródłowych na obiektowe
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Komenda do czyszczenia plików obiektowych i binarnych
clean:
	rm -f $(OBJS) $(TARGET)

# Komenda do uruchamiania programu
run: $(TARGET)
	./$(TARGET)

