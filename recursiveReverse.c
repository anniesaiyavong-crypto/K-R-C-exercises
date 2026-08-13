#include <string.h>
#include <stdio.h>
// prototype
void reverse(char string[], int left, int right);
// main-----
int main() {
    char s[] = "obmobim";
    int left = 0;
    int right = strlen(s);

    reverse(s, left, right);

    printf("%s\n", s);
}





void reverse(char s[], int left, int right) {
    // base case
    if (left <= right)
        return;
    // swaping
    int temp = s[left];
    s[left] = s[right];
    s[right] = temp;
    // narrow down
    reverse(s, left + 1, right - 1);
}
