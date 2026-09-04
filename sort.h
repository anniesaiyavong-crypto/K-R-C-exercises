#pragma once
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
int get_line(char *s, int lim);
char *alloc(int);
void q_sort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(const char *, const char *);

extern int reverse;
