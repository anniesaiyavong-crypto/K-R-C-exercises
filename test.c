#include <stdio.h>

int binsearch(int x, int v[], int n) {
  int low, high, mid;
  low = 0;
  high = n - 1;

  while (low < high) {
    mid = (low + high) / 2;
    if (x <= v[mid]) {
      high = mid;
    }
    else
      low = mid + 1;
  }
  return (x == v[low]) ? low : -1;
}
int main() {

    int my_array[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int total_elements = sizeof(my_array) / sizeof(my_array[0]);
    int target = 14;


    int result_index = binsearch(target, my_array, total_elements);


    if (result_index != -1) {
        printf("%d (Index): %d\n", target, result_index);
    } else {
        printf("%d did not exist in \n", target);
    }

    return 0;
}


