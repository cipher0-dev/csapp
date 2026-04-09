/*

Run with:

  strace -f -tt -T -e trace=memory ./build/test_allocator > ./build/out.txt 2>&1

to see the behavior of the default glibc allocator. It uses brk for small
allocations and mmap for larger ones.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define SMALL_MAX (64 * 1024)       // up to 64 KB
#define LARGE_MIN (128 * 1024)      // 128 KB and above often use mmap
#define LARGE_MAX (4 * 1024 * 1024) // up to 4 MB

#define ITERS 1000

int main(void) {
  void *ptrs[ITERS];

  printf("PID: %d\n", getpid());

  printf("Starting small allocations:\n");

  // Phase 1: small allocations (likely served by brk / heap)
  for (int i = 0; i < ITERS; i++) {
    size_t size = (rand() % SMALL_MAX) + 1;
    printf("+malloc(%ld)\n", size);
    ptrs[i] = malloc(size);
    printf("-malloc(%ld)\n", size);
    if (!ptrs[i]) {
      perror("malloc");
      exit(1);
    }
    memset(ptrs[i], 0xAA, size);
  }

  printf("Starting larger allocations:\n");

  for (int i = 0; i < ITERS; i++) {
    printf("+free(%p)\n", ptrs[i]);
    free(ptrs[i]);
    printf("-free(%p)\n", ptrs[i]);
  }

  // Phase 2: large allocations (likely mmap)
  for (int i = 0; i < ITERS; i++) {
    size_t size = LARGE_MIN + (rand() % (LARGE_MAX - LARGE_MIN));
    printf("+malloc(%ld)\n", size);
    ptrs[i] = malloc(size);
    printf("-malloc(%ld)\n", size);
    if (!ptrs[i]) {
      perror("malloc");
      exit(1);
    }
    memset(ptrs[i], 0xBB, size);
  }

  for (int i = 0; i < ITERS; i++) {
    printf("+free(%p)\n", ptrs[i]);
    free(ptrs[i]);
    printf("-free(%p)\n", ptrs[i]);
  }

  printf("Starting mixed allocations:\n");

  // Phase 3: mixed allocations
  for (int i = 0; i < ITERS; i++) {
    size_t size;
    if (i % 2 == 0)
      size = (rand() % SMALL_MAX) + 1;
    else
      size = LARGE_MIN + (rand() % (LARGE_MAX - LARGE_MIN));

    printf("+malloc(%ld)\n", size);
    ptrs[i] = malloc(size);
    printf("-malloc(%ld)\n", size);
    if (!ptrs[i]) {
      perror("malloc");
      exit(1);
    }
    memset(ptrs[i], 0xCC, size);
  }

  for (int i = 0; i < ITERS; i++) {
    printf("+free(%p)\n", ptrs[i]);
    free(ptrs[i]);
    printf("-free(%p)\n", ptrs[i]);
  }

  return 0;
}
