#ifndef CALC_H
#define CALC_H

// personal preference short
#define DE "%d"
#define ST "%s"
#define NL "\n"
#define NLINE '\n'
#define EOS '\0'
// token
#define NUMBER '0'
#define MATH 'n'
#define VAR 'v'
// variable
extern int sp;
extern double val[];
// functions
// get operators
int getop(char []);
//buffer
int getch(void);
void ungetch(int);
void ungets(char[]);
void clear(void);
//stack
void push(double);
double pop(void);
void duplicate(void);
void swap(void);
void check_stack(void);
#endif
