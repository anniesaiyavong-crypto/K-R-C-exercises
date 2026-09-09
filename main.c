#include "common.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEF_MATCH 6
// prototypes
struct tnode *addtree(struct tnode *, char *);
int getword(char *, int);
int count_nodes(struct tnode *);
void tree_to_array(struct tnode *, struct tnode **, int *);
int cmp_node(const void *, const void *);

int main(void) {
  struct tnode *root = NULL;
  char word[MAXWORD];

  while (getword(word, MAXWORD) != EOF)
    if (isalpha(word[0]))
      root = addtree(root, word);

  int n = count_nodes(root);
  if (n == 0) {
    return 0;
  }

  struct tnode **list = (struct tnode **)malloc(n * sizeof(struct tnode *));
  int index = 0;

  tree_to_array(root, list, &index);

  qsort(list, n, sizeof(struct tnode *), cmp_node);

  for (int i = 0; i < n; i++)
    printf("$%4d %s\n", list[i]->count, list[i]->word);

  free(list);
  return 0;
}
