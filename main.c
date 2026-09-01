#include <stdio.h>
int get_line(char *s, int lim) {
    int c;
    char *s_start_ptr = s;
    // copy input loop
  while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    *s++ = c;
    // include newline
  if (c == '\n') {
    *s++ = c;

  }
  // apply '\0'
  *s = '\0';
  // return string length
  return s - s_start_ptr;
}
