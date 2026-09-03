#include <stdio.h>
// 1st version
int main(int argc, char *argv[]) {
  int i;

  for (i = 0; i < argc; i++)
    printf("%s%s", argv[i], (i < argc - 1) ? " " : "");
  printf("\n");
}
