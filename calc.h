#ifndef CALC_H
#define CALC_H

// personal preference short
#define DE "%d"
#define ST "%s"
#define NL "\n"
#define NLINE '\n'
#define EOS '\0'
//
#define NUMBER '0'

// variable
extern int sp;
extern double val[];
extern int bufp;

// functions
int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
void clear(void);


#endif
