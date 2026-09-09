#include "common.h"
#include <stdio.h>
#include <string.h>
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

  for (np = hashtab[hash(s)]; np != NULL; np = np->next)
    if (strcmp(s, np->name) == 0)
      return np; // found
  return NULL;   // not found
}
