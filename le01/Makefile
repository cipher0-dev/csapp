.PHONY: all clean

PROG_BINS := $(patsubst %.c,build/%,$(wildcard *.c))

all: $(PROG_BINS) build/test_int_sizes_32 build/test_fun_32

clean:
	-rm -rf build 2>/dev/null

# programs binaries

build/%: %.c
	mkdir -p $(@D)
	zig cc -std=c23 -g -O0 -fno-sanitize=undefined -o $@ $^

build/test_int_sizes_32: test_int_sizes.c
	mkdir -p $(@D)
	zig cc -std=c23 -target x86-linux-gnu -g -O0 -fno-sanitize=undefined -o $@ $^

build/test_fun_32: test_fun.c
	mkdir -p $(@D)
	zig cc -std=c23 -target x86-linux-gnu -g -O0 -fno-sanitize=undefined -o $@ $^
