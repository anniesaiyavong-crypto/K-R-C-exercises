#pragma once

#define HASHSIZE 101

// table entry
struct nlist {
  struct nlist *next; // next entry in chian
  char *name;         // defined name
  char *defn;         // replacement text
};
