.PHONY=run clean

CC=g++

INC_FLAGS=-I./googletest/include

CFLAGS=-O0 -Wall -Wextra -pedantic

LDFLAGS=-L./googletest/build/lib -L. -lgtest -lpthread 

SRCS=$(wildcard *.cxx)

OBJ=$(SRCS:%.cxx=%.o)

TARGET:=test

all: clean $(OBJ) $(TARGET) run

%.o: %.cxx
	$(CC) -c $(INC_FLAGS) $^ $(LDFLAGS) $(CFLAGS)

$(TARGET): $(OBJ)
	$(CC) -o $@ $(INC_FLAGS) $^ $(LDFLAGS) $(CFLAGS)

run:
	#g++ -o test_exe -I./googletest/include test.cxx -L./googletest/build/lib -L. -lgtest -lpthread -O0
	./$(TARGET)

clean:
	rm -rf .*swp .*swo $(TARGET)
