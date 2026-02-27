#include <stdio.h>
#include <stdlib.h>

typedef unsigned char *byte_pointer;

void show_bytes(void *start, size_t len) {
  byte_pointer s = start;
  int i;
  for (i = 0; i < len; i++)
    printf(" %.2x", s[i]);
  printf("\n");
}

void show_int(int x) { show_bytes(&x, sizeof(int)); }

int main(int argc, char *argv[]) {
  show_int(12345);
  return EXIT_SUCCESS;
}
