
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  auto x = sizeof(int);
  auto y = -256;

  printf("%d < %d -> %s\n", y, x, (y < x) ? "true" : "false");
  return EXIT_SUCCESS;
}
