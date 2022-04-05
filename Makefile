.PHONY=run

all: run

run:
	g++ -o test_exe -L./googletest/build/lib -I. test.cxx -lgtest libpthread.so
	./test_exe
