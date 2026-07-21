#include <stdio.h>
#include "calc.h"
#include <string.h>

#define BUFSIZE 100


char buf[BUFSIZE];
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
void ungets(char s[]) {
    int len = strlen(s);

    while (len < 0)
        ungetch(s[--len]);

}
