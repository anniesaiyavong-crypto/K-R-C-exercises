# include "calc.h"
# include <ctype.h>
#include <stdio.h>


char line[MAXLINE];
int line_index;

int getop(char s[]) {
    int i, c, next;
    i = 0;
    // skip spaces
    while ((s[0] = c = line[line_index++]) == ' ' || c == '\t') {
        ;
    }

    s[1] = EOS;

    if (c == '\n' || c == '\0' || c == EOF) {
        return c;
    }

    // for negative number
    if (c == '-') {
        next = line[line_index++];
        if (isdigit(next) || next == '.') {
            s[0] = '-';
            c = next;
        } else {
            if (next != '\0') {
                line_index--;
            }
            return '-';
        }
    }


    if (isalpha(c)) {
        s[i] = c;
        while (isalpha(s[++i] = c = line[line_index++]))
            ;
        s[i] = EOS;

        if (c != '\0') {
            line_index--;
        }
        if (s[1] == EOS && isupper(s[0])) {
            return VAR;
        }

        if (s[1] == EOS) {
            return s[0];
        }
        return MATH;
    }


    if (!isdigit(c) && c != '.') {
        return c;
    }

    i = (s[0] == '-') ? 1 : 0;
    s[i] = c;


    while (isdigit(s[++i] = c = line[line_index++]))
        ;


    if (c == '.') {
        while (isdigit(s[++i] = c = line[line_index++]))
            ;
    }

    s[i] = EOS;

    if (c != '\n' && c != '\0' && c != EOF) {
        line_index--;
    }

    return NUMBER;
}

