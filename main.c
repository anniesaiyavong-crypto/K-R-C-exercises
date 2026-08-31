#include <stdio.h>
void str_cpy(char *s, char *t, int n) {
    // copy until n become 0 or no char left in t
  while (n > 0 && *t != '\0') {
    *s++ = *t++;
    n--;
  }
  // end with \0
  if (n > 0)
    *s = '\0';
}
void str_cat(char *s, char *t, int n) {
    // move to \0
  while (*s)
    s++;
    // copy to its end
  while (n > 0 && *t != '\0') {
    *s++ = *t++;
    n--;
  }

  *s = '\0';
}

int str_cmp(char *s, char *t, int n) {
    // compare s and t until n is 0
    for (; n > 0 && *s == *t; s++, t++, n--)
        if (*s == '\0')
            return 0;

    return (n == 0) ? 0 : (*s - *t);
}
int main() {
  char s[] = {"II000"};
  char t[] = {"IIIII"};
  int n = 2;

  printf("%d\n", str_cmp(s, t, n));
}
