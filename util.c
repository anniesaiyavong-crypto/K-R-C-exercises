#include "common.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>
int getch(void);
void ungetch(int c);

// binsearch: find word in tab[0]... tab[n-1]
struct key *binsearch(char *word, struct key *tab, int n) {
  int cond;
  struct key *low = &tab[0];
  struct key *high = &tab[n];
  struct key *mid;

  while (low < high) {
    mid = low + (high - low) / 2;

    if ((cond = strcmp(word, mid->word)) < 0)
      high = mid;
    else if (cond > 0)
      low = mid + 1;
    else
      return mid;
  }
  return NULL;
}
// getword: get next word or character from input
int getword(char *word, int lim) {
  int c, d;
  char *w = word;

  // skip space
  while (isspace(c = getch()))
    ;

  if (c != EOF)
    *w++ = c;

  if (isalpha(c) || c == '_') {
    for (; --lim > 0; w++) {
      if (!isalnum(*w = getch()) && *w != '_') {
        ungetch(*w);
        break;
      }
    }
    *w = '\0';
    return word[0];
  }

  if (c == '"' || c == '\'') {
    int quote = c;
    for (; --lim > 0; w++) {
      if ((*w = getch()) == '\\') {
        if (--lim > 0)
          *++w = getch();
      } else if (*w == quote || *w == EOF) {
        if (*w != EOF)
          w++;
        break;
      }
    }
    *w = '\0';
    return word[0];
  }
  if (c == '/') {
    if ((d = getch()) == '*') {
      while ((c = getch()) != EOF) {
        if (c == '*') {
          if ((c = getch()) == '/')
            break;
          else
            ungetch(c);
        }
      }
      return getword(word, lim);
    } else if (d == '/') {
      while ((c = getch()) != '\n' && c != EOF)
        ;
      return getword(word, lim);
    } else {
      ungetch(d);
    }
  }
  if (c == '#') {
    while ((c = getch()) != '\n' && c != EOF)
      ;
    return getword(word, lim);
  }
  *w = '\0';
  return c;
}
