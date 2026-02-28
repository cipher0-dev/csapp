// This program demonstrates that casting on numeric values actually involves a
// numeric conversion from one encoding to another vs using the same underlying
// bytes and just changing the static type as is done with pointers.

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void show_bytes(void *start, size_t len) {
  uint8_t *s = start;
  for (auto i = 0; i < len; i++)
    printf(" %.2x", s[i]);
  printf("\n");
}

int main(int argc, char *argv[]) {
  int x = 12345;
  auto y = (float)x;

  int *ip = &x;
  auto *fp = (float *)ip;

  printf("x: %d\n", x);
  show_bytes(&x, sizeof(x));
  printf("y: %f\n", y);
  show_bytes(&y, sizeof(y));

  printf("ip: %p\n", ip);
  show_bytes(&ip, sizeof(ip));
  printf("*ip: %d\n", *ip);
  show_bytes(ip, sizeof(*ip));
  printf("fp: %p\n", fp);
  show_bytes(&fp, sizeof(fp));
  printf("*fp: %f\n", *fp);
  show_bytes(fp, sizeof(*fp));
  return EXIT_SUCCESS;
}
