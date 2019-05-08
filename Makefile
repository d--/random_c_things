.PHONY: all clean

all: bin/main

run: bin/main
	bin/main

bin/main: build/list.o bin
	$(CC) src/main.c build/list.o -o bin/main

build/list.o: build
	$(CC) -c src/ds/list.c -o build/list.o

build:
	@mkdir -p build

bin:
	@mkdir -p bin

clean:
	-rm -rf build
	-rm -rf bin

