#include <stdio.h>
#include <stdlib.h>

void fibonacci(int n) {
  int a = 0;
  int b = 1;
  int tmp = 0;

  if (n <= 0)
    goto done;

loop:
  printf("%d\n", a);
  tmp = a;
  a = b;
  b += tmp;
  n--;
  if (n > 0)
    goto loop;

done:
  return;
}

int main(int argc, char *argv[]) {
  fibonacci(40);
  return EXIT_SUCCESS;
}
