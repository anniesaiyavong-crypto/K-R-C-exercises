#include <stdio.h>

int htoi(char s[]);

int htoi(char s[]) {
  int i = 0;
  int result = 0;
  int digit_value;

  if (s[i] == '0') {
    i++;
    if ((s[i] == 'x') || (s[i] == 'X')) {
      i++;
    }
  }
  while (s[i] != '\0') {
    if ((s[i] >= '0') && (s[i] <= '9')) {
      digit_value = s[i] - '0';
    } else if ((s[i] >= 'a') && (s[i] <= 'f')) {
      digit_value = s[i] - 'a' + 10;
    } else if ((s[i] >= 'A') && (s[i] <= 'F')) {
      digit_value = s[i] - 'A' + 10;
    } else {
      break;
    }
    result = (result * 16) + digit_value;
    i++;
  }
  return result;
}

int main() {
  printf("0x1A3 ➔ %d\n", htoi("0x1A3"));
  printf("0XFF  ➔ %d\n", htoi("0XFF"));
  printf("f     ➔ %d\n", htoi("f"));

  return 0;
}
