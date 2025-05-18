CXX = g++
CC = gcc
CFLAGS = -Wall -Wextra -std=c++17 -mwindows -O2 -DUNICODE -D_UNICODE

SRC = $(wildcard src/*.cpp) $(wildcard src/**/*.cpp)
OBJ = $(SRC:.cpp=.o)
INCLUDE = -I./src/
TARGET = projectforge
LINKERLIBS =

.PHONY: all clean

all: libs build

libs:
	@echo "No external libs to build."

build: $(OBJ)
	$(CXX) $(CFLAGS) $(OBJ) -o bin/$(TARGET) $(LINKERLIBS)

%.o: %.cpp
	$(CXX) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJ) bin/$(TARGET)
	$(MAKE) -C thirdparty/lua clean
