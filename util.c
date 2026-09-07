#include "common.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// binsearch: find word in tab[0]... tab[n-1]
int binsearch(char *word, struct key tab[], int n) {
  int cond;
  int low, high, mid;

  low = 0;
  high = n - 1;
  while (low <= high) {
    mid = (low + high) / 2;

    if ((cond = strcmp(word, tab[mid].word)) < 0)
      high = mid - 1;
    else if (cond > 0)
      low = mid + 1;
    else
      return mid;
  }
  return -1;
}
// getword: get next word or character from input
int getword(char *word, int lim) {
  int c, getch(void);
  void ungetch(int);
  char *w = word;
  // skip space
  while (isspace(c = getch()))
    ;
  if (c != EOF)
    *w++ = c;
  if (!isalpha(c)) {
    *w = '\0';
    return c;
  }
  for (; --lim > 0; w++)
    if (isalnum(*w = getch())) {
      ungetch(*w);
      break;
    }
  *w = '\0';

  return word[0];
}
