void strcat(char *s, char *t) {
    // find \0
    while (*s)
        s++;
    // copy loop
    while (*s++ = *t++)
        ;
}
