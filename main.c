#include <ctype.h>
int atoi(char *s) {
  int n = 0;
  int sign;
// skip white space
  while (isspace(*s))
      s++;

  sign = (*s == '-') ? -1 : 1;

  if (*s == '+' || *s == '-')
    s++;

  while (isdigit(*s)) {
    n = 10 * n + (*s++ - '0');
  }
  return sign * n;
}
