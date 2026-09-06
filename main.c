#include "parser.h"
#include <stdio.h>
#include <string.h>

int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];

int gettoken(void);

int main(void) {
  int type;
  char temp[MAXTOKEN];

  while (gettoken() != EOF) {
    strcpy(out, token);

    while ((type = gettoken()) != '\n' && type != EOF) {
      if (type == PARENS || type == BRACKETS) {
        strcat(out, token);
      } else if (type == '*') {

        sprintf(temp, "(*%s)", out);
        strcpy(out, temp);
      } else if (type == NAME) {
        // prepend variable name
        sprintf(temp, "%s %s", token, out);
        strcpy(out, temp);
      } else {
        printf("invalid input at %s\n", token);
      }
    }
    printf("%s\n", out);
  }
  return 0;
}
#include "parser.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// gettoken: return next token from input
int gettoken(void) {
  int c, getch(void);
  void ungetch(int);
  char *p = token;

  // Skip whitespaces except newline
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
      if (*p == '\n' || *p == EOF)
        break;
    }
    if (*p == ']')
      p++;
    *p = '\0';
    return tokentype = BRACKETS;
  } else if (isalpha(c)) {
    for (*p++ = c; isalnum(c = getch());)
      *p++ = c;
    *p = '\0';
    ungetch(c);
    return tokentype = NAME;
  } else {
    return tokentype = c;
  }
}
