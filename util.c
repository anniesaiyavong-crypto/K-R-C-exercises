#include "common.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int getch(void);
void ungetch(int c);
//-----------------------------------------------------------------
// getword: get next word or character from input
int getword(char *word, int lim) {
  int c;
  char *w = word;
  // skip space
  while ((c = getchar()) != EOF) {
    if (isspace(c))
      continue;

    if (c == '/') {
      int next = getchar();
      if (next == '*') {
        int prev = 0;
        while ((c = getchar()) != EOF) {
          if (prev == '*' && c == '/')
            break;
          prev = c;
        }
        continue;
      } else if (next == '/') {
        while ((c = getchar()) != EOF && c != '\n')
          ;
        continue;
      } else {
        ungetc(next, stdin);
      }
    }

    if (c == '"' || c == '\'') {
      int quote = c;
      while ((c = getchar()) != EOF) {
        if (c == '\\')
          getchar();
        else if (c == quote)
          break;
      }
      continue;
    }
    break;
  }

  if (c == EOF)
    return EOF;

  *w++ = c;
  if (!isalpha(c) && c != '_') {
    *w = '\0';
    return c;
  }
  for (; --lim > 0; w++) {
    if (!isalnum(*w = getchar()) && *w != '_') {
      ungetc(*w, stdin);
      break;
    }
  }
  *w = '\0';
  return word[0];
}
//-----------------------------------------------------------------
// treeprint: in-order print of tree p
void treeprint(struct tnode *p) {
  if (p != NULL) {
    treeprint(p->left);
    if (p->match) {
      printf("%s\n", p->word);
    }
    treeprint(p->right);
  }
}
// talloc: make a tnode
struct tnode *talloc(void) {
  return (struct tnode *)malloc(sizeof(struct tnode));
}
// strdup: make a duplicate of s
char *str_dup(char *s) {
  char *p;

  p = (char *)malloc(strlen(s) + 1); // + 1 for '\0'
  if (p != NULL)
    strcpy(p, s);
  return p;
}

// addtree: add a node with w, at or below p
struct tnode *addtree_num(struct tnode *p, char *w, int num, int *found) {
  int cond;
  // a new word has arrived
  if (p == NULL) {
    // make a new node
    p = (struct tnode *)malloc(sizeof(struct tnode));
    p->word = str_dup(w);
    p->match = *found;
    p->left = p->right = NULL;
  } else if ((cond = strcmp(w, p->word)) == 0) {
    *found = 1;
    p->match = 1;
    if (strncmp(w, p->word, num) == 0) {
      *found = 1;
      p->match = 1;
    }
    if (cond < 0)
      p->left = addtree_num(p->left, w, num, found);
    else
      p->right = addtree_num(p->right, w, num, found);
  }
  return p;
}
//-----------------------------------------------------------------
