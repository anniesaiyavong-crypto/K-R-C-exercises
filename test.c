#include <stdio.h>


char* lower(char c[]) {
  int i;
  for (i = 0; c[i] != '\0'; i++) {
    ( c[i] >= 'A' && c[i] <= 'Z') ? c[i] += 32 : c[i];
  }
  return c;
}


int main() {
  char c[] = "CAT";

  printf("%s\n",lower(c));
  return 0;
}


