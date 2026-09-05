#include "sort.h"
#include <stdio.h>
#include <string.h>

#define MAXLEN 1000 // max length of any input line

// writelines: write output lines
void writelines(char *lineptr[], int nlines) {
  for (int i = 0; i < nlines; i++) {
    printf("%s\n", lineptr[i]);
  }
}

// readlines: read input lines
int readlines(char *lineptr[], int maxlines) {
  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;
  while ((len = get_line(line, MAXLEN)) > 0) {
    if (nlines >= maxlines || (p = alloc(len + 1)) == NULL) {
      // alloc(len + 1)
      return -1;
    } else {

      if (len > 0 && line[len - 1] == '\n') {
        line[len - 1] = '\0';
      }
      strcpy(p, line);
      lineptr[nlines++] = p;
    }
  }
  return nlines;
}

int get_line(char *s, int lim) {
  int c;
  char *s_start_ptr = s;

  // copy input loop
  while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
    *s++ = c;
  }

  // append newline if present
  if (c == '\n') {
    *s++ = c;
  }

  // end with NULL
  *s = '\0';

  // return string length
  return (int)(s - s_start_ptr);
}
