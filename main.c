#include "sort.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5000
#define MAXFIELD 10
#define MAXLEN 1000

char *lineptr[MAXLINES];

int field_numeric[MAXFIELD];
int field_reverse[MAXFIELD];
int field_fold[MAXFIELD];
int field_directory[MAXFIELD];

int num_options = 0;

void get_field(const char *line, int field_idx, char *buf);
int field_cmp(const void *p1, const void *p2);

int main(int argc, char *argv[]) {
  int nlines;

  while (--argc > 0 && (*++argv)[0] == '-') {
    char c;
    if (num_options < MAXFIELD) {
      while ((c = *++argv[0])) {
        switch (c) {
        case 'n':
          field_numeric[num_options] = 1;
          break;
        case 'r':
          field_reverse[num_options] = 1;
          break;
        case 'f':
          field_fold[num_options] = 1;
          break;
        case 'd':
          field_directory[num_options] = 1;
          break;
        case 'h':
          printf("-n numeric sort, -r reverse, -f fold case, -d directory "
                 "order\n");
          return 0;
        default:
          printf("unknown argument: -%c\n", c);
          return 1;
        }
      }
      num_options++;
    }
  }

  if (num_options == 0) {
    num_options = 1;
  }
  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    /* ส่ง field_cmp เข้าไปเป็น Comparator หลัก */
    q_sort((void **)lineptr, 0, nlines - 1, (int (*)(void *, void *))field_cmp);
    writelines(lineptr, nlines);
    return 0;
  } else {
    printf("input too big to sort\n");
    return -1;
  }
}

void get_field(const char *line, int field_idx, char *buf) {
  int i = 0, j = 0, curr = 0;

  while (line[i] != '\0' && curr < field_idx) {
    if (line[i] == ' ' || line[i] == '\t') {
      curr++;
      while (line[i] == ' ' || line[i] == '\t')
        i++;
    } else {
      i++;
    }
  }

  while (line[i] != '\0' && line[i] != ' ' && line[i] != '\t') {
    buf[j++] = line[i++];
  }
  buf[j] = '\0';
}

int field_cmp(const void *p1, const void *p2) {
  const char *s1 = *(const char **)p1;
  const char *s2 = *(const char **)p2;
  char buf1[MAXLEN], buf2[MAXLEN];
  int rc = 0;

  for (int f = 0; f < num_options; f++) {
    get_field(s1, f, buf1);
    get_field(s2, f, buf2);

    if (field_numeric[f]) {
      double v1 = atof(buf1);
      double v2 = atof(buf2);
      if (v1 < v2)
        rc = -1;
      else if (v1 > v2)
        rc = 1;
      else
        rc = 0;
    } else {
      char *p_buf1 = buf1, *p_buf2 = buf2;
      char a, b;
      do {
        if (field_directory[f]) {
          while (*p_buf1 && !isalnum((unsigned char)*p_buf1) && *p_buf1 != ' ')
            p_buf1++;
          while (*p_buf2 && !isalnum((unsigned char)*p_buf2) && *p_buf2 != ' ')
            p_buf2++;
        }
        a = field_fold[f] ? tolower((unsigned char)*p_buf1) : *p_buf1;
        b = field_fold[f] ? tolower((unsigned char)*p_buf2) : *p_buf2;

        if (a == b) {
          if (a == '\0')
            break;
          p_buf1++;
          p_buf2++;
        }
      } while (a == b);
      rc = a - b;
    }
    if (field_reverse[f])
      rc = -rc;
    if (rc != 0)
      return rc;
  }
  return strcmp(s1, s2);
}
