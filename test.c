#include <stdio.h>

#define DE "%d"
#define ST "%s"
#define NL "\n"
#define END '\0'

void expand(char s1[], char s2[]) {
  int i = 0;
  int j = 0;
  char c;

  while (s1[i] != END) {
    if (i > 0 && s1[i] == '-' && s1[i + 1] != END) {
      char start = s1[i - 1];
      char end = s1[i + 1];

      for (c = start + 1; c <= end; c++) {
        s2[j++] = c;
      }
      i += 2;
    }
    else {
      s2[j++] = s1[i];
      i++;
    }
  }
  s2[j] = END;
}

int main() {
  char s1[] = "0-9";
  char s2[100] = "";
  expand(s1, s2);

  printf(ST"\n", s2);

  return 0;
}












