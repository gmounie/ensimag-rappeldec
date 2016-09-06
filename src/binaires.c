#include <stdlib.h>
#include <stdio.h>

static unsigned long long X = 123456ULL;

unsigned char crand48(void) {
    /* Insérez votre code ici. */
    return 0;
}

int main(void)
{
    printf("%hhu\n", crand48());
    printf("%hhu\n", crand48());
    printf("%hhu\n", crand48());

    return EXIT_SUCCESS;
}
