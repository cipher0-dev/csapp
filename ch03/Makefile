.PHONY: all clean

PROG_BINS := $(patsubst %.c,build/%,$(wildcard *.c))

all: $(PROG_BINS) build/mstore.zig.s build/mstore.clang.s build/mstore.gcc.s build/mstore.o build/test_3_3.o build/test_3_11

clean:
	-rm -rf build 2>/dev/null

# programs binaries

build/%: %.c
	mkdir -p $(@D)
	zig cc -std=c23 -g -O0 -fno-sanitize=undefined -o $@ $^

build/mstore:
	mkdir -p $(@D)
	touch $@

build/mstore.o: mstore.c
	mkdir -p $(@D)
	clang -std=c23 -Og -c -o $@ $^

build/mstore.zig.s: mstore.c
	mkdir -p $(@D)
	zig cc -std=c23 -Og -S -fno-sanitize=undefined -o $@ $^

build/mstore.clang.s: mstore.c
	mkdir -p $(@D)
	clang -std=c23 -Og -S -o $@ $^

build/mstore.gcc.s: mstore.c
	mkdir -p $(@D)
	gcc -std=c23 -Og -S -o $@ $^

# NOTE: Looking at the generated .s files zig cc generates WAY more instructions
# and uses different registers than gcc and clang.

build/test_3_3.o: test_3_3.s
	mkdir -p $(@D)
	# NOTE: commented out since this was to detect invalid instructions
	# as $^ -o $@
	touch $@

build/test_3_11.o: test_3_11.s
	mkdir -p $(@D)
	as $^ -o $@

build/test_3_11: build/test_3_11.o
	mkdir -p $(@D)
	ld $^ -o $@
