#include <stdio.h>
#include <string.h>

// personal preference shortcut
#define DE "%d"
#define ST "%s"
#define NL "\n"
#define END '\0'
// function prototypes
void reverse(char text[]);
void itoa(int n, char s[], int w);



// main
int main() {
  int n = -123;
  char s[100] = "";
  int width = 10;
  itoa(n, s, width);

  printf(ST NL, s);

  return 0;
}


// int to string
void itoa(int n, char s[], int w) {
  int i, sign;
  sign = n;
  i = 0;
  int le;



  do {
    int rem = n % 10;
    if (rem < 0)
      s[i++] = '0' - rem;
    else
      s[i++] = '0' + rem;
    n /= 10;
  }

  while (n != 0);
  if (sign < 0) {
    s[i++] = '-';
  }

  while (i < w) {
    s[i++] = ' ';
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
