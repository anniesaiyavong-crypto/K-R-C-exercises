#include <stdio.h>
#include "calc.h"

#define BUFSIZE 100


static int buf = 0;
static int buf_got_char = 0;

// clear stack function
void clear(void) {
    buf = EOF;
    buf_got_char = 0;
    if (sp > 0) {
        sp = 0;
}
}
