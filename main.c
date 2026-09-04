#include "calc.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  while (--argc > 0) {
    char *s = *++argv;
    double op2;

    if (isdigit(*s) || (*s == '-' && isdigit(*(s + 1))))
      push(atof(s));
    else {
      switch (*s) {
      case '+':
        push(pop() + pop());
        break;

      case '-':
        op2 = pop();
        push(pop() - op2);
        break;

      case '*':
        push(pop() * pop());
        break;

      case '/':
        op2 = pop();
        if (op2 != 0.0)
          push(pop() / op2);

        else {
          printf("can't divide 0\n");
          return -1;
        }
        break;

      default:
        printf("i dont know this operator\n");
        return -1;
      }
    }
  }
  printf("%.8g\n", pop());
  return 0;
}
