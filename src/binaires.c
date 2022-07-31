#include <stdio.h>
#include <stdlib.h>

static unsigned long long X = 123456ULL;

unsigned char crand48(void) {
  /* Insérez votre code ici. */
  (void)X; // to remove

  return 0;
}

int main(void) {
  printf("%hhu\n", crand48());
  printf("%hhu\n", crand48());
  printf("%hhu\n", crand48());

  return EXIT_SUCCESS;
}
