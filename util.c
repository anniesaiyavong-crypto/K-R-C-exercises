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
//-----------------------------------------------------------------
// treeprint: in-order print of tree p
void treeprint(struct tnode *p) {
  if (p != NULL) {
    treeprint(p->left);
    printf("%4d %s\n", p->count, p->word);
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

  return p;
}

// addtree: add a node with w, at or below p
struct tnode *addtree(struct tnode *p, char *w) {
  int cond;
  // a new word has arrived
  if (p == NULL) {
    // make a new node
    p = talloc();
    p->word = str_dup(w);
    p->count = 1;
    p->left = p->right = NULL;
  } else if ((cond = strcmp(w, p->word)) == 0)
    p->count++;      // repeated word
  else if (cond < 0) // less than into left subtree
    p->left = addtree(p->left, w);
  else // greater than into righ subtree
    p->right = addtree(p->right, w);

  return p;
}
//-----------------------------------------------------------------
