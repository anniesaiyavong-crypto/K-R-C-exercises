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
  int intop1, intop2;

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

      case '%':
        intop1 = pop();
        intop2 = pop();
        if (intop1 != 0) {
        push(intop2 % intop1);
        }
        else {
          printf("error: zero devisor"NL);
        }
        break;

      case NLINE:
        if (sp > 0) {
          printf("\t%.8g"NL, val[sp-1]);
        }
        else {
          printf("Error"NL);
        }
        break;

      default:
        printf("Unknow command"NL);
        break;
    }
  }
  return 0;
}






















