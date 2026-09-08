#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAXWORD 100

// prototypes
struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);
struct tnode *talloc(void);
char *str_dup(char *);

int main() {
  struct tnode *root;
  char word[MAXWORD];

  root = NULL;
  while (getword(word, MAXWORD) != EOF)
    ;
  if (isalpha(word[0]))
    root = addtree(root, word);

  treeprint(root);
  return 0;
}
