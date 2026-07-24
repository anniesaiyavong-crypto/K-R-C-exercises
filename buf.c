#include <stdio.h>
#include "calc.h"
#include <string.h>

#define BUFSIZE 100


static int buf = 0;
static int buf_got_char = 0;
int getch(void) {
    int c;

    if (buf_got_char) {
     c = buf;
     buf_got_char = 0;
    }
    else {
        c = getchar();
    }
    return c;
}

void ungetch(int c) {
    if (buf_got_char) {
        printf("ungetch: too many cahr");
    }
    else {
        buf = c;
        buf_got_char = 1;
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
    buf_got_char = 0;
    if (sp > 0) {
        sp = 0;
}
}
