#include <ctype.h>
#include <stdio.h>
// prototypes
int getch(void);
void ungetch(int);
int getint(int *);

int main() {
    int n;
    getint(&n);

    printf("%d\n", n);

}

int getint(int *pn) {
    int c, temp, sign;

    // skip space
    while (isspace(c = getch()))
        ;

    // for non-number
    if (!isdigit(c) && c != EOF && c != '-' && c != '+') {
        ungetch(c);
        return 0;
    }
    // save sign
    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-') {
        // save current c and read the next input
        temp = c;
        c = getch();
    }
    // digit and EOF check
    if (!isdigit(c)) {
        if (c != EOF)
            //push sign back
            ungetch(c);
        //psuh non-digit input back
        ungetch(temp);
        return 0;
    }





    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');

    // apply the sign
    *pn *= sign;

    if (c != EOF)
        ungetch(c);

    return c;
}


char buf[100];
int bufp;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c) {
    if (bufp >= 100) {
        printf("ungetch: too many characters\n");
    }
    else {
        buf[bufp++] = c;
    }
}
