
#include <stdio.h>
#include <stdlib.h>

unsigned long __POS_INFINITY = 0x7ff0000000000000;
unsigned long __NEG_INFINITY = 0xfff0000000000000;
unsigned long __NEG_ZERO = 0x8000000000000000;

#define POS_INFINITY *(double *)(&__POS_INFINITY)
#define NEG_INFINITY *(double *)(&__NEG_INFINITY)
#define NEG_ZERO *(double *)(&__NEG_ZERO)

int main(int argc, char *argv[]) {
  unsigned int x = 0x80000000;
  printf("neg zero: %f\n", *(float *)(&x));

  x = 0xFF800000;
  printf("neg inf: %f\n", *(float *)(&x));

  x = 0x7F800000;
  printf("pos inf: %f\n", *(float *)(&x));

  x = 0xFF800001;
  printf("neg nan: %f\n", *(float *)(&x));

  x = 0x7F800001;
  printf("pos nan: %f\n", *(float *)(&x));

  printf("double pos inf: %f\n", POS_INFINITY);
  printf("double neg inf: %f\n", NEG_INFINITY);
  printf("double neg zero: %f\n", NEG_ZERO);

  return EXIT_SUCCESS;
}
