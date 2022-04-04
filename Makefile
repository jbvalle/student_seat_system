.PHONY=run

all: run

run:
	g++ -o test_exe test.cxx libgtest.a -I. libpthread.so
