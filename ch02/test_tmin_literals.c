#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

#define hex_dump(x) (printf(#x ": %016" PRIx64 "\n", (uint64_t)x))

int main(int argc, char *argv[]) {
  int x = -2147483648;
  int y = -2147483647 - 1;

  hex_dump(x);
  hex_dump(y);

  hex_dump((int)(-2147483648));
  hex_dump((int)(-2147483647 - 1));

  hex_dump(-2147483648);
  hex_dump(-2147483647 - 1);

  return EXIT_SUCCESS;
}
