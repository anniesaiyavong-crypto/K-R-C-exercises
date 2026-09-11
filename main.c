#include <ctype.h>
#include <stdio.h>

#define MAXLINE 80
#define OCTLEN 4

int inc(int pos, int n) {
  if (pos + n >= MAXLINE) {
    putchar('\n');
    return n;
  }
  return pos + n;
}
int main() {
  int c;
  int pos = 0;

  while ((c = getchar()) != EOF) {
    if (iscntrl(c) && c != '\n' && c != '\t') {
      pos = inc(pos, OCTLEN);
      printf("\\%03o", c);
    } else if (c == '\n') {
      putchar('\t');
    } else {
      pos = inc(pos, 1);
      putchar(c);
    }
  }
  return 0;
}
