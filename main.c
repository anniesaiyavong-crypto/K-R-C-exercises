#include "calc.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MAXOP 100

int my_getline(char s[], int lim) {
  int c, i;
  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

int main(void) {
  int type;
  double op2;
  char s[MAXOP];
  int intop1, intop2;
  double variable[26] = {0};
  int var_i = 0;
  double last_value = 0.0;

  while (my_getline(line, MAXLINE) > 0) {
    line_index = 0;

    while ((type = getop(s)) != '\0' && type != EOF) {
      switch (type) {
        case NUMBER:
          push(atof(s));
          break;

          // math functions
        case MATH:
          if (strcmp(s, "sin") == 0) {
            push(sin(pop()));
          } else if (strcmp(s, "exp") == 0) {
            push(exp(pop()));
          } else if (strcmp(s, "pow") == 0) {
            op2 = pop();
            push(pow(pop(), op2));
          } else {
            printf("unknown function %s\n", s);
          }
          break;

          // assign variable
        case VAR:
          if (s[0] == 'V') {
            push(last_value);
          } else {
            var_i = s[0] - 'A';
            push(variable[var_i]);
          }
          break;

        case '=':
          pop();
          if (sp > 0) {
            double val_to_assign = pop();
            variable[var_i] = val_to_assign;
            push(val_to_assign);
          } else {
            printf("cant assign\n");
          }
          break;

          // math operators
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
            printf("Cannot divide 0\n");
          }
          break;

        case '%':
          intop1 = (int)pop();
          intop2 = (int)pop();
          if (intop1 != 0) {
            push(intop2 % intop1);
          } else {
            printf("error: zero divisor\n");
          }
          break;

          // control command
        case 'c':
        case 'C':
          clear();
          line_index = strlen(line);
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
          line_index = strlen(line);
          break;

          // Enter
        case '\n':
          if (sp > 0) {
            last_value = pop();
            push(last_value);
            printf("\t%.8g\n", last_value);
          } else {
            printf("empty stack\n");
          }
          break;

        default:
          printf("Unknown command %s\n", s);
          break;
      }
    }
  }
  return 0;
}
