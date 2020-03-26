.PHONY: all clean

all: bin/main

run: bin/main
	bin/main

bin/main: build/list.o build/array.o bin
	$(CC) src/main.c build/list.o build/array.o -o bin/main

build/list.o: build
	$(CC) -c src/ds/list.c -o build/list.o

build/array.o: build
	$(CC) -c src/ds/array.c -o build/array.o

build:
	@mkdir -p build

bin:
	@mkdir -p bin

clean:
	-rm -rf build
	-rm -rf bin

