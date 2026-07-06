#include <stdio.h>
#include <string.h>


#define DE "%d"
#define ST "%s"
#define NL "\n"
#define END '\0'
// function prototypes
void reverse(char text[]);
void itoa(int n, char s[]);



// main
int main() {
  int n = 189002;
  char s[100] = "";
  itoa(n, s);

  printf(ST NL, s);

  return 0;
}


// int to string
void itoa(int n, char s[]) {
  int i, sigh;
  if ((sigh = n) < 0) {
    n = -n;
  }
  i = 0;

  do {
    s[i++] = n % 10 + '0';
  }
  while ((n /= 10) > 0);
  if (sigh < 0) {
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












