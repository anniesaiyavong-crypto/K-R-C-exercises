#include "parser.h"
#include <stdio.h>
#include <string.h>

extern int prevtoken;

void dcl(void);
void dirdcl(void);

// dcl: parse a declarator
void dcl(void) {
  int ns;

  // count *'s
  for (ns = 0; gettoken() == '*';) {
    ns++;
  }

  dirdcl();

  while (ns-- > 0) {
    strcat(out, " pointer to");
  }
}

// dirdcl: parse a direct declarator with proper error recovery
void dirdcl(void) {
  int type;

  if (tokentype == '(') {
    dcl();
    if (tokentype != ')') {
      printf("error: missing )\n");
      prevtoken = 1;
      return;
    }
  } else if (tokentype == NAME) {
    strcpy(name, token);
  } else {
    printf("error: expected name or (dcl)\n");
    prevtoken = 1;
    return;
  }
  while ((type = gettoken()) == PARENS || type == BRACKETS) {
    if (type == PARENS) {
      strcat(out, " function returning");
    } else {
      strcat(out, " array");
      strcat(out, token);
      strcat(out, " of");
    }
  }
}
