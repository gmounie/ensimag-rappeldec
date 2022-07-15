#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

const unsigned int SIZE= 100;

void fibon(unsigned int *p, unsigned int size) {
    for(unsigned int i=0; i< size; i++)
	if (i < 2)
	    p[i] = i;
	else
	    p[i] = p[i-1] + p[i-2];
    free(p);
}

int main() {
    assert(SIZE > 2);
    
    unsigned int p[SIZE];
    assert(p != NULL);

    fibon(p, SIZE);

    return 0;
}
