#include <stdio.h>
// r = reverse
unsigned roll(unsigned int x, int n) {
 return (x >> n) | (x << ((sizeof(x) * 8) - n) );
}

int main() {
  unsigned int x = 0xFF;
  int p = 4;
  int n = 3;
  printf("%u\n", roll(n, x));
}
