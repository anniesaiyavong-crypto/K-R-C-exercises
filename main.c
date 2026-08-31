// string copy, shorter pointer version
void string_cpy_p(char *s, char *t) {
  while ((*s++ = *t++) != '\0')
      ;
}
