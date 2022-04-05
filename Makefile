.PHONY=run

all: run

run:
	g++ -o test_exe -I. test.cxx -L./googletest/build/lib -lgtest -L. -lpthread
	./test_exe
