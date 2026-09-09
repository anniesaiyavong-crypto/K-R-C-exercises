#include "common.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define DEF_MATCH 6
// prototypes
int isnoise(char *w);
struct tnode *addtree_num(struct tnode *, char *, int, int *);
void treeprint(struct tnode *);
int getword(char *word, int lim, int *lineno);
struct tnode *addtree(struct tnode *p, char *w, int line);

int main(void) {
  struct tnode *root = NULL;
  char word[MAXWORD];
  int lineno = 1;

  while (getword(word, MAXWORD, &lineno) != EOF) {
    if (isalpha(word[0]) && !isnoise(word)) {
      root = addtree(root, word, lineno);
    }
  }

  printf("%-15s Line Numbers\n\n", "Word");
  treeprint(root);

  return 0;
}
