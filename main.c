#include <string.h>
// reverse string s
void reverse(char *s) {
  // Check for null or empty string
  if (s == NULL || *s == '\0') {
    return;
  }
  // point to the last character before '\0'
  char *s_start = s;
  char *end = s + strlen(s) - 1;
  char temp;

  // Swap characters until the pointers meet in the middle
  while (s_start < end) {
    temp = *s_start;
    *s_start = *end;
    *end = temp;

    // Move the pointers toward each other
    s_start++;
    end--;
  }
}

// convert n to characters in s
void itoa(int n, char *s) {
  int sign;
  char *s_start = s;

  // save sign & make n positive
  if ((sign = n) < 0)
    n = -n;
  // generate digits
  do {
    *s++ = n % 10 + '0';
  } while ((n /= 10) > 0);
  // negative case
  if (sign < 0)
    *s++ = '-';
  // end with null
  *s = '\0';
  reverse(s_start);
}

