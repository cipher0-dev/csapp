#include <stdio.h>
#include <stdlib.h>

int counter = 0;

void recurse() {
  int near_stack_ptr;

  counter++;
  if (counter < 10 || counter > 261700) {
    printf("%p %d\n", &near_stack_ptr, counter);
  }
  recurse();
}

int main(int argc, char *argv[]) {
  recurse();
  return EXIT_SUCCESS;
}
