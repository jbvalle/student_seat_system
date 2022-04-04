.PHONY=run

all: run

run:
	g++ -o test_exe -L. -I. test.cxx libgtest.a libpthread.so
	./test_exe
