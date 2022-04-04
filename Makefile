.PHONY=run

all: run

run:
	g++ -o test_exe test.cxx -I. -L. libpthread.so libgtest.a
