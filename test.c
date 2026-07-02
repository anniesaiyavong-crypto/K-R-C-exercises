#include <stdio.h>


int bitcount(unsigned x) {
  int b;

  for (b = 0; x != 0; b++) {
    x &= (x - 1);
  }
  return b;
}

int main() {
  unsigned int x = 10;

  printf("%d\n",bitcount(x));
  return 0;
}


