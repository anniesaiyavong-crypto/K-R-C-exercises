#include <stdio.h>

int scan(char text[],char blacklist[]);



int scan(char t[],char b[]) {
  int i, j, s;

  for(i = 0; t[i] != '\0'; i++) {
    for(j = 0; b[j] != '\0'; j++) {
      if(t[i] == b[j]) {
        return i;
      }
     }
    }
  return -1;
}

int main() {
  char text[] = "e sam see";
  char blacklist[] = "a";

  printf("result = %d\n", scan(text, blacklist));
}

