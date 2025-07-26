#include "abmc.h"

#define XABMC(FNAME, TYPE) \
TYPE FNAME(TYPE a, TYPE b, TYPE c) { \
		return ((a+b)-c); \
}
  

float fabmc(float a, float b, float c) {
		return ((a+b)-c);
}
	
double dabmc(double a, double b, double c) {
		return ((a+b)-c);
};

long double ldabmc(long double a, long double b, long double c) {
		return ((a+b)-c);
};

XABMC(dfabmc, _Decimal32);
XABMC(ddabmc, _Decimal64);
XABMC(dlabmc, _Decimal128);
