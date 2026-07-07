#include <stdio.h>
#include <string.h>
#include <ctype.h>
// personal preference shortcut
#define DE "%d"
#define ST "%s"
#define NL "\n"
#define NLINE '\n'
#define EOS '\0'

// function prototypes
double atofl(char s[]);

// main
int main() {
  char s[100] = "123";

  printf("%f" NL, atofl(s));
  return 0;
}
double atofl(char s[]) {
  double val, power;
  int i, sign;

  for (i = 0; isspace(s[i]); i++) {
    ;
  }
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-') {
    i++;
  }
  for (val = 0.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
  }
  if (s[i] == '.') {
    i++;
  }
  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] = '0');
    power *= 10;
  }
  return sign * val / power;
}




