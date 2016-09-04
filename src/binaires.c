#include <stdio.h>

static unsigned long long X=123456ULL;

unsigned char crand48() {
	(void) X;
	return 0;
}


int main(int argc, char **argv) {
	(void) argc;
	(void) argv;

	printf("%hhu\n", crand48());
	printf("%hhu\n", crand48());
	printf("%hhu\n", crand48());
	
	return 0;
} 
