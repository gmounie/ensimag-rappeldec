#include "abmc.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, [[maybe_unused]] char *argv[static argc + 1]) {
  /* version 1 et 2 */
  float a = 0.0001f, b = 0.0002f, c = 0.0003f;
  printf("%e\n", fabmc(a, b, c));

  double da = 0.00001, db = 0.00002, dc = 0.00003;
  printf("%e\n", dabmc(da, db, dc));

  long double lda = 0.00001l, ldb = 0.00002l, ldc = 0.00003l;
  printf("%Le\n", ldabmc(lda, ldb, ldc));

  _Decimal32 dfa = 0.0001df, dfb = 0.0002df, dfc = 0.0003df;
  printf("%He\n", dfabmc(dfa, dfb, dfc));

  _Decimal64 dda = 0.0001dd, ddb = 0.0002dd, ddc = 0.0003dd;
  printf("%De\n", ddabmc(dda, ddb, ddc));

  _Decimal128 dla = 0.0001dl, dlb = 0.0002dl, dlc = 0.0003dl;
  printf("%DDe\n", dlabmc(dla, dlb, dlc));
  return EXIT_SUCCESS;
}
