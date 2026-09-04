#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// max line to be sorted
#define MAXLINES 5000
// pointer to text line
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void q_sort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(const char *, const char *);

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
void q_sort(void *v[], int left, int right, int (*comp)(void *, void *)) {
  int i, last;

  void swap(void *v[], int, int);

  if (left >= right)
    return;

  swap(v, left, (left + right) / 2);
  last = left;

  for (i = left + 1; i <= right; i++)
    if ((*comp)(v[i], v[left]) < 0)
      swap(v, ++last, i);

  swap(v, left, last);
  q_sort(v, left, last - 1, comp);
  q_sort(v, last + 1, right, comp);
}

int numcmp(const char *s1, const char *s2) {
  double v1, v2;

  v1 = atof(s1);
  v2 = atof(s2);

  if (v1 < v2)
    return -1;
  else if (v1 > v2)
    return 1;
  else
    return 0;
}
void swap(void *v[], int i, int j) {
  void *temp;
  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}
