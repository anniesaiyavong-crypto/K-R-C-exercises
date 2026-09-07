#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS, QUALIFIER };

extern int tokentype;
extern char token[];
extern char name[];
extern char datatype[];
extern char out[];
extern int prevtoken;

int gettoken(void);
void dcl(void);
void dirdcl(void);
void paramdcl(void);
