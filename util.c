#include "common.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// prototypes
struct linklist *addline(struct linklist *list, int line);
void printlines(struct linklist *list);
void tree_to_array(struct tnode *p, struct tnode **list, int *i);
//-----------------------------------------------------------------
// getword: get next word or character from input
int getword(char *word, int lim, int *lineno) {
  int c;
  char *w = word;
  // skip space
  while (isspace(c = getchar()))
    ;

  if (c == EOF)
    return EOF;

  *w++ = c;

  if (!isalpha(c) && c != '_') {
    *w = '\0';
    return c;
  }

  for (; --lim > 0; w++) {
    c = getchar();
    if (!isalnum(c) && c != '_') {
      ungetc(c, stdin);
      break;
    }
    *w = c;
  }
  *w = '\0';
  return word[0];
}

//-----------------------------------------------------------------
// talloc: make a tnode
struct tnode *talloc(void) {
  return (struct tnode *)malloc(sizeof(struct tnode));
}

// addtree: add a node with w, at or below p
struct tnode *addtree(struct tnode *p, char *w, int line) {
  int cond;
  // a new word has arrived
  if (p == NULL) {
    // make a new node
    p = (struct tnode *)malloc(sizeof(struct tnode));
    p->word = strdup(w);
    p->count = 1;
    p->left = p->right = NULL;

  } else if ((cond = strcmp(w, p->word)) == 0) // if found a duplicated word
    p->count++;
  else if (cond < 0)
    p->left = addtree(p->left, w, line);
  else
    p->right = addtree(p->right, w, line);

  return p;
}
//-----------------------------------------------------------------
struct linklist *addline(struct linklist *list, int line) {
  if (list == NULL) {
    list = (struct linklist *)malloc(sizeof(struct linklist));
    list->lnum = line;
    list->next = NULL;
  } else if (list->lnum != line)

    list->next = addline(list->next, line);

  return list;
}

void tree_to_array(struct tnode *p, struct tnode **list, int *i) {
  if (p != NULL) {
    tree_to_array(p->left, list, i);
    list[(*i)++] = p;
    tree_to_array(p->right, list, i);
  }
}

int count_nodes(struct tnode *p) {
  if (p == NULL)
    return 0;
  return 1 + count_nodes(p->left) + count_nodes(p->right);
}

int cmp_node(const void *a, const void *b) {
  struct tnode *nodeA = *(struct tnode **)a;
  struct tnode *nodeB = *(struct tnode **)b;

  return nodeB->count - nodeA->count;
}
