#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int c;

  char *progname = argv[0];
  char *p = strrchr(progname, '/');
  if (p != NULL)
    progname = p + 1;

  if (strcmp(progname, "lower") == 0) {
    while ((c = getchar()) != EOF)
      putchar(tolower(c));
  } else if (strcmp(progname, "upper") == 0) {
    while ((c = getchar()) != EOF)
      putchar(toupper(c));
  } else {
    fprintf(stderr, "name unmatch\n");
    return 1;
  }
  return 0;
}
