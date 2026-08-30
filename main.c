#define ALLOCSIZE 10000

// spaces for mem allocattion
static char allocbuf[ALLOCSIZE];
// pin
static char *alloc_ptr = allocbuf;

char *alloc(int n) {
    // check for the available spaces
    if (allocbuf + ALLOCSIZE - alloc_ptr >= n) {
        // move the pin by n and return its prev address
        alloc_ptr += n;
        return alloc_ptr - n;
    } else
        // full!
        return 0;
}

void afree(char *p) {
    // check if p is within allocbuf range
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        alloc_ptr = p;
}
