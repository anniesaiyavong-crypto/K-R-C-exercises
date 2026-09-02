#include <ctype.h>
#include <stdio.h>
#include <string.h>
//--------------------------------------
// token
#define NUMBER '0'
int getch(void);
void ungetch(int);

// get operator and operand
int getop(char *s) {
  int c;

  // skip spaces
  while ((*s = c = getch()) == ' ' || c == '\t')
    ;
  *(s + 1) = '\0';

  // return operator if found
  if (!isdigit(c) && c != '.')
    return c;

  // collect integer
  if (isdigit(c))
    while (isdigit(*++s = c = getch()))
      ;

  // 4. collect fraction
  if (c == '.')
    while (isdigit(*++s = c = getch()))
      ;

  *s = '\0';

  if (c != EOF)
    ungetch(c);

  return NUMBER;
}
//--------------------------------------
// return the first index of t that occurred in s
int strindex(char *s, char *t) {
    char *s_ptr, *p1, *p2;
    // return if t is empty
    if (*t == '\0')
        return 0;

    for (s_ptr = s; *s_ptr != '\0'; s_ptr++) {
        p1 = s_ptr;
        p2 = t;
        // checking loop
        while (*p1 != '\0' && *p2 != '\0' && *p1 == *p2) {
            p1++;
            p2++;
        }
        // return index
        if (*p2 == '\0')
            return s_ptr - s;
    }
    return -1;
}
//--------------------------------------
// string to double
double atof(char *s) {
    double val = 0.0, power = 1.0;
    int sign;

    // skip spaces
    while (isspace(*s))
        s++;

    // save sign
    sign = (*s == '-') ? -1 : 1;
    if (*s == '+' || *s == '-')
        s++;

    // convert
    while (isdigit(*s))
        val = 10.0 * val + (*s++ - '0');

    // skip decimal point
    if (*s == '.')
        s++;

    // convert fraction
    while (isdigit(*s)) {
        val = 10.0 * val + (*s++ - '0');
        power *= 10.0;
    }

    return sign * val / power;
}
//--------------------------------------
// reverse string s
void reverse(char *s) {
    // Check for null or empty string
    if (s == NULL || *s == '\0') {
        return;
    }
    // point to the last character before '\0'
    char *s_start = s;
    char *end = s + strlen(s) - 1;
    char temp;

    // Swap characters until the pointers meet in the middle
    while (s_start < end) {
        temp = *s_start;
        *s_start = *end;
        *end = temp;

        // Move the pointers toward each other
        s_start++;
        end--;
    }
}
//--------------------------------------
// convert n to characters in s
void itoa(int n, char *s) {
    int sign;
    char *s_start = s;

    // save sign & make n positive
    if ((sign = n) < 0)
        n = -n;
    // generate digits
    do {
        *s++ = n % 10 + '0';
    } while ((n /= 10) > 0);
    // negative case
    if (sign < 0)
        *s++ = '-';
    // end with null
    *s = '\0';
    reverse(s_start);
}
//--------------------------------------
// string to int
int atoi(char *s) {
    int n = 0;
    int sign;
    // skip white space
    while (isspace(*s))
        s++;
    // save sing
    sign = (*s == '-') ? -1 : 1;

    if (*s == '+' || *s == '-')
        s++;
    // generate integer value
    while (isdigit(*s)) {
        n = 10 * n + (*s++ - '0');
    }
    return sign * n;
}
//--------------------------------------
int get_line(char *s, int lim) {
    int c;
    char *s_start_ptr = s;
    // copy input loop
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;
    // include newline
    if (c == '\n') {
        *s++ = c;

    }
    // apply '\0'
    *s = '\0';
    // return string length
    return s - s_start_ptr;
}
//--------------------------------------
