#include <stdio.h>
#define swap(t, x, y) do {\
t temp = x;\
x = y;\
y = temp;\
} while(0)

int main() {
    int x = 2;
    int y = 6;

    printf("before\nX = ""%d\n", x);
    printf("Y = ""%d\n", y);

    if (x < y)
        swap(int, x, y);

    printf("After\nX = ""%d\n", x);
    printf("Y = ""%d\n", y);
}
