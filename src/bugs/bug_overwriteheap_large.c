#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

const unsigned int SIZE= 10000; // size may be a misleading name

void fibon(unsigned int *p, unsigned int size) {
    for(unsigned int i=0; i<= size; i++)
	if (i < 2)
	    p[i] = i;
	else
	    p[i] = p[i-1] + p[i-2];
}

int main() {
    assert(SIZE > 2);
    
    unsigned int *p = malloc( SIZE ); // BUG:  NB * sizeof(int));
    assert(p != NULL);

    fibon(p, SIZE);

    free(p);
    return 0;
}
