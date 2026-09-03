#pragma once
#define MAXSTORE 500000
void writelines(char *lineptr[], int nlines);
int readlines(char *lineptr[], int maxlinesม, char *store);
void qsort(char *lineptr[], int left, int right);
int get_line(char *, int);
