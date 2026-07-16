#include <stdio.h>
#include "calc.h"
#include <string.h>

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
void clear(void) {
    if (sp > 0) {
        memset(val, '\0', sizeof(val));
        sp = 0;
    }
}

