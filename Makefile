.PHONY=run

all: run

run:
	g++ -o test_exe test.cxx -lgtest -I. -L. libpthread.so
