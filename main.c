#include <stdio.h>
#include <string.h>
// if t occurs at the end of s, return 1, 0 otherwise
int strend(char *s, char *t) {
    char *t_start_ptr = t;
    // check the length
    if (strlen(s) < strlen(t))
        return 0;
  // move both to '\0'
    while (*s)
        s++;
    while (*t)
        t++;
    // move back
    while (*s == *t) {
        s--;
        t--;
    }
    // check
    if (++t == t_start_ptr)
        return 1;

    return 0;
}

int main() {
    char s[] = {"banana"};
    char t[] = {"na"};

    printf("%d\n", strend(s, t));

}
