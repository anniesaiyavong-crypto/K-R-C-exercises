#include "parser.h"
#include <stdio.h>
#include <string.h>

// dcl: parse a declarator
void dcl(void) {
  int ns;

  // count pointers and check for const pointers
  for (ns = 0; gettoken() == '*';) {
    ns++;
    if (gettoken() == QUALIFIER) {
      strcat(out, " const");
    } else {
      prevtoken = 1;
    }
  }

  dirdcl();

  while (ns-- > 0) {
    strcat(out, " pointer to");
  }
}

// paramdcl: parse function arguments
void paramdcl(void) {
  char param_buf[1000] = "";
  char temp[MAXTOKEN];

  strcat(out, " function passing (");

  while (1) {
    gettoken();
    if (tokentype == ')') {
      break;
    }

    temp[0] = '\0';
    while (tokentype == QUALIFIER || tokentype == NAME || tokentype == '*') {
      if (tokentype == '*') {
        strcat(temp, "pointer to ");
      } else {
        strcat(temp, token);
        strcat(temp, " ");
      }
      gettoken();
    }

    strcat(param_buf, temp);

    if (tokentype == NAME) {
      strcat(param_buf, token);
      gettoken();
    }

    if (tokentype == ',') {
      strcat(param_buf, ", ");
    } else if (tokentype == ')') {
      break;
    }
  }

  strcat(out, param_buf);
  strcat(out, ") returning");

  gettoken();
}

// dirdcl: parse direct declarators
void dirdcl(void) {
  int type;

  if (tokentype == '(') {
    dcl();
    if (tokentype != ')') {
      printf("error: missing )\n");
      prevtoken = 1;
    }
  } else if (tokentype == NAME || tokentype == QUALIFIER) {
    strcpy(name, token);
  } else {
    printf("error: expected name or (dcl)\n");
    prevtoken = 1;
  }

  while ((type = gettoken()) == PARENS || type == BRACKETS || type == '(') {
    if (type == PARENS) {
      strcat(out, " function returning");
    } else if (type == '(') {
      paramdcl();
    } else {
      strcat(out, " array");
      strcat(out, token);
      strcat(out, " of");
    }
  }
}
