#include <stdio.h>
#include <stdlib.h>

#define TAB_DEFAULT 8

int is_tab_stop(int col, int argc, char *argv[]) {
  if (argc == 1)
    return (col % TAB_DEFAULT == 0);

  for (int i = 1; i < argc; i++) {
    if (col == atoi(argv[i]))
      return 1;
  }
  return 0;
}

int main(int argc, char *argv[]) {
  int c;
  int col = 0;
  int space_count = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      space_count++;
      col++;
      if (is_tab_stop(col, argc, argv)) {
        putchar('\t');
        space_count = 0;
      }
    } else {
      while (space_count > 0) {
        putchar(' ');
        space_count--;
      }

      putchar(c);
      if (c == '\n')
        col = 0;
      else if (c == '\t') {
        while (!is_tab_stop(++col, argc, argv))
          ;
      } else {
        col++;
      }
    }
  }
  return 0;
}
