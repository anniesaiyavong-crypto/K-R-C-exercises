#include "common.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>
// prototypes
int getword(char *word, int lim);
void pardef(void);
struct nlist *lookup(char *s);

int main(void) {
  char word[MAXWORD];
  struct nlist *np;

  while (getword(word, MAXWORD) != EOF) {
    if (strcmp(word, "#define") == 0) {
      pardef();
    } else if (isalpha(word[0])) {
      if ((np = lookup(word)) != NULL)
        printf("%s", np->defn);
      else
        printf("%s", word);
    } else {
      printf("%s", word);
    }
  }
  return 0;
}
