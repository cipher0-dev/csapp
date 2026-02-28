// NOTE: I keep hearing people say that arrays are allocated on the stack and
// not the heap. This program demonstrates getting a pointer to an array
// allocated on the heap to show it is very possible. This can be useful when
// allocating a block of memory on the heap for n-dimensional structures where
// you don't want to have to manually calculate the offsets into the block and
// would prefer to use [i][j][k] notation.

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void print_arr(const unsigned char arr[SIZE]) {
  for (auto i = 0; i < SIZE; i++)
    printf(" %2x", arr[i]);
  puts("");
}

void inc_arr(unsigned char arr[SIZE]) {
  for (auto i = 0; i < SIZE; i++)
    arr[i] += 1;
}

int main(int argc, char *argv[]) {
  auto p = malloc(SIZE);
  printf("p: %p\n", p);
  // NOTE: x has type unsigned char (*)[10] which is a pointer to an array
  // NOTE: p is not needed here as the cast can be done directly on the malloc
  //       call. I only separated it to show the difference between the pointer
  //       syntax vs the array syntax.
  auto x = (unsigned char (*)[SIZE])p;
  printf("x: %p\n", x);

  printf("*p: %2x\n", *(unsigned char *)p);
  printf("*(p+1): %2x\n", *(unsigned char *)(p + 1));
  printf("*(p+2): %2x\n", *(unsigned char *)(p + 2));
  printf("(*x)[0]: %2x\n", (*x)[0]);
  printf("(*x)[1]: %2x\n", (*x)[1]);
  printf("(*x)[2]: %2x\n", (*x)[2]);

  printf("(*x)[0]++\n");
  (*x)[0]++;
  printf("(*x)[1] += 2\n");
  (*x)[1] += 2;
  printf("(*x)[2] += 3\n");
  (*x)[2] += 3;

  printf("*p: %2x\n", *(unsigned char *)p);
  printf("*(p+1): %2x\n", *(unsigned char *)(p + 1));
  printf("*(p+2): %2x\n", *(unsigned char *)(p + 2));
  printf("(*x)[0]: %2x\n", (*x)[0]);
  printf("(*x)[1]: %2x\n", (*x)[1]);
  printf("(*x)[2]: %2x\n", (*x)[2]);

  print_arr(p);
  print_arr(*x);

  inc_arr(p);
  inc_arr(*x);
  print_arr(*x);

  return EXIT_SUCCESS;
}
