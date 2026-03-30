#include <stdio.h>

typedef struct point3d {
  long x;
  long y;
  long z;
} point3d_t;

void print_point(point3d_t a) {
  a.x += 2;
  a.y += 4;
  a.z += 8;
  printf("point: {%ld, %ld, %ld}\n", a.x, a.y, a.z);
}

int main() {
  point3d_t a = {
      .x = 1,
      .y = 2,
      .z = 3,
  };
  print_point(a);
  print_point(a);
  return 0;
}
