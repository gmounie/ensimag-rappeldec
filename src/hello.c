#include <stdio.h>
#include <stdlib.h>

int main(int argc, [[maybe_unused]] char *argv[static argc + 1]) {
  printf(u8"∀ p ∈ world, hello p\n");
  return EXIT_SUCCESS;
}
