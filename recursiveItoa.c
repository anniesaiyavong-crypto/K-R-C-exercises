#include <stdio.h>
#include <stdlib.h>
// prototype
void itoa(int number, char string[]);

// main-----
int main() {
    int n = -10007;
    char s[100] = "";
    int w = 10;

    itoa(n, s);
    printf("%s\n", s);
}

void itoa(int num, char s[]) {
    static int i;

    // move to the leftmost
    if (num / 10)
        itoa(num / 10, s);
    // reset index
    else {
        i = 0;

    // negative sign case
    if (num < 0)
        s[i++] = '-';
    }
    // push each number into s array, move index, then null it
    s[i++] = abs(num % 10) + '0';
    s[i] = '\0';


}
