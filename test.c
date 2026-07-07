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
  char s[100] = "123e10";

  printf("%f" NL, atofl(s));
  return 0;
}
// ASCII to Float
double atofl(char s[]) {
  double val, power;
  int i, sign, expo_sign, expo_val;


  // clear the space
  for (i = 0; isspace(s[i]); i++) {
    ;
  }
  // check sign
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
  val = sign * val / power;

  if (s[i] == 'e' || s[i] == 'E') {
    i++;

    expo_sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-') {
      i++;
    }
    for (expo_val = 0; isdigit(s[i]); i++) {
      expo_val = 10 * expo_val + (s[i] - '0');
    }

    for (int k = 0; k < expo_val; k++) {
      if (expo_sign == -1) {
        val /= 10.0;
      }
      else {
        val *= 10;
      }
    }
  }
  return val;
}




