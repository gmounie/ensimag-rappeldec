#include <stdlib.h>
#include <stdio.h>
#include "abmc.h"

int main(int argc, char **argv) {
	(void) argc;
	(void) argv;

	/* version 1 et 2 */	
	float a=0.1f, b=0.2f, c=0.3f;
	printf("%e\n", fabmc(a, b, c));

	double da=0.1, db=0.2, dc=0.3;
	printf("%e\n", dabmc(da, db, dc));

	long double lda=0.111111L, ldb=0.222222L, ldc=0.333333L;
	printf("%Le\n", ldabmc(lda, ldb, ldc));

	return EXIT_SUCCESS;
} 

