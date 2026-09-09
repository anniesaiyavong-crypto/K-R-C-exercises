#pragma once

#define MAXWORD 100
// tree node
struct tnode {
  char *word;
  int count;
  struct tnode *left;
  struct tnode *right;
};
// linked list: line number
struct linklist {
  int lnum;
  struct linklist *next;
};
