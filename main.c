#include "parser.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];
int prevtoken = 0;

int main(void) {
  while (gettoken() != EOF) {
    // check type specifier or qualifier
    strcpy(datatype, token);
    out[0] = '\0';
    name[0] = '\0';

    dcl();

    if (tokentype != '\n') {
      printf("syntax error\n");
      while (tokentype != '\n' && tokentype != EOF) {
        gettoken(); // Flush remaining garbage
      }
    } else {
      printf("%s: %s %s\n", name, out, datatype);
    }
  }
  return 0;
}

// gettoken: handles QUALIFIER (const/volatile) and identifiers
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

    // identify qualifiers like const or volatile
    if (strcmp(token, "const") == 0 || strcmp(token, "volatile") == 0) {
      return tokentype = QUALIFIER;
    }
    return tokentype = NAME;
  } else {
    return tokentype = c;
  }
}
