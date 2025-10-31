CC := g++
CFLAGS := -std=c++11 -O2
TARGET := rps
SRC := main.cpp rockpaperscissor.cpp

.PHONY: all build run clean

all: build

build:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: build
	@echo "Running Rock Paper Scissor..."
	./$(TARGET)

clean:
	rm -f $(TARGET)
