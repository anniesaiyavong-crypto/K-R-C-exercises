#include "calc.h"
#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100

// main
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
      } else {
        printf("Cannot divide 0" NL);
      }
      break;

    case '%':
      intop1 = pop();
      intop2 = pop();
      if (intop1 != 0) {
        push(intop2 % intop1);
      } else {
        printf("error: zero devisor" NL);
      }
      break;
      // control command
      // clear
    case 'c':
    case 'C':
      clear();
      bufp = 0;
      int garbage;
      while ((garbage = getch()) != '\n' && garbage != EOF) {
        ;
      }
      break;
      // duplicate
    case 'd':
    case 'D':
      duplicate();
      break;
      // swap
    case 's':
    case 'S':
      swap();
      break;
      // check the whole stack
    case 'a':
    case 'A':
      check_stack();
      while ((garbage = getch()) != '\n' && garbage != EOF) {
       ;
      }
      break;

    case NLINE:
      if (sp > 0) {
        printf("\t%.8g" NL, val[sp - 1]);
      } else {
        printf("empty stack" NL);
      }
      break;

    default:
      printf("Unknow command" NL);
      break;
    }
  }
  return 0;
}
