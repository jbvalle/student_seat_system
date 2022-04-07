.PHONY=run clean build test

BUILD_GTEST=build_gtest.sh

CC=g++

INC_FLAGS=-I./googletest/include

CFLAGS=-O0 -Wall -Wextra -pedantic

LDFLAGS=-L./googletest/build/lib -L. -lgtest -lpthread 

SRCS=$(wildcard *.cxx)

OBJ=$(SRCS:%.cxx=%.o)

TARGET:=main

all: clean $(OBJ) $(TARGET) run

%.o: %.cxx
	@$(CC) -c $(INC_FLAGS) $^ $(LDFLAGS) $(CFLAGS)

$(TARGET): $(OBJ)
	@$(CC) -o $@ $(INC_FLAGS) $^ $(LDFLAGS) $(CFLAGS)

run:
	@./$(TARGET)

build:
	@bash build_gtest.sh

test:
	@$(MAKE) -C testing 

clean:
	@rm -rf .*swp .*swo $(TARGET) *.o
	@$(MAKE) -C testing clean 
