#include "sort.h"
#include <stdio.h>

#define MAXLINES 5000

char *lineptr[MAXLINES];
// sort input line
int main() {
  // number of input line read
  int nlines;
  char store[MAXSTORE];

  if ((nlines = readlines(lineptr, MAXLINES, store)) >= 0) {
    qsort(lineptr, 0, nlines - 1);
    writelines(lineptr, nlines);
    return 0;
  } else {
    printf("error: input too big to sort");
    return 1;
  }
}
