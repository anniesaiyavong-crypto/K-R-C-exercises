#include <ctype.h>
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
