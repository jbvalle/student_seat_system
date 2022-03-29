.PHONY= clean run memleak

CC=gcc

gtk_FLAGS=`pkg-config gtk+-3.0 --cflags --libs`

CFLAGS=-g -Wall -Wextra -pedantic 

VFLAGS=--leak-check=full --track-origins=yes

SRCS=$(wildcard *.c)

OBJ=$(SRCS:%.c=%.o)

TARGET=main

#programs

all: $(OBJ) $(TARGET) run

#generate obj files

%.o: %.c
	$(CC) -c -o $@ $^ $(gtk_FLAGS) $(CFLAGS)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(gtk_FLAGS) $(CFLAGS)

run:
	./$(TARGET)

memleak: $(TARGET)
	valgrind $(VFLAGS) ./$^


clean:
	rm -rf $(TARGET) $(OBJ)
