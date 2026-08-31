// copy t to s, array version
void string_cpy(char *s, char *t) {
  int i = 0;
  while ((s[i] = t[i]) != '\0')
    i++;
}
// copy, pointer version
void string_cpy_p(char *s, char *t) {
  while ((*s = *t) != '\0') {
    s++;
    t++;
  }
}
