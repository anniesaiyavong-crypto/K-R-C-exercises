#include <stdio.h>
#include <stdlib.h>

#define TAB_DEFAULT 8

int is_tab_stop(int col, int argc, char *argv[]) {
  if (argc == 1) {

    return (col % TAB_DEFAULT == 0);
  }

  for (int i = 1; i < argc; i++) {
    int tab_pos = atoi(argv[i]);
    if (col == tab_pos)
      return 1;
  }
  return 0;
}

int main(int argc, char *argv[]) {
  int c;
  int col = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      do {
        putchar(' ');
        col++;
      } while (!is_tab_stop(col, argc, argv));
    } else if (c == '\n') {
      putchar(c);
      col = 0;
    } else {
      putchar(c);
      col++;
    }
  }
  return 0;
}
