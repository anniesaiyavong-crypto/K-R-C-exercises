// return the first index of t that occurred in s
int strindex(char *s, char *t) {
  char *s_ptr, *p1, *p2;
  // return if t is empty
  if (*t == '\0')
    return 0;

  for (s_ptr = s; *s_ptr != '\0'; s_ptr++) {
    p1 = s_ptr;
    p2 = t;
    // checking loop
    while (*p1 != '\0' && *p2 != '\0' && *p1 == *p2) {
      p1++;
      p2++;
    }
    // return index
    if (*p2 == '\0')
      return s_ptr - s;
  }
  return -1;
}
