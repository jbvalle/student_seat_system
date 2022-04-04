.PHONY=run

all: run

run:
	g++ -o test_exe -L. -I. test.cxx vendor/google/googletest/googletest/build/lib/libgtest.a libpthread.so
	./test_exe
