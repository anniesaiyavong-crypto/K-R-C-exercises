#include <stdio.h>
#define MAXVAL 100

double val[MAXVAL];
int sp = 0;

void push(double f) {
  if (sp < MAXVAL)
    val[sp++] = f;
  else
    printf("stack full");
}

double pop(void) {
  if (sp > 0)
    return val[--sp];
  else
    printf("empty stack");

  return 0.0;
}
