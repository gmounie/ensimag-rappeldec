#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

const unsigned int NB= 10000;

void fibon(unsigned int *p, unsigned int size) {
    for(unsigned int i=0; i<= size; i++) // BUG: i < size
	if (i < 2)
	    p[i] = i;
	else
	    p[i] = p[i-1] + p[i-2]; // BUG: write p[NB]
}

int main() {
    assert(NB > 2);
    
    unsigned int *p = malloc( NB * sizeof(int));
    assert(p != NULL);

    fibon(p, NB);

    free(p);
    return 0;
}
