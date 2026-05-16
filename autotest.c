#include <stdio.h>
#include <tgmath.h>

struct option {
  bool ok;
  double res;
  const char *msg;
};

const char *const msg = "TOO LARGE";

struct option f(double x) {
  struct option o = {
      .ok = true, .res = sqrt(fabs(x)) + 5 * pow(x, 3), .msg = msg};
  if (fabs(o.res) > 400.0)
    o.ok = false;
  return o;
}

int main() {
  double val[11];

  for (int i = 0; i < 11; i++)
    scanf("%lg", &val[i]);

  for (int i = 10; i >= 0; i--) {
    const struct option o = f(val[i]);
    if (o.ok)
      printf("f(%lg)= %g\n", val[i], o.res);
    else
      printf("%lg : %s\n", val[i], o.msg);
  }
  return 0;
}
