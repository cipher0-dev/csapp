#include <stdalign.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

// size/offset/alignment
typedef struct rec {
  int *a;   // 8/0/8
  float b;  // 4/8/4
  char c;   // 1/12/1
  short d;  // 2/14/2
  long e;   // 8/16/8
  double f; // 8/24/8
  int g;    // 4/32/4
  char *h;  // 8/40/8
} rec;

// size/offset/alignment
typedef struct rec_packed {
  int *a;   // 8/0/8
  long e;   // 8/8/8
  double f; // 8/16/8
  char *h;  // 8/24/8
  float b;  // 4/32/4
  int g;    // 4/36/4
  short d;  // 2/40/2
  char c;   // 1/41/1
} rec_packed;

int main(int argc, char *argv[]) {
  printf("rec:\n");
  printf("  a: %ld\n", offsetof(rec, a));
  printf("  b: %ld\n", offsetof(rec, b));
  printf("  c: %ld\n", offsetof(rec, c));
  printf("  d: %ld\n", offsetof(rec, d));
  printf("  e: %ld\n", offsetof(rec, e));
  printf("  f: %ld\n", offsetof(rec, f));
  printf("  g: %ld\n", offsetof(rec, g));
  printf("  h: %ld\n", offsetof(rec, h));
  printf("  sizeof: %ld\n", sizeof(rec));
  printf("  alignof: %ld\n", alignof(rec));

  printf("\nrec_packed:\n");
  printf("  a: %ld\n", offsetof(rec_packed, a));
  printf("  e: %ld\n", offsetof(rec_packed, e));
  printf("  f: %ld\n", offsetof(rec_packed, f));
  printf("  h: %ld\n", offsetof(rec_packed, h));
  printf("  b: %ld\n", offsetof(rec_packed, b));
  printf("  g: %ld\n", offsetof(rec_packed, g));
  printf("  d: %ld\n", offsetof(rec_packed, d));
  printf("  c: %ld\n", offsetof(rec_packed, c));
  printf("  sizeof: %ld\n", sizeof(rec_packed));
  printf("  alignof: %ld\n", alignof(rec_packed));

  return EXIT_SUCCESS;
}
