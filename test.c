#include <stdio.h>

#define DE "%d"
#define ST "%s"
#define NT "\n"

void shellsort(int v[], int n) {
  int gap, i, j, temp;

  for (gap = n/2; gap > 0; gap /= 2)
    for (i = gap; i < n; i++)
      for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap) {
        temp = v[j];
        v[j] = v[j + gap];
        v[j + gap] = temp;
      }
}

int main() {
  int num[] = {1, 5, 7, 8, 2, 9, 6, 10, 3, 4};
  int n = (sizeof(num) / sizeof(num[0]));
  int i;

  shellsort(num, n);
  printf("[");
  for (i = 0; i < n; i++) {
   printf(DE, num[i]);
   if (i < n - 1)
     printf(", ");

  }
  printf("]"NT);
 return 0;
}
