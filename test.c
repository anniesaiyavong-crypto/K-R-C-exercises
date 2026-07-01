#include <stdio.h>
// squeeze function
void sq(char s1[], char s2[]) {

  // i for s1, j for s2, k for the leftover
  int i, j, k;

  k = 0;
  //read s1
  for (i = 0; s1[i] != '\0'; i++) {
    //read s2
    for (j = 0; s2[j] != '\0'; j++) {
      // break after they matched
     if (s1[i] == s2[j]) {
        break;
     }
    }
    // if j found \0 its job is done
    if (s2[j] == '\0') {
      // push the leftover to s1 and count with k
      s1[k++] = s1[i];
    }
  }
  // k is done after \0
  s1[k] = '\0';
}

// main function
int main() {

  // data
  char text[] = "babcock";
  char blacklist[] = "bc";

  // call the function
  sq(text, blacklist);

  // print
  printf("result: %s\n", text);
}

// result is aok

