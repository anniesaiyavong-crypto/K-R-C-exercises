# include "calc.h"
# include <ctype.h>
#include <stdio.h>


int getop(char s[]) {
    int i, c, next;
    i = 0;
    // save the first char into s[0] and c whie skipping spaces
    while ((s[0] = c = getch()) == ' ' || c == '\t') {
        ;
    }

    s[1] = EOS;

    if (!isdigit(c) && c != '.' && !isalpha(c)) {
        return c;
    }
    i = 0;

    if (isalpha(c)) {
        while (isalpha(s[++i] = c = getch()))
            ;
        s[i] = '\0';

        if (c != EOF) {
            ungetch(c);
        }

        if (s[1] == '\0') {
            return s[0];
        }

        return MATH;
    }
    //For negative number
    if (c == '-') {
        next = getch();
        if (isdigit(next) || next == '.') {
            s[1] = c = next;
            i = 2;
        }
        else {
            if (next != EOS) {
                ungetch(next);
            }
            return '-';
        }
    }

    else if (!isdigit(c) && c != '.') {
        return c;
    }
    else {
        i = 1;
    }

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
