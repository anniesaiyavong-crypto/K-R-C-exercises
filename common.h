#pragma once
#define NKEYS (sizeof keytab / sizeof(keytab[0]))
struct key {
  char *word;
  int count;
};
