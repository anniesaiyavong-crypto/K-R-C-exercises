#include "common.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// prototypes
int getch(void);
void ungetch(int);
// pointer table
static struct nlist *hashtab[HASHSIZE];

// hash: form hash value for string s
unsigned hash(char *s) {
  unsigned hashval;

  for (hashval = 0; *s != '\0'; s++)
    hashval = *s + 31 * hashval;

  return hashval % HASHSIZE;
}

// lookup: look for s in hashtab
struct nlist *lookup(char *s) {
  struct nlist *np;
  // search
  for (np = hashtab[hash(s)]; np != NULL; np = np->next)
    if (strcmp(s, np->name) == 0)
      return np; // found
  return NULL;   // not found
}
// install: put name and definition in hashtab
struct nlist *install(char *name, char *defn) {
  struct nlist *np;
  unsigned hashval;

  if ((np = lookup(name)) == NULL) { // not found
    np = (struct nlist *)malloc(sizeof(*np));
    if (np == NULL || (np->name = strdup(name)) == NULL)
      return NULL;
    hashval = hash(name);
    np->next = hashtab[hashval];
    hashtab[hashval] = np;
  } else                    // already there
    free((void *)np->defn); // free previous defn
  if ((np->defn = strdup(defn)) == NULL)
    return NULL;

  return np;
}
// undef: remove name and definition from the table
int undef(char *s) {
  struct nlist *np, *prev;
  unsigned hashval;

  if (s == NULL)
    return 1;

  hashval = hash(s);
  prev = NULL;
  // search loop
  for (np = hashtab[hashval]; np != NULL; np = np->next) {
    if (strcmp(s, np->name) == 0) { // found
      if (prev == NULL)
        hashtab[hashval] = np->next;
    } else {
      prev->next = np->next;
    }

    free((void *)np->name);
    free((void *)np->defn);
    free((void *)np);

    return 0;
  }
  return -1;
}
// skip comment
void skip_comment(void) {
  int c;
  while ((c = getch()) != EOF) {
    putchar(c);
    if (c == '*') {
      if ((c = getch()) == '/') {
        putchar(c);
        break;
      }
      ungetch(c);
    }
  }
}
// getword
int getword(char *word, int lim) {
  int c;
  char *w = word;

  while (isspace(c = getch()))
    putchar(c);

  if (c != EOF)
    *w++ = c;

  if (c == '"') {
    while ((c = getch()) != EOF && c != '"') {
      *w++ = c;
      if (c == '\\')
        *w++ = getch();
    }
    if (c == '"')
      *w++ = c;

    *w = '\0';

    return word[0];
  } else if (c == '/') {
    if ((c = getch()) == '*') {
      putchar('*');
      skip_comment();
      return getword(word, lim);
    } else
      ungetch(c);
  }
  if (isalpha(c) && c != '#') {
    *w = '\0';

    return c;
  }
  for (; --lim > 0; w++) {
    if (!isalnum(*w = getch()) && *w != '_') {
      ungetch(*w);
      break;
    }
  }
  *w = '\0';
  return word[0];
}
// pardef
void pardef(void) {
    char name[MAXWORD], defn[MAXWORD];
    int c;

    // read macro
    if (getword(name, MAXWORD) && isalpha(name[0])) {
        while (isspace(c = getch()) && c != '\n')
            ;
        if (c != '\n') {
            ungetch(c);
            int i = 0;

            while ((c = getch()) != '\n' && c != EOF && i < MAXWORD -1)
                defn[i++] = c;
            defn[i] = '\0';

            install(name, defn);
            putchar('\n');
        }
    }
}
