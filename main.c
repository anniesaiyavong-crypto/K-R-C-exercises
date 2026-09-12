#include <stdarg.h>
#include <stdio.h>
// minprintf: minimal printf with variable argument list
void minprintf(char *fmt, ...) {
  va_list ap; // pointer to unnamed argument in turn
  char *p, *sval;
  unsigned uval;
  int ival;
  double dval;
  void *pval;

  va_start(ap, fmt); // make ap point to 1st argument
  for (p = fmt; *p; p++) {
    if (*p != '%') {
      putchar(*p);
      continue;
    }
    switch (*++p) {
    case 'd':
    case 'i':
      ival = va_arg(ap, int);
      printf("%d", ival);
      break;
    case 'u':
      uval = va_arg(ap, unsigned int);
      printf("%u", uval);
      break;
    case 'o':
      uval = va_arg(ap, unsigned int);
      printf("%o", uval);
      break;
    case 'x':
      uval = va_arg(ap, unsigned int);
      printf("%x", uval);
    case 'X':
      uval = va_arg(ap, unsigned int);
      printf("%X", uval);
    case 'c':
      ival = va_arg(ap, int);
      putchar(ival);
      break;
    case 'p':
      pval = va_arg(ap, void *);
      printf("%p", pval);
      break;
    case '%':
      putchar('%');
      break;
    case 'f':
      dval = va_arg(ap, double);
      printf("%f", dval);
      break;
    case 's':
      for (sval = va_arg(ap, char *); *sval; sval++)
        putchar(*sval);
      break;
    default:
      putchar(*p);
      break;
    }
  }
  va_end(ap); // clean up
}
