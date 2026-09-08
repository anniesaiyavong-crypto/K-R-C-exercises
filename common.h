#pragma once
struct tnode {
  char *word;
  int match;
  struct tnode *left;
  struct tnode *right;
};
