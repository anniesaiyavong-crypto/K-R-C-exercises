
#include <stdlib.h>
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
