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
// get operators
int getop(char []);
//buffer
int getch(void);
void ungetch(int);
//stack
void push(double);
double pop(void);
void clear(void);
void duplicate(void);
void swap(void);
void check_stack(void);
#endif
