#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
// personal preference shortcut
#define DE "%d"
#define ST "%s"
#define NL "\n"
#define NLINE '\n'
#define EOS '\0'

#define MAXOP 100
#define NUMBER '0'

// function prototypes
int getop(char []);
void push(double);
double pop(void);

// main
// reverse Polsih Calculator
int main() {
  int type;
  double op2;
  char s[MAXOP];

  while ((type = getop(s)) != EOF) {
    switch (type) {
      case NUMBER:
        push(atof(s));
        break;
      case '+':
        push(pop() + pop());
        break;
      case '*':
        push(pop() * pop());
        break;
      case '-':
        op2 = pop();
        push(pop() - op2);
        break;
      case '/':
        op2 = pop();
        if (op2 != 0.0) {
          push(pop() / op2);
        }
        else {
          printf("Cannot divide 0"NL);
        }
        break;
      case NLINE:
        printf("\t%.8g"NL, pop());
        break;
      default:
        printf("Unknow command"NL);
        break;
    }
  }
  return 0;
}


#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f) {
  if (sp < MAXVAL) {
    val[sp++] = f;
  }
  else {
    printf("full, cant push %g"NL, f);
  }
}

double pop(void) {
  if (sp > 0) {
    return val[sp--];
  }
  else {
    printf("Error, empty stack"NL);
    return 0.0;
  }
}

int getch(void);
void ungetch(int);

int getop(char s[]) {
  int i, c;

  while ((s[0] = c = getch()) == ' ' || c == '\t') {
    ;
  }
    s[1] = EOS;
    if (!isdigit(c) && c != '.') {
      return c;
    }
    i++;
    if (isdigit(c)) {
      while (isdigit(s[i++] = c = getch())) {
        ;
       }
      }
    if (c == '.') {
      while (isdigit(s[i++] = c = getch())) {
        ;
      }
    }
    s[i] = EOS;
    if (c != EOF) {
      ungetch(c);
    }
    return NUMBER;
}

#define BUFSIZE 100




char buf[BUFSIZ];
int bufp;

int getcha(void) {
  return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c) {
  if (bufp >= BUFSIZE) {
    printf("ungetch: too many characters"NL);
  }
  else {
    buf[bufp++] = c;
  }
}
















