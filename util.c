#include "common.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// prototypes
int getch(void);
void ungetch(int c);
struct linklist *addline(struct linklist *list, int line);
void printlines(struct linklist *list);
//-----------------------------------------------------------------
// getword: get next word or character from input
int getword(char *word, int lim, int *lineno) {
  int c;
  char *w = word;

  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      (*lineno)++;
    } else if (!isspace(c)) {
      break;
    }
  }

  if (c == EOF)
    return EOF;

  *w++ = c;
  if (!isalpha(c)) {
    *w = '\0';
    return c;
  }

  for (; --lim > 0; w++) {
    c = getchar();
    if (!isalnum(c)) {
      ungetc(c, stdin);
      break;
    }
    *w = c;
  }
  *w = '\0';
  return word[0];
}
//-----------------------------------------------------------------
// treeprint: in-order print of tree p
void treeprint(struct tnode *p) {
  if (p != NULL) {
    treeprint(p->left);
    printf("%-15s ", p->word);
    printlines(p->lines);
    printf("\n");

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
struct tnode *addtree(struct tnode *p, char *w, int line) {
  int cond;
  // a new word has arrived
  if (p == NULL) {
    // make a new node
    p = (struct tnode *)malloc(sizeof(struct tnode));
    p->word = str_dup(w);
    p->lines = NULL;
    p->lines = addline(p->lines, line);
    p->left = p->right = NULL;

  } else if ((cond = strcmp(w, p->word)) == 0) // if found a duplicated word
    p->lines = addline(p->lines, line);
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
int isnoise(char *w) {
  // noise list
  static char *noise[] = {"a",  "an",  "and",  "are",  "as", "at",   "be",
                          "by", "for", "from", "has",  "he", "in",   "is",
                          "it", "its", "of",   "on",   "or", "that", "the",
                          "to", "was", "were", "with", NULL};

  char temp[MAXWORD];
  int i;

  // temporary lower case
  for (i = 0; w[i] != '\0'; i++)
    temp[i] = tolower(w[i]);
  temp[i] = '\0';

  for (i = 0; noise[i] != NULL; i++) {
    if (strcmp(temp, noise[i]) == 0)
      return 1;
  }
  return 0;
}
// printlines
void printlines(struct linklist *list) {
  while (list != NULL) {
    printf("%d ", list->lnum);
    list = list->next;
  }
}
