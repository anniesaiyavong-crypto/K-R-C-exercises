#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXWORD 100
#define DEF_MATCH 6
// prototypes

struct tnode *addtree_num(struct tnode *, char *, int, int *);
void treeprint(struct tnode *);
int getword(char *, int);

int main(int argc, char *argv[]) {
  int num = DEF_MATCH;
  // read argument
  if (argc > 1 && argv[1][0] == '-')
    num = atoi(&argv[1][1]);
  else if (argc > 1)
    num = atoi(argv[1]);

  struct tnode *root = NULL;
  char word[MAXWORD];
  int found = 0;
  //
  while (getword(word, MAXWORD) != EOF)
    if (isalpha(word[0]) && strlen(word) >= num)
      root = addtree_num(root, word, num, &found);

  treeprint(root);
  return 0;
}
