.PHONY=run

all: run

run:
	g++ -o test_exe -L./googletest/build/lib -L. -I. test.cxx -lgtest -lpthread
	./test_exe
