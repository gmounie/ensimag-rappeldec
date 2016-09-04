#include <stdio.h>

static long long X=123456;

unsigned char crand48() {
	(void) X;
	return 0;
}


int main(int argc, char **argv) {
	(void) argc;
	(void) argv;

	printf("%hhd\n",crand48());
	printf("%hhd\n",crand48());
	printf("%hhd\n",crand48());
	
	return 0;
} 
