#include <ctype.h>
#include <stdio.h>
// token
#define NUMBER '0'

int getch(void);
void ungetch(int);

// get operator and operand
int getop(char *s) {
  int c;

  // skip spaces
  while ((*s = c = getch()) == ' ' || c == '\t')
    ;
  *(s + 1) = '\0';

  // return operator if found
  if (!isdigit(c) && c != '.')
    return c;

  // collect integer
  if (isdigit(c))
    while (isdigit(*++s = c = getch()))
      ;

  // 4. collect fraction
  if (c == '.')
    while (isdigit(*++s = c = getch()))
      ;

  *s = '\0';

  if (c != EOF)
    ungetch(c);

  return NUMBER;
}
