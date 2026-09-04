#include "sort.h"
#include <stdio.h>
#include <string.h>
// max line to be sorted
#define MAXLINES 5000
// pointer to text line
char *lineptr[MAXLINES];

// sort input lines
int main(int argc, char *argv[]) {
  // number of input line read
  int nlines;
  // numeric sort switch
  int numeric = 0;

  if (argc > 1 && strcmp(argv[1], "-n") == 0)
    numeric = 1;
  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    q_sort((void **)lineptr, 0, nlines - 1,
           (int (*)(void *, void *))(numeric ? numcmp : strcmp));
    writelines(lineptr, nlines);
    return 0;
  } else {
    printf("input too big to sort\n");
    return -1;
  }
}
