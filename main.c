#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_N 10
#define MAXLEN 1000
#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n) {
  if (allocbuf + ALLOCSIZE - allocp >= n) {
    allocp += n;
    return allocp - n;
  } else {
    return NULL;
  }
}

int my_getline(char *s, int lim) {
  int c, i;
  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

int main(int argc, char *argv[]) {
  int n = DEFAULT_N;

  if (argc > 1 && argv[1][0] == '-') {
    n = atoi(&argv[1][1]);
    if (n <= 0)
      n = DEFAULT_N;
  }

  char **lineptr = (char **)malloc(n * sizeof(char *));
  if (lineptr == NULL) {
    fprintf(stderr, "tail: out of memory\n");
    return 1;
  }

  for (int i = 0; i < n; i++)
    lineptr[i] = NULL;

  char line[MAXLEN];
  int len;
  int count = 0;

  while ((len = my_getline(line, MAXLEN)) > 0) {
    char *p = alloc(len + 1);
    if (p == NULL) {
      fprintf(stderr, "tail: line too long or out of memory\n");
      free(lineptr);
      return 1;
    }

    line[len] = '\0';
    strcpy(p, line);

    int index = count % n;
    lineptr[index] = p;
    count++;
  }

  int start, total_to_print;
  if (count < n) {
    start = 0;
    total_to_print = count;
  } else {
    start = count % n;
    total_to_print = n;
  }

  for (int i = 0; i < total_to_print; i++) {
    int index = (start + i) % n;
    printf("%s", lineptr[index]);
  }

  free(lineptr);
  return 0;
}
