#include "parser.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>
void dcl(void);
void dirdcl(void);

int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];
int prevtoken = 0;

int main() {
  while (gettoken() != EOF) {
    strcpy(datatype, token);
    out[0] = '\0';
    dcl();
    if (tokentype != '\n') {
      printf("syntax error\n");
      // flush garbage input
      while (tokentype != '\n' && tokentype != EOF) {
        gettoken();
      }
    } else {
      printf("%s: %s %s\n", name, out, datatype);
    }
  }
  return 0;
}
int gettoken(void) {
  int c, getch(void);
  void ungetch(int);
  char *p = token;

  if (prevtoken) {
    prevtoken = 0;
    return tokentype;
  }

  while ((c = getch()) == ' ' || c == '\t')
    ;

  if (c == '(') {
    if ((c = getch()) == ')') {
      strcpy(token, "()");
      return tokentype = PARENS;
    } else {
      ungetch(c);
      return tokentype = '(';
    }
  } else if (c == '[') {
    for (*p++ = c; (*p = getch()) != ']'; p++) {
      if (*p == '\n' || *p == EOF) {
        ungetch(*p);
        break;
      }
    }
    if (*p == ']') {
      p++;
    }
    *p = '\0';
    return tokentype = BRACKETS;
  } else if (isalpha(c)) {
    for (*p++ = c; isalnum(c = getch());) {
      *p++ = c;
    }
    *p = '\0';
    ungetch(c);
    return tokentype = NAME;
  } else {
    return tokentype = c;
  }
}
