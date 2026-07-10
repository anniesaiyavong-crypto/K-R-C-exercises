#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "calc.h"


#define MAXOP 100

//main
int main() {
  int type;
  double op2;
  char s[MAXOP];

  while ((type = getop(s)) != EOF) {
    switch (type) {
      case NUMBER:
        push(atof(s));
        break;
      case '+':
        push(pop() + pop());
        break;
      case '*':
        push(pop() * pop());
        break;
      case '-':
        op2 = pop();
        push(pop() - op2);
        break;
      case '/':
        op2 = pop();
        if (op2 != 0.0) {
          push(pop() / op2);
        }
        else {
          printf("Cannot divide 0"NL);
        }
        break;
      case NLINE:
        printf("\t%.8g"NL, pop());
        break;
      default:
        printf("Unknow command"NL);
        break;
    }
  }
  return 0;
}






















