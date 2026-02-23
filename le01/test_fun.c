#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int a[2];
  double d;
} struct_t;

double fun(int i) {
  volatile struct_t s;
  s.d = 3.14;
  // s.a[i] = 1073741824;
  s.a[i] = 0;
  return s.d;
}

int main(int argc, char *argv[]) {
  for (auto i = 0; i < 32; ++i)
    printf("%f\n", fun(i));

  return EXIT_SUCCESS;
}
