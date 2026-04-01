.PHONY: all clean

PROG_BINS := build/main build/m

all: $(PROG_BINS)

clean:
	-rm -rf build 2>/dev/null

# programs binaries

build/main: build/main.o build/sum.o
	mkdir -p $(@D)
	gcc -std=c23 -g -Og -v -o $@ $^

build/m: build/m.o build/swap.o
	mkdir -p $(@D)
	gcc -std=c23 -g -Og -v -o $@ $^

# library code

build/main.o: main.c
	mkdir -p $(@D)
	gcc -std=c23 -g -Og -v -c -o $@ $^

build/sum.o: sum.c
	mkdir -p $(@D)
	gcc -std=c23 -g -Og -v -c -o $@ $^

build/m.o: m.c
	mkdir -p $(@D)
	gcc -std=c23 -g -Og -v -c -o $@ $^

build/swap.o: swap.c
	mkdir -p $(@D)
	gcc -std=c23 -g -Og -v -c -o $@ $^
