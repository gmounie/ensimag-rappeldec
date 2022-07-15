#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

const unsigned int NB= 100;

void fibon(unsigned int *p, unsigned int size) {
    for(unsigned int i=0; i< size; i++)
	if (i < 1) // BUG: i < 2
	    p[i] = i;
	else
	    p[i] = p[i-1] + p[i-2]; // BUG: read p[-1]
}

int main() {
    assert(NB > 2);
    
    unsigned int *p = malloc( NB * sizeof(int));
    assert(p != NULL);

    fibon(p, NB);

    free(p);
    return 0;
}
