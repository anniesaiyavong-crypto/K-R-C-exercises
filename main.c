#include <stdlib.h>
#include <stdio.h>
int compare_int(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int array[] = {1, 8, 9, 7, 3};

    qsort(array, 5, sizeof(int), compare_int);

    for (int i = 0; i <= 4; i++)
        printf("%d ",array[i]);

    printf("\n");
}
