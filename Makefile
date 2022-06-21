.PHONY= build



all: build


build:
	mkdir -p $@ && cd $@ && cmake ..


