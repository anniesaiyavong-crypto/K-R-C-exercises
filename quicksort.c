#include <stdio.h>
// prototypes------
void qsort(int array[], int left, int right);
static void swap(int v[], int i, int j);

// main-----
int main() {
    int num[] = {1, 3, 5, 3, 7, 8, 9, 0, 2, 3, 12, 4};
    int size = sizeof(num) / sizeof(num[0]);

    qsort(num, 0, size - 1);

    for (int i = 0; i < size; i++) {
        printf("%d", num[i]);
    }
    printf("\n");

}

// int v[] is an array, left & right is the index range of the array
void qsort(int v[], int left, int right) {
  int i, last;

  // recursion base case
  if (left >= right) {
    return;
  }

  swap(v, left, (left + right) / 2);
  last = left;
  for (i = left + 1; i <= right; i++) {
    if (v[i] < v[left]) {
      swap(v, ++last, i);
    }
  }
  swap(v, left, last);
  qsort(v, left, last - 1);
  qsort(v, last + 1, right);
}

// swap function
void swap(int v[], int i, int j) {
  int temp;
  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}


