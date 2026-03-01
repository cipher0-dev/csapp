.PHONY: all clean

PROG_BINS := $(patsubst %.c,build/%,$(wildcard *.c))

all: $(PROG_BINS)

clean:
	-rm -rf build 2>/dev/null

# programs binaries

build/%: %.c
	mkdir -p $(@D)
	zig cc -std=c23 -g -O0 -fno-sanitize=undefined -o $@ $^

build/test_tmin_literals: test_tmin_literals.c
	mkdir -p $(@D)
	zig cc -std=c23 -g -O0 -target x86-linux-gnu -fno-sanitize=undefined -o $@_32_23 $^
	zig cc -std=c17 -g -O0 -target x86-linux-gnu -fno-sanitize=undefined -o $@_32_17 $^
	zig cc -std=c11 -g -O0 -target x86-linux-gnu -fno-sanitize=undefined -o $@_32_11 $^
	zig cc -std=c99 -g -O0 -target x86-linux-gnu -fno-sanitize=undefined -o $@_32_99 $^
	zig cc -std=c90 -g -O0 -target x86-linux-gnu -fno-sanitize=undefined -o $@_32_90 $^
