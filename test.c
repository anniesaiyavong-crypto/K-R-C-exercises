#include <stdio.h>
#include <string.h>

// personal preference shortcut
#define DE "%d"
#define ST "%s"
#define NL "\n"
#define END '\0'
// function prototypes
void reverse(char text[]);
void itoa(int n, char s[]);



// main
int main() {
  int n = -2147483648;
  char s[100] = "";
  itoa(n, s);

  printf(ST NL, s);

  return 0;
}


// int to string
void itoa(int n, char s[]) {
  int i, sign;
  sign = n;
  i = 0;



  do {
    int x = n % 10;
    if (x < 0)
      s[i++] = '0' - x;
    else
      s[i++] = '0' + x;
  }

  while ((n /= 10) != 0);
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












