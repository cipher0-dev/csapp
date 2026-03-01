#include <stdio.h>
#include <stdlib.h>

int main(void) {
  for (auto i = -3; i < sizeof(int); ++i) {
    printf("%d\n", i);
  }

  return EXIT_SUCCESS;
}
