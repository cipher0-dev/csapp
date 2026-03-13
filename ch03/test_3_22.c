#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int32_t fact_do_32(int32_t n) {
  int32_t result = 1;
  do {
    result *= n;
    n = n - 1;
  } while (n > 1);
  return result;
}

int64_t fact_do_64(int64_t n) {
  int64_t result = 1;
  do {
    result *= n;
    n = n - 1;
  } while (n > 1);
  return result;
}

int main(int argc, char *argv[]) {
  printf("32: %d\n", fact_do_32(14));
  printf("64: %ld\n", fact_do_64(14));
  return EXIT_SUCCESS;
}
