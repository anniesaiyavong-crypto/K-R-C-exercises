#include <string.h>
#include "sort.h"
#define MAXLEN 1000 // max lenght of any input line
int getline(char *, int);
char *alloc(int);
// readlines: read input lines
int readlines(char *lineptr[], int maxlines) {
  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;
  while ((len = getline(line, MAXLEN)) > 0)
    if (nlines >= maxlines || (p = alloc(len)) == NULL)
      return -1;
    else {
      // delete newline
      line[len - 1] = '\0';
      strcpy(p, line);
      lineptr[nlines++] = p;
    }
  return nlines;
}
