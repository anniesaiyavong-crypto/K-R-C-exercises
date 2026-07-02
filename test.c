#include <stdio.h>

unsigned setbit(unsigned int x, int p, int n,unsigned int y) {
return (x & ~(~(~0 << n) << (p + 1 - n))) | ((y & ~(~0 << n)) << (p + 1 - n));
}

int main() {
  unsigned int x = 0xFF;
  unsigned int y = 1;
  int p = 4;
  int n = 3;
  printf("%d\n", setbit(n, x, p, y));
}
