# include "calc.h"
# include <ctype.h>
#include <stdio.h>


int getop(char s[]) {
    int i, c;
    i = 0;
    while ((s[0] = c = getch()) == ' ' || c == '\t') {
        ;
    }
    s[1] = EOS;
    if (!isdigit(c) && c != '.') {
        return c;
    }
    i++;
    if (isdigit(c)) {
        while (isdigit(s[i++] = c = getch())) {
            ;
        }
    }
    if (c == '.') {
        while (isdigit(s[i++] = c = getch())) {
            ;
        }
    }
    s[i] = EOS;
    if (c != EOF) {
        ungetch(c);
    }
    return NUMBER;
}
