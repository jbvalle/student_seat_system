.PHONY= build

CMAKE=cmake

BUILD=./build/

all: build


build: FORCE
	mkdir -p $@ && $(CMAKE) -B./$(BUILD) && cd $(BUILD) && $(MAKE)

FORCE:

