#include <ctype.h>
#include <stdio.h>
// prototypes
int getch(void);
void ungetch(int);
int getfloat(double *);

int main() {
    double n;
    getfloat(&n);

    printf("%f\n", n);

}
int getfloat(double *pn) {
    int c, d, sign;
    double power;

    // skip spaces
    while (isspace(c = getch()))
        ;

    // ckeck for non-digit
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;

    // handle sign
    if (c == '+' || c == '-') {
        d = c;
        c = getch();
        if (!isdigit(c) && c != '.') {
            if (c != EOF)
                ungetch(c);
            ungetch(d);
            return 0;
        }
    }

    // process left side of the '.'
    for (*pn = 0.0; isdigit(c); c = getch()) {
        *pn = 10.0 * *pn + (c - '0');
    }
    if (c == '.') {
        c = getch();
    }

    // process right side of '.' and power
    for (power = 1.0; isdigit(c); c = getch()) {
        *pn = 10.0 * *pn + (c - '0');
        power *= 10.0;
    }

    // 6. add sign and divide by power
    *pn = (sign * *pn) / power;

    if (c != EOF) {
        ungetch(c);
    }

    return c;
}


char buf[10];
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
