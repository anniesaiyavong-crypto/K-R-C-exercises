#include <stdio.h>
#include <string.h>

// personal preference shortcut
#define DE "%d"
#define ST "%s"
#define NL "\n"
#define NLINE '\n'
#define EOS '\0'

#define MAXLINE 1000
// function prototypes
int get_line(char line[], int max);
int strindex(char source[], char searchfor[]);


// main
int main() {
  char pattern[] = "a";
  char line[MAXLINE];
  int found = 0;

  while (get_line(line, MAXLINE) > 0)
    if (strindex(line, pattern) >= 0) {
      printf(ST, line);
      found++;
    }
  return found;
}
// get_line
int get_line(char s[], int limit) {
  int c, i;
  i = 0;

  while (--limit > 0 && (c = getchar()) != EOF && c != NLINE) {
    s[i++] = c;
  }
  if (c == NLINE) {
    s[i++] = c;
  }
  s[i] = EOS;
  return i;
}
// strindex
int strindex(char s[], char t[]) {
  int i, j, k;
  int rightmost = -1;

  for (i = 0; s[i] != EOS; i++) {
    for (j = i, k = 0; t[k] != EOS && s[j] == t[k]; j++, k++) {
    }
    if (k > 0 && t[k] == EOS) {
      rightmost = i;
    }
  }
      return rightmost;
}





