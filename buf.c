#include <stdio.h>
#include "calc.h"


#define BUFSIZE 100


char buf[BUFSIZ];
int bufp;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c) {
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters"NL);
    }
    else {
        buf[bufp++] = c;
    }
}
