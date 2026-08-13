#include <string.h>
#include <stdio.h>
// prototype
void reverse(char string[]);
void r_helper(char string[], int left, int right);
// main-----
int main() {
    char s[] = "obmobim";
    int left = 0;
    int right = strlen(s);

    reverse(s);

    printf("%s\n", s);
}


void reverse(char s[]) {
    // call helper
    r_helper(s, 0, strlen(s) - 1);
}

void r_helper(char s[],int left , int right) {
    // base case
    if (left >= right) {
        return;
    }
    // swap
    int temp = s[left];
    s[left] = s[right];
    s[right] = temp;
    // narrow down
    r_helper(s, left + 1, right - 1);

}
