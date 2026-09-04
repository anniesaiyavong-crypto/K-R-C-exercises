#include "sort.h"
#include <stdio.h>
#include <string.h>
// max line to be sorted
#define MAXLINES 5000
// pointer to text line
char *lineptr[MAXLINES];
// flags
int numeric = 0;
int reverse = 0;
// sort input lines
int main(int argc, char *argv[]) {
  // number of input line read
  int nlines;
  int c;
  while (--argc && (*++argv)[0] == '-')
    while ((c = *++argv[0]))
      switch (c) {
      case 'n':
        numeric = 1;
        break;

      case 'r':
        reverse = 1;
        break;
      case 'h':
        printf("-n numeric sort, -r reverse\n");
        return 0;

      default:
        printf("unknow argument\n");
        return 0;
      }

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
