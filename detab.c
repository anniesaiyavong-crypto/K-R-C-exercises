#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_START 1
#define DEFAULT_INC 8
void parse_args(int argc, char *argv[], int *m, int *n) {
  *m = DEFAULT_START;
  *n = DEFAULT_INC;

  while (--argc > 0) {
    char *s = *++argv;
    if (*s == '-') {
      *m = atoi(s + 1);
    } else if (*s == '+') {
      *n = atoi(s + 1);
    }
  }
}

int is_tab_stop(int col, int m, int n) {
  if (col < m)
    return 0;
  return ((col - m) % n == 0);
}

int main(int argc, char *argv[]) {
  int c;
  int col = 1;
  int m, n;

  parse_args(argc, argv, &m, &n);

  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      do {
        putchar(' ');
        col++;
      } while (!is_tab_stop(col, m, n));
    } else if (c == '\n') {
      putchar(c);
      col = 1;
    } else {
      putchar(c);
      col++;
    }
  }
  return 0;
}
