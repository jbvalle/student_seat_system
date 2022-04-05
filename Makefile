r.PHONY=run

all: run

run:
	g++ -o test_exe -I. test.cxx -L./googletest/build/lib -L. -lgtest -lpthread -O0
	./test_exe
