#include <stdio.h>
#include "calc.h"

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f) {
    if (sp < MAXVAL) {
        val[sp++] = f;
    }
    else {
        printf("full, cant push %g"NL, f);
    }
}

double pop(void) {
    if (sp > 0) {
        return val[--sp];
    }
    else {
        return 0.0;
    }
}
// duplicate the top stack function
void duplicate(void) {
    if (sp > 0) {
        double dupe = val[sp-1];
        push(dupe);
    }
}
// swap the last 2 position function
void swap(void) {
    if (sp > 1) {
        double t = val[sp - 1];
        val[sp - 1] = val[sp - 2];
        val[sp - 2] = t;
    }
    else {
        printf("not enough number to swap"NL);
    }
}
// print all number in stack (a)
void check_stack(void) {
    printf("stack:");

    if (sp == 0) {
        printf("empty"NL);
        return;
    }
    for (int i = 0; i < sp; i++) {
        printf("%g ", val[i]);
    }
    printf(NL);
}



