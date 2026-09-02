#include <stdio.h>
#include "sort.h"

#define MAXLINE 5000

char *lineptr[MAXLINE];
// sort input line
int main() {
  // number of input line read
  int nlines;

  if ((nlines = readlines(lineptr, MAXLINE)) >= 0) {
    qsort(lineptr, 0, nlines - 1);
    writelines(lineptr, nlines);
    return 0;
  } else {
    printf("error: input too big to sort");
    return 1;
  }
}
