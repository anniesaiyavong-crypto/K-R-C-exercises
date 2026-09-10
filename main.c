#include "common.h"
#include <stdlib.h>
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
