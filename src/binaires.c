#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

static constexpr unsigned long long X = 123456ULL;

unsigned char crand48() {
#if 0
	X = (0x5DEEDE66DULL * X + 0xBULL) & ((1ULL <<48) - 1);
	unsigned char c = ((X & 0xFF00000000ULL) >> 32);
        return c;

#else
  uint64_t a = 0x5DEECE66DULL;
  uint64_t c = 0xBULL;
  uint64_t m = ((1ULL << 48) - 1);
  X = (a * X + c) & m;
  return (unsigned char)(X >> 32);
#endif
}

int main(int argc, [[maybe_unused]] char *argv[static argc +1]) {
  printf("%hhu\n", crand48());
  printf("%hhu\n", crand48());
  printf("%hhu\n", crand48());

  return EXIT_SUCCESS;
}
