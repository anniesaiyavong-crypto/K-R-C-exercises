#include <stdio.h>

void escape(char string[], char text[]);

int main() {
  char cat[] = "hello \n \t";
  char esc[100] = "";

  escape(esc, cat);

  printf("%s\n", esc);
    return 0;
}

void escape(char s[], char t[]) {
  int i, j;
  j = 0;
  char c;

  for (i = 0; t[i] != '\0'; i++) {
   c = t[i];

   switch (c) {
     case '\n' :
       s[j++] = '\\';
       s[j++] = 'n';
        break;
     case '\t' :
       s[j++] = '\\';
       s[j++] = 't';
       break;
     default :
       s[j++] = c;
       break;
    }
  }
  s[j] = '\0';
}










