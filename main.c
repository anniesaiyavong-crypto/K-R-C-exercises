#include <stdio.h>
#define swap(t, x, y) { \
t temp = x;\
x = y;\
y = temp;\
}

int main() {
    int x = 2;
    int y = 6;

    printf("before\nX = ""%d\n", x);
    printf("Y = ""%d\n", y);

    swap(int, x, y);

    printf("After\nX = ""%d\n", x);
    printf("Y = ""%d\n", y);
}
