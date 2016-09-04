#include <stdio.h>

static unsigned long long X=123456ULL;

unsigned char crand48() {

	X = (0x5DEEDE66DULL * X + 0xBULL) % (1ULL <<48);
	unsigned char c = ((X & 0xFF00000000ULL) >> 32);
	return c;
}


int main(int argc, char **argv) {
	(void) argc;
	(void) argv;

	printf("%hhu\n", crand48());
	printf("%hhu\n", crand48());
	printf("%hhu\n", crand48());
	
	return 0;
} 
