#include <stdio.h>
#include <string.h>

// personal preference shortcut
#define DE "%d"
#define ST "%s"
#define NL "\n"
#define END '\0'
// function prototypes
void reverse(char text[]);
void base_conversion(int n, char s[], int b);



// main
int main() {
  int n = 255;
  int b = 16;
  char s[100] = "";

  base_conversion(n, s, b);
  printf(ST NL, s);


  return 0;
}


// base_conversion function
void base_conversion(int n, char s[], int b) {
  int i = 0;
  int sign = n;
  char digits[] = "0123456789abcdefghijklmnopqrstuvwxyz";

  do {
    int rem = n % b;
    if (rem < 0)
      rem = -rem;
    s[i++] = digits[rem];
    n /= b;
  }

  while (n != 0);
  if (sign < 0) {
    s[i++] = '-';
  }
  s[i] = END;
  reverse(s);
}
// reverse
void reverse(char s[]) {
  int i, j;
  char c;

  for (i = 0, j = strlen(s) - 1;  i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }

}












