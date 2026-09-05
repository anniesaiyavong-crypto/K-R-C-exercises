#include "sort.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int directory;
int fold;

// Static helper function prototype
static void swap(void *v[], int i, int j);

// q_sort: quicksort array v[left]...v[right] using comparator function
void q_sort(void *v[], int left, int right, int (*comp)(void *, void *)) {
  int i, last;

  if (left >= right) {
    return;
  }

  swap(v, left, (left + right) / 2);
  last = left;

  for (i = left + 1; i <= right; i++) {
    if (comp(v[i], v[left]) < 0) {
      swap(v, ++last, i);
    }
  }

  swap(v, left, last);
  q_sort(v, left, last - 1, comp);
  q_sort(v, last + 1, right, comp);
}

// numcmp: compare s1 and s2 numerically via atof, fallback to strcmp
int numcmp(const char *s1, const char *s2) {
  double v1 = atof(s1);
  double v2 = atof(s2);

  if (v1 < v2) {
    return -1;
  } else if (v1 > v2) {
    return 1;
  } else {
    return strcmp(s1, s2);
  }
}

// charcmp: compare s1 and s2 with optional directory order and case folding
int charcmp(const char *s1, const char *s2) {
  char a, b;

  do {
    // Skip non-alphanumeric and non-space characters if directory order is set
    if (directory) {
      while (*s1 != '\0' && !isalnum((unsigned char)*s1) && *s1 != ' ') {
        s1++;
      }
      while (*s2 != '\0' && !isalnum((unsigned char)*s2) && *s2 != ' ') {
        s2++;
      }
    }

    a = *s1;
    b = *s2;

    // Fold case if fold flag is enabled
    if (fold) {
      a = tolower((unsigned char)a);
      b = tolower((unsigned char)b);
    }

    if (a == b) {
      if (a == '\0') {
        return 0;
      }
      s1++;
      s2++;
    }
  } while (a == b);

  return a - b;
}

// swap: interchange two pointer array elements
static void swap(void *v[], int i, int j) {
  void *temp;
  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}
