#include <stdio.h>
#include "calc.h"
#include <string.h>

#define BUFSIZE 100


static int buf = EOF;

int getch(void) {
    int c;

    if (buf != EOF) {
        c = buf;
        buf = EOF;
    }
    else {
        c = getchar();
    }
    return c;
}

void ungetch(int c) {
    if (buf != EOF) {
        printf("ungetch: too many cahr");
    }
    else {
        buf = c;
    }
}
void ungets(char s[]) {
    int len = strlen(s);

    while (len < 0)
        ungetch(s[--len]);

}
// clear stack function
void clear(void) {
    buf = EOF;
    if (sp > 0) {
        sp = 0;
}
}
